/*
 * SocketAddress.h
 *
 *  Created on: 16.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_SOCKETADDRESS_H_
#define SOCKET_SOCKETADDRESS_H_

#include "incl.h"

using namespace std;

class SocketAddress {
public:
	SocketAddress(uint32_t inAddress, uint16_t inPort);
	SocketAddress(const sockaddr& inSockAddr);
	SocketAddress() {};
	virtual ~SocketAddress();
	uint32_t GetSize() const;
	friend class UDPSocket;
private:
	sockaddr mSockAddr;
	sockaddr_in* GetAsSockAddrIn();
};
typedef std::shared_ptr<SocketAddress> SocketAddressPtr;
#endif /* SOCKET_SOCKETADDRESS_H_ */
