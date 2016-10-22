//============================================================================
// Name        : Server.cpp
// Author      : gidabite
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Socket/incl.h"

#include "Socket/SocketUtil.h";
#include "Socket/UDPSocket.h";
#include "Socket/SocketAddressFactory.h";
#include "Socket/Pocket.h"
#include "Socket/ClientObject.h";
#include "Socket/ClientMeneger.h";

using namespace std;

std::vector<BaseObject> objects;

int main() {

	ClientMeneger cm(INET, "192.168.1.45:45678");
	char inBuff[100];
	cout << "Start reading" << endl;
	int i = 0;
	while (true) {
		i++;

		cm.Wait();
		//cout << (char *)inBuff<< endl;
		//cout << readByteCount;
		cout << i << endl;
	}
}
