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
#include "Socket/OutMemoryStream.h"
#include "GameObject/BaseObject.h";
using namespace std;

std::vector<BaseObject> objects;

int main() {

	UDPSocketPtr s_ptr = SocketUtil::CreateUDPSocket(INET);
	s_ptr->Bind(*SocketAddressFactory::CreateIPv4FromString("192.168.1.45:45678"));
	char inBuff[100];
	SocketAddress outAddr;
	cout << "Start reading" << endl;
	int i = 0;
	while (true) {
		i++;
		int readByteCount = s_ptr->ReceiveFrom((inBuff), 100, outAddr);
		if (strcmp(inBuff, "HELLO") == 0){
			objects.push_back(BaseObject(Position(2,1,3), Rotation(1,0,2.5), Scale(3,2,1)));
			OutMemoryStream out;
			objects.back().Serialization(out);
			s_ptr->SendTo(out.GetBufferPtr(), out.GetLength(), outAddr);
		}
		//cout << (char *)inBuff<< endl;
		//cout << readByteCount;
		cout << i << endl;
	}
	s_ptr.reset();
}
