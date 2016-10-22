/*
 * Serialize.h
 *
 *  Created on: 22.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_POCKET_H_
#define SOCKET_POCKET_H_

#include "NetworkMeneger.h"
#include "OutMemoryBitStream.h"
#include "cmath"

enum PocketType{
	PT_HELLO,
	PT_DISCONNECT,
	PT_RepData,
	PT_MAX
};

class Pocket {
public:
	Pocket(PocketType pt);
	void AddObject(BaseObject* inGameObject);
	OutMemoryBitStream& GetStream();

private:
	OutMemoryBitStream out;
};

#endif /* SOCKET_POCKET_H_ */
