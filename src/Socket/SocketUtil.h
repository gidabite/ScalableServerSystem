/*
 * SocketUtill.h
 *
 *  Created on: 16.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_SOCKETUTIL_H_
#define SOCKET_SOCKETUTIL_H_

#include "incl.h"
#include "UDPSocket.h"

enum AddressFamily{
	INET = AF_INET,
	INET6 = AF_INET6
};

class SocketUtil
{
public:

	static bool			StaticInit();
	static void			CleanUp();

	static void			ReportError( const char* inOperationDesc );
	static int			GetLastError();
	static UDPSocketPtr CreateUDPSocket(AddressFamily adrF);

	//UDPSocketPtr CreateUDPSocket();
private:
	//inline static fd_set* FillSetFromVector( fd_set& outSet, const vector< TCPSocketPtr >* inSockets, int& ioNaxNfds );
	//inline static void FillVectorFromSet( vector< TCPSocketPtr >* outSockets, const vector< TCPSocketPtr >* inSockets, const fd_set& inSet );
};
#endif /* SOCKET_SOCKETUTIL_H_ */
