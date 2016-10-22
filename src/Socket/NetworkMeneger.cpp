/*
 * NetworkMeneger.cpp
 *
 *  Created on: 22.10.2016
 *      Author: gidabite
 */

#include "NetworkMeneger.h"

NetworkMeneger* NetworkMeneger::nm = 0;

NetworkMeneger* NetworkMeneger::Instance(){
	if(!nm) nm = new NetworkMeneger();
	return nm;
}

uint32_t NetworkMeneger::GetNetworkId(BaseObject* inGameObject){
	auto it = this->mGameObjectRoNetworkIdMap.find(inGameObject);
	if (it != this->mGameObjectRoNetworkIdMap.end()){
		return it->second;
	} else {
		AddObject(inGameObject);
		return mNextNetworkId - 1;
	}
}

void NetworkMeneger::AddObject(BaseObject* inGameObject){
	this->mNetworkIdToGameObjectMap[mNextNetworkId] = inGameObject;
	this->mGameObjectRoNetworkIdMap[inGameObject] = mNextNetworkId;
	mNextNetworkId++;
}

void NetworkMeneger::RemoveObject(BaseObject* inGameObject){
	uint32_t networkId = this->mGameObjectRoNetworkIdMap[inGameObject];
	this->mGameObjectRoNetworkIdMap.erase(inGameObject);
	this->mNetworkIdToGameObjectMap.erase(networkId);
}

BaseObject* NetworkMeneger::GetObject(uint32_t networkId){
	auto it = this->mNetworkIdToGameObjectMap.find(networkId);
	if (it != mNetworkIdToGameObjectMap.end()){
		return it->second;
	} else
		return nullptr;
}

NetworkMeneger::~NetworkMeneger() {
	// TODO Auto-generated destructor stub
}

