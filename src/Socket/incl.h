/*
 * incl.h
 *
 *  Created on: 16.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_INCL_H_
#define SOCKET_INCL_H_


#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX

	#include "Windows.h"
	#include "WinSock2.h"
	#include "Ws2tcpip.h"
	typedef int socklen_t;
	//typedef char* receiveBufer_t;
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	#include <netdb.h>
	#include <errno.h>
	#include <fcntl.h>
	#include <unistd.h>
	//typedef void* receiveBufer_t;
	typedef int SOCKET;
	const int NO_ERROR = 0;
	const int INVALID_SOCKET = -1;
	const int WSAECONNRESET = ECONNRESET;
	const int WSAEWOULDBLOCK = EAGAIN;
	const int SOCKET_ERROR = -1;
#endif
using namespace std;
#include <iostream>

#include "memory"
#include "errno.h"
#include "vector"
#include "unordered_map"
#include "string"
#include "list"
#include "queue"
#include "deque"
#include "unordered_set"
#include "cassert"
#include <cstring>

using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::queue;
using std::list;
using std::deque;
using std::unordered_map;
using std::string;
using std::unordered_set;

//class RoboCat;
//class GameObject;

//#include "StringUtils.h"
//#include "SocketAddress.h"
//#include "SocketAddressFactory.h"
//#include "UDPSocket.h"
//#include "SocketUtil.h"


#endif /* SOCKET_INCL_H_ */