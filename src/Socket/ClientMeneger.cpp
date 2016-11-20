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
	ClientObject* client = new ClientObject();
	int readByteCount = socket->ReceiveFrom(inBuff, 1024, client->GetAddress());
	InputMemoryBitStream in(inBuff, readByteCount*8);
	//ClientTypePocket CTP;
	int PocketT;
	while(in.GetRemainingBitCount() != 0){
		uint32_t u = in.GetRemainingBitCount();
		in.ReadBits(&PocketT, 3);
		if (PocketT == PT_HELLO){
			client->AssociatedWhitObject(new BaseObject(Position(2,1,3), Rotation(1,0,2.5), Scale(3,2,1))); //СОЗДАВАТЬ НЕ ЗДЕСЬ!!!
			client->setNetworkId(this->mNextNetworkIdClient);
			this->mNetworkIdToClientObjectMap[this->mNextNetworkIdClient] = client;
			mNextNetworkIdClient++;
			Pocket pocket(PT_REPDATA);
			pocket.AddObject(client->GetObj());
			socket->SendTo(pocket.GetStream().GetBufferPtr(), pocket.GetStream().GetByteLength(), client->GetAddress());
		} else delete client;
		if (PocketT == PT_ACTION){
			uint32_t networkID;
			in.Read(networkID);
			ClientObject* client =  this->mNetworkIdToClientObjectMap[networkID];
			uint32_t mask;
			in.ReadBits(&mask, 5);
			float up, down, left, right;
			if (mask && IS_UP == IS_UP){
				in.Read(up);
			}
			if (mask && IS_DOWN == IS_DOWN){
				in.Read(down);
			}
			if (mask && IS_LEFT == IS_LEFT){
				in.Read(left);
			}
			if (mask && IS_RIGHT == IS_RIGHT){
				in.Read(right);
			}
			client->addInputState(InputState(up,down,left,right));
		}
	}
}

void ClientMeneger::AddClient(SocketAddress& adr){

}
ClientMeneger::~ClientMeneger() {
	socket.reset();
}

