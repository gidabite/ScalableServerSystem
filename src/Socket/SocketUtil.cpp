/*
 * SocketUtill.cpp
 *
 *  Created on: 16.10.2016
 *      Author: gidabite
 */

#include "SocketUtil.h"
//#include "UDPSocket.h"

void SocketUtil::ReportError( const char* inOperationDesc )
{
	cout << inOperationDesc << endl;
}

UDPSocketPtr SocketUtil::CreateUDPSocket(AddressFamily adrF){
	int s = socket(adrF, SOCK_DGRAM, IPPROTO_UDP);
	if (s != INVALID_SOCKET){
		return UDPSocketPtr(new UDPSocket(s));
	} else {
		SocketUtil::ReportError("UDPSOcket::CreateUDPSocket");
		return nullptr;
	}

}
