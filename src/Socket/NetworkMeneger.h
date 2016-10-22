/*
 * NetworkMeneger.h
 *
 *  Created on: 22.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_NETWORKMENEGER_H_
#define SOCKET_NETWORKMENEGER_H_

#include "../GameObject/BaseObject.h"
#include <unordered_map>;

class NetworkMeneger {
public:
	static NetworkMeneger* Instance();
	uint32_t GetNetworkId(BaseObject* inGameObject);
	BaseObject* GetObject(uint32_t networkId);
	void AddObject(BaseObject* inGameObject);
	void RemoveObject(BaseObject*);
	virtual ~NetworkMeneger();
private:
	NetworkMeneger(): mNextNetworkId(1){};
	NetworkMeneger(NetworkMeneger const&) = delete;
	NetworkMeneger& operator= (NetworkMeneger const&) = delete;

	static NetworkMeneger* nm;
	uint32_t mNextNetworkId;
	std::unordered_map<uint32_t, BaseObject*> mNetworkIdToGameObjectMap;
	std::unordered_map<const BaseObject*, uint32_t> mGameObjectRoNetworkIdMap;
};

#endif /* SOCKET_NETWORKMENEGER_H_ */
