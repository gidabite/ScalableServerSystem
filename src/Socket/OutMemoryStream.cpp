/*
 * OutMemoryStream.cpp
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#include "OutMemoryStream.h"

OutMemoryStream::OutMemoryStream():mBuffer(nullptr), mHead(0), mCapacity(0) {
	this->ReallocBuffer(32);
}

OutMemoryStream::~OutMemoryStream() {
	std::free(mBuffer);
}

const char* OutMemoryStream::GetBufferPtr() const{
	return mBuffer;
}

uint32_t OutMemoryStream::GetLength() const{
	return mHead;
}

void OutMemoryStream::Write(const void* inData, size_t inByteCount){
	uint32_t resultHead = mHead + static_cast<uint32_t>(inByteCount);
	if (resultHead > mCapacity){
		ReallocBuffer(std::max(mCapacity*2, resultHead));
	}
	std::memcpy(mBuffer + mHead, inData, inByteCount);
	mHead = resultHead;
}

void OutMemoryStream::ReallocBuffer(uint32_t inNewLength){
	mBuffer = static_cast<char*>(std::realloc(mBuffer, inNewLength));
	//Обработать ошиьку вызова std::realloc!!!!!!!
	mCapacity = inNewLength;
}
