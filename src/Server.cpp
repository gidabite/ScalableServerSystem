//============================================================================
// Name        : Server.cpp
// Author      : gidabite
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Socket/incl.h"
#include "Components/InputComponent.h"
#include "Components/OutputComponent.h"
#include "Components/HandlerComponent.h"

using namespace std;

std::vector<BaseObject> objects;

int main() {
	ClientMeneger::init(INET, "192.168.43.215:45678");
	InputComponent::init().go();
	OutputComponent::init().go();
	HandlerComponent::init().go();
	InputComponent::init().join();
	OutputComponent::init().join();
	HandlerComponent::init().join();
}
