/*
 * OutMemoryStream.h
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_OUTMEMORYBITSTREAM_H_
#define SOCKET_OUTMEMORYBITSTREAM_H_

#include "memory"
#include "cstring"

class OutMemoryBitStream {
public:
	OutMemoryBitStream();
	virtual ~OutMemoryBitStream();

	const char* GetBufferPtr() const;
	uint32_t GetBitLength() const;
	uint32_t GetByteLength() const;

	void WriteBits(uint8_t inData, size_t inBitCount);
	void WriteBits(const void* inData, size_t inBitCount);
	template<typename T> void Write(T inData, size_t inBitCount = sizeof(T)*8);
	void WriteBytes(const void* inData, size_t inByteCount);
	template<typename T> void WriteBytes(T inData);
	void Write(bool inData);
private:
	void ReallocBuffer(uint32_t inNewLength);
	char* mBuffer;
	uint32_t mBitHead;
	uint32_t mBitCapacity;
};
template<typename T> void OutMemoryBitStream::Write(T inData, size_t inBitCount){
	static_assert(std::is_arithmetic<T>::value || std::is_enum<T>::value, "Generic Write only support primitive data types");
	WriteBits(&inData, inBitCount);
}

template<typename T> void OutMemoryBitStream::WriteBytes(T inData){
	static_assert(std::is_arithmetic<T>::value || std::is_enum<T>::value, "Generic Write only support primitive data types");
	WriteBits(&inData, sizeof(T) << 3);
}


#endif /* SOCKET_OUTMEMORYBITSTREAM_H_ */
