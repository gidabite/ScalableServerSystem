/*
 * ClientMeneger.cpp
 *
 *  Created on: 22.10.2016
 *      Author: gidabite
 */

#include "ClientMeneger.h"

ClientMeneger::ClientMeneger(AddressFamily af, const string& inString): mNextNetworkIdClient(1), socket(socket){
	socket = SocketUtil::CreateUDPSocket(INET);
	socket->Bind(*SocketAddressFactory::CreateIPv4FromString(inString));
};


void ClientMeneger::Wait() {
	char* inBuff = new char[1024];
	InputMemoryBitStream in(inBuff, 1024);

	ClientObject newClient;
	int readByteCount = socket->ReceiveFrom(inBuff, 1024, newClient.GetAddress());
	//ClientTypePocket CTP;
	char* ans = new char[6];
	in.ReadBytes(ans, 6);
	if (strcmp(ans,"HELLO") == 0){
		newClient.AssociatedWhitObject(new BaseObject(Position(2,1,3), Rotation(1,0,2.5), Scale(3,2,1))); //СОЗДАВАТЬ НЕ ЗДЕСЬ!!!
		this->mNetworkIdToClientObjectMap[mNextNetworkIdClient] = &newClient;
		mNextNetworkIdClient++;
		Pocket pocket(PT_RepData);
		pocket.AddObject(newClient.GetObj());
		socket->SendTo(pocket.GetStream().GetBufferPtr(), pocket.GetStream().GetByteLength(), newClient.GetAddress());
	} else {
	}
}

void ClientMeneger::AddClient(SocketAddress& adr){

}
ClientMeneger::~ClientMeneger() {
	socket.reset();
}

