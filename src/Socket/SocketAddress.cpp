/*
 * SocketAddress.cpp
 *
 *  Created on: 16.10.2016
 *      Author: gidabite
 */

#include "SocketAddress.h"

SocketAddress::SocketAddress(uint32_t inAddress, uint16_t inPort) {
	GetAsSockAddrIn()->sin_family = AF_INET;
	GetAsSockAddrIn()->sin_addr.s_addr = htonl(inAddress);
	GetAsSockAddrIn()->sin_port = htons(inPort);
}

SocketAddress::SocketAddress(const sockaddr& inSockAddr) {
	memcpy(&mSockAddr, &inSockAddr, sizeof(sockaddr));
}

uint32_t SocketAddress::GetSize() const {
	return sizeof(sockaddr);
}

sockaddr_in* SocketAddress::GetAsSockAddrIn() {
	return reinterpret_cast<sockaddr_in*>(&(mSockAddr));
}

SocketAddress::~SocketAddress() {
	// TODO Auto-generated destructor stub
}

