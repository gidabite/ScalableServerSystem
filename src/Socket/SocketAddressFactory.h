/*
 * SocketAddressFactory.h
 *
 *  Created on: 16.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_SOCKETADDRESSFACTORY_H_
#define SOCKET_SOCKETADDRESSFACTORY_H_

#include "incl.h"
#include "SocketAddress.h"

using namespace std;
class SocketAddressFactory {
public:
	static SocketAddressPtr CreateIPv4FromString(const string& inString);
};

#endif /* SOCKET_SOCKETADDRESSFACTORY_H_ */
