/*
 * InputState.h
 *
 *  Created on: 14.11.2016
 *      Author: gidabite
 */

#ifndef GAMEOBJECT_INPUTSTATE_H_
#define GAMEOBJECT_INPUTSTATE_H_

enum InputStateEnumeration{
	IS_UP = 0x01,
	IS_DOWN = 0x02,
	IS_LEFT = 0x04,
	IS_RIGHT = 0x08,
	IS_JUMP = 0x10,
	IS_CREATE = 0x20
};

class InputState {
public:
	InputState(InputStateEnumeration state, float value): state(state), value(value){};
	virtual ~InputState();

InputStateEnumeration getState() const {
	return state;
}

float getValue() const {
	return value;
}

private:
	float value;
	InputStateEnumeration state;
};

#endif /* GAMEOBJECT_INPUTSTATE_H_ */
