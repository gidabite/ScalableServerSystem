/*
 * OutMemoryStream.h
 *
 *  Created on: 21.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_OUTMEMORYSTREAM_H_
#define SOCKET_OUTMEMORYSTREAM_H_

#include "memory"
#include "cstring"
class OutMemoryStream {
public:
	OutMemoryStream();
	virtual ~OutMemoryStream();

	const char* GetBufferPtr() const;
	uint32_t GetLength() const;

	void Write(const void* inData, size_t inByteCount);
	template<typename T> void Write(T inData);
private:
	void ReallocBuffer(uint32_t inNewLength);
	char* mBuffer;
	uint32_t mHead;
	uint32_t mCapacity;
};

template<typename T> void OutMemoryStream::Write(T inData){
	static_assert(std::is_arithmetic<T>::value || std::is_enum<T>::value, "Generic Write only support primitive data types");
	Write(&inData, sizeof(T));
}
#endif /* SOCKET_OUTMEMORYSTREAM_H_ */
