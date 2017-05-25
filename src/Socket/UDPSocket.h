/*
 * UDPSocket.h
 *
 *  Created on: 16.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_UDPSOCKET_H_
#define SOCKET_UDPSOCKET_H_

#include "incl.h"
#include "SocketAddress.h"

class UDPSocket {
public:
	 ~UDPSocket();
	 int Bind(const SocketAddress& inToAddress);
	 int SendTo(const void* inData, int inLen, const SocketAddress& inTo);
	 int ReceiveFrom(void* inBuffer, int inLen, SocketAddress& outFrom);
	 void SetNonBlock(bool isNonBlock);
private:
	 friend class SocketUtil;
	 UDPSocket(int inSocket);
	 int mSocket;
	 bool isNonBlock = false;
};
typedef std::shared_ptr<UDPSocket> UDPSocketPtr;

#endif /* SOCKET_UDPSOCKET_H_ */
