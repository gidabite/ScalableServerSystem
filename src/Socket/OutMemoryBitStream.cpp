/*
 * OutMemoryStream.cpp
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#include "OutMemoryBitStream.h"
#include <iostream>
using namespace std;
OutMemoryBitStream::OutMemoryBitStream():mBuffer(nullptr), mBitHead(0), mBitCapacity(0) {
	this->ReallocBuffer(256);
}

OutMemoryBitStream::~OutMemoryBitStream() {
	std::free(mBuffer);
}

const char* OutMemoryBitStream::GetBufferPtr() const{
	return mBuffer;
}

uint32_t OutMemoryBitStream::GetBitLength() const{
	return mBitHead;
}

uint32_t OutMemoryBitStream::GetByteLength() const{
	return (mBitHead + 7) >> 3;
}

void OutMemoryBitStream::WriteBits(uint8_t inData, size_t inBitCount){
	uint32_t nextBitHead = mBitHead + static_cast<uint32_t>(inBitCount);
	if (nextBitHead > mBitCapacity){
		ReallocBuffer(std::max(mBitCapacity*2, nextBitHead));
	}
	uint32_t byteOffset = mBitHead >> 3;
	uint32_t bitOffset = mBitHead & 0x7;

	uint32_t currentMask = ~(0xff << bitOffset);
	mBuffer[byteOffset] = (mBuffer[byteOffset] & currentMask) | (inData << bitOffset);

	uint32_t bitsFreeThisByte = 8 - bitOffset;
	if (bitsFreeThisByte < inBitCount){
		mBuffer[byteOffset +1] = inData >> bitsFreeThisByte;
	}
	mBitHead = nextBitHead;
}

void OutMemoryBitStream::WriteBits(const void* inData, size_t inBitCount){
	const char* srcByte = static_cast<const char*>(inData);
	while(inBitCount > 8){
		WriteBits(*srcByte, 8);
		++srcByte;
		inBitCount -= 8;
	}
	if (inBitCount > 0){
		WriteBits(*srcByte, inBitCount);
	}
}

void OutMemoryBitStream::WriteBytes(const void* inData, size_t inByteCount){
	WriteBits(inData, inByteCount << 3);
}

void OutMemoryBitStream::Write(bool inData){
	WriteBits(&inData, 1);
}

void OutMemoryBitStream::ReallocBuffer(uint32_t inNewLength){
	mBuffer = static_cast<char*>(std::realloc(mBuffer, inNewLength));
	//Обработать ошибку вызова std::realloc!!!!!!!
	mBitCapacity = inNewLength;
}

