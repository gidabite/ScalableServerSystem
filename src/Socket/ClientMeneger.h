/*
 * ClientMeneger.h
 *
 *  Created on: 22.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_CLIENTMENEGER_H_
#define SOCKET_CLIENTMENEGER_H_
#include "ClientObject.h"
#include "SocketUtil.h"
#include "SocketAddressFactory.h"
#include "Pocket.h"
#include "InputMemoryBitStream.h"

enum ClientTypePocket{
	CTP_HELLO,
	CTP_DISCONNET,
	CTP_ACTION,
	CTP_MAX
};

class ClientMeneger {
public:
	static ClientMeneger* init(AddressFamily af, const string& inString);
	static ClientMeneger* init();
	const std::unordered_map<uint32_t, ClientObject*>& getClient();
	void Wait();

	const UDPSocketPtr& getSocket() const {
		return socket;
	}

private:
	ClientMeneger(AddressFamily af, const string& inString);
	uint32_t mNextNetworkIdClient;
	std::unordered_map<uint32_t, ClientObject*> mNetworkIdToClientObjectMap;
	UDPSocketPtr socket;
	void AddClient(SocketAddress& adr);
	virtual ~ClientMeneger();
	static ClientMeneger* cm;
};

#endif /* SOCKET_CLIENTMENEGER_H_ */
