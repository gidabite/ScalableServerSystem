/*
 * InputState.h
 *
 *  Created on: 14.11.2016
 *      Author: gidabite
 */

#ifndef GAMEOBJECT_INPUTSTATE_H_
#define GAMEOBJECT_INPUTSTATE_H_


#include "../PhysicalParameters/Position.h"
#include "../PhysicalParameters/Rotation.h"
#include "../PhysicalParameters/Scale.h"

enum InputStateEnumeration{
	IS_CREATE = 0x01,
	IS_CHANGE = 0x02
};

class InputState {
public:
	InputState(InputStateEnumeration state): state(state){};
	virtual ~InputState();

InputStateEnumeration getState() const {
	return state;
}

	const Position& getPos() const {
		return pos;
	}

	void setPos(const Position& pos = Position(0, 0, 0)) {
		this->pos = pos;
	}

	const Rotation& getRot() const {
		return rot;
	}

	void setRot(const Rotation& rot = Rotation(0, 0, 0)) {
		this->rot = rot;
	}

	const Scale& getSc() const {
		return sc;
	}

	void setSc(const Scale& sc = Scale(0, 0, 0)) {
		this->sc = sc;
	}

private:
	Position pos = Position(0,0,0);
	Rotation rot = Rotation(0,0,0);
	Scale sc = Scale(1,1,1);
	InputStateEnumeration state;
};

#endif /* GAMEOBJECT_INPUTSTATE_H_ */
