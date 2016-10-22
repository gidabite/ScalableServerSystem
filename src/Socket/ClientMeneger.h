/*
 * ClientMeneger.h
 *
 *  Created on: 22.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_CLIENTMENEGER_H_
#define SOCKET_CLIENTMENEGER_H_
#include "ClientObject.h"
#include "SocketUtil.h";
#include "SocketAddressFactory.h";
#include "Pocket.h";
#include "InputMemoryBitStream.h"

enum ClientTypePocket{
	CTP_HELLO,
	CTP_DISCONNET,
	CTP_ACTION,
	CTP_MAX
};

class ClientMeneger {
public:
	ClientMeneger(AddressFamily af, const string& inString);
	void Wait();
	virtual ~ClientMeneger();
private:
	uint32_t mNextNetworkIdClient;
	std::unordered_map<uint32_t, ClientObject*> mNetworkIdToClientObjectMap;
	UDPSocketPtr socket;
	void AddClient(SocketAddress& adr);
};

#endif /* SOCKET_CLIENTMENEGER_H_ */
