/*
 * Serialize.cpp
 *
 *  Created on: 22.10.2016
 *      Author: gidabite
 */

#include "Pocket.h"

Pocket::Pocket(PocketType pt){
	out.Write(pt, ceil(log(PT_MAX)/log(2)));
}

void Pocket::AddObject(BaseObject* inGameObject){

	out.Write(NetworkMeneger::Instance()->GetNetworkId(inGameObject));
	out.Write(BaseObject::classId, 2);
	inGameObject->Serialize(out);
}

OutMemoryBitStream& Pocket::GetStream(){
	return out;
}

