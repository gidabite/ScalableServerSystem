/*
 * ClientObject.h
 *
 *  Created on: 22.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_CLIENTOBJECT_H_
#define SOCKET_CLIENTOBJECT_H_

#include "SocketAddress.h";
#include "../GameObject/InputState.h";
#include <vector>
class BaseObject;

class ClientObject {
public:
	ClientObject();
	SocketAddress& GetAddress(){
		return adr;
	}
	BaseObject* GetObj(){
			return obj;
		}
	void AssociatedWhitObject(BaseObject*  obj);
	void setNetworkId(uint32_t networkId);
	void addInputState(InputState ins);
	virtual ~ClientObject();
private:
	uint32_t time = 0;
	SocketAddress adr;
	BaseObject* obj;
	uint32_t mNetworkId;
	vector<InputState> mInput;
};

#endif /* SOCKET_CLIENTOBJECT_H_ */
