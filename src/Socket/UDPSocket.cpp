/*
 * UDPSocket.cpp
 *
 *  Created on: 16.10.2016
 *      Author: gidabite
 */

#include "UDPSocket.h"
#include "SocketUtil.h"
UDPSocket::UDPSocket(int inSocket): mSocket(inSocket){}

int UDPSocket::Bind(const SocketAddress& inBindAddress)
{
	int error = bind(mSocket,
					 &inBindAddress.mSockAddr,
					 inBindAddress.GetSize());
	if (error != 0){
		SocketUtil::ReportError("UDPSOcket::Bind");
		return -1;
	}
	return NO_ERROR;
}

int UDPSocket::SendTo(const void* inData, int inLen, const SocketAddress& inTo){
	int byteSentCount = sendto(mSocket,
							   static_cast<const char*>(inData),
							   inLen,
							   0,
							   &inTo.mSockAddr,
							   inTo.GetSize());

	if (byteSentCount >= 0){
		return byteSentCount;
	} else {
		SocketUtil::ReportError("UDPSOcket::SendTo");
		return -1;
	}
}

int UDPSocket::ReceiveFrom(void* inToRecive, int inMaxLen, SocketAddress& outFrom){
	socklen_t fromLength = outFrom.GetSize();
	int readByteCount = recvfrom(mSocket,
								 (inToRecive),
								 inMaxLen,
								 0,
								 &outFrom.mSockAddr,
								 &fromLength);
	if (isNonBlock || readByteCount >= 0){
		return readByteCount;
	} else {
		cout << errno << endl;
		SocketUtil::ReportError("Error UDPSOcket::ReceiveFrom");
		return -1;
	}
}

UDPSocket::~UDPSocket() {
#if _WIN32
	closesocket( mSocket );
#else
	close( mSocket );
#endif
}

void UDPSocket::SetNonBlock(bool isNonBlock) {
	int fl = fcntl(mSocket, F_GETFL, 0);
	fl = isNonBlock ? (fl | O_NONBLOCK):(fl & ~O_NONBLOCK);
	fcntl(mSocket, F_SETFL, fl);
	this->isNonBlock = true;
}
