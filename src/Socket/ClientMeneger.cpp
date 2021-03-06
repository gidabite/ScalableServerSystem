/*
 * ClientMeneger.cpp
 *
 *  Created on: 22.10.2016
 *      Author: gidabite
 */

#include "ClientMeneger.h"

ClientMeneger::ClientMeneger(AddressFamily af, const string& inString): mNextNetworkIdClient(1), socket(socket){
	socket = SocketUtil::CreateUDPSocket(INET);
	socket->SetNonBlock(true);
	socket->Bind(*SocketAddressFactory::CreateIPv4FromString(inString));
};


void ClientMeneger::Wait() {
	char* inBuff = new char[1024];
	ClientObject* client = new ClientObject();
	int readByteCount = socket->ReceiveFrom(inBuff, 1024, client->GetAddress());
	if (readByteCount > 0){
		//cout << "Get data"<< endl;
		bool isNew = false;
		InputMemoryBitStream in(inBuff, readByteCount*8);
		//ClientTypePocket CTP;
		uint8_t PocketT;
		while(in.GetRemainingBitCount() != 0){
			in.ReadBits(&PocketT, 3);
			switch(PocketT)
			{
				case PT_HELLO:{
					client->AssociatedWhitObject(new BaseObject(Position(1,0,1), Rotation(0,0,0), Scale(1,1,1)));
					client->setNetworkId(this->mNextNetworkIdClient);
					client->addInputState(InputState(InputStateEnumeration::IS_CREATE));
					this->mNetworkIdToClientObjectMap[this->mNextNetworkIdClient] = client;
					mNextNetworkIdClient++;
					isNew = true;
					break;
				}
				case PT_ACTION:{
					if (!isNew) delete client;
					uint32_t networkID;
					in.Read(networkID);
					ClientObject* client =  this->mNetworkIdToClientObjectMap[networkID];
					if (client){
						uint16_t timeSync;

						InputState inpSt(InputStateEnumeration::IS_CHANGE);

						float x, y, z;
						in.Read(x);
						in.Read(y);
						in.Read(z);
						inpSt.setPos(Position(x,y,z));

						in.Read(x);
						in.Read(y);
						in.Read(z);
						inpSt.setRot(Rotation(x,y,z));

						in.Read(x);
						in.Read(y);
						in.Read(z);
						inpSt.setSc(Scale(x,y,z));

						while (client->isBlock) {usleep(2);};
						client->isBlock = true;
						client->addInputState(inpSt);
						client->isBlock = false;

						//uint32_t mask;
						//in.ReadBits(&mask, 5);
						//float up, down, left, right;
						//if (mask && IS_UP == IS_UP){
						//	in.Read(up);
						//}
						//if (mask && IS_DOWN == IS_DOWN){
						//	in.Read(down);
						//}
						//if (mask && IS_LEFT == IS_LEFT){
						//	in.Read(left);
						//}
						//if (mask && IS_RIGHT == IS_RIGHT){
						//	in.Read(right);
						//}
						//client->addInputState(InputState(up,down,left,right));
						break;
					}
				}
			}
		}
	}
}

ClientMeneger* ClientMeneger::init(AddressFamily af, const string& inString) {
	if (!cm)
		cm = new ClientMeneger(af, inString);
	return cm;
}
ClientMeneger* ClientMeneger::init() {
	if (!cm)
		return NULL;
	return cm;
}

void ClientMeneger::AddClient(SocketAddress& adr){

}
ClientMeneger::~ClientMeneger() {
	socket.reset();
}

ClientMeneger* ClientMeneger::cm = 0;

const std::unordered_map<uint32_t, ClientObject*>& ClientMeneger::getClient() {
	return this->mNetworkIdToClientObjectMap;
}
