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
	IS_JUMP = 0x10
};

class InputState {
public:
	InputState(float up, float down, float left, float right): mUp(up), mDown(down), mLeft(left), mRight(right)	{};
	virtual ~InputState();
private:
	float mUp;
	float mDown;
	float mLeft;
	float mRight;
};

#endif /* GAMEOBJECT_INPUTSTATE_H_ */
