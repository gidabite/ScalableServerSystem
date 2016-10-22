/*
 * ClientObject.h
 *
 *  Created on: 22.10.2016
 *      Author: gidabite
 */

#ifndef SOCKET_CLIENTOBJECT_H_
#define SOCKET_CLIENTOBJECT_H_

#include "SocketAddress.h";
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
	virtual ~ClientObject();
private:
	SocketAddress adr;
	BaseObject* obj;
};

#endif /* SOCKET_CLIENTOBJECT_H_ */
