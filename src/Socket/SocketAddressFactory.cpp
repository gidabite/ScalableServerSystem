/*
 * SocketAddressFactory.cpp
 *
 *  Created on: 16.10.2016
 *      Author: gidabite
 */

#include "SocketAddressFactory.h"


SocketAddressPtr SocketAddressFactory::CreateIPv4FromString(const string& inString) {
	int pos = inString.find_last_of(':');
	string host, service;
	if (pos != string::npos)
	{
		host = inString.substr(0, pos);
		service = inString.substr(pos + 1);
	} else {
		host = inString;
		service = "0"; //Use port on default
	}

	addrinfo hint;
	memset(&hint, 0, sizeof(hint));
	hint.ai_family = AF_INET;
	addrinfo* result;
	int error = getaddrinfo(host.c_str(), service.c_str(), &hint, &result);
	if (error != 0 && result != nullptr){
		freeaddrinfo(result);
		return nullptr;
	}
	while(!result->ai_addr && result->ai_next){
		result = result->ai_next;
	}

	if (!result->ai_addr){
		freeaddrinfo(result);
		return nullptr;
	}
	auto toRet = std::make_shared<SocketAddress>(*result->ai_addr);
	freeaddrinfo(result);
	return toRet;

}

