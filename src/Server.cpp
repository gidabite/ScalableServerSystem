//============================================================================
// Name        : Server.cpp
// Author      : gidabite
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Socket/incl.h"
#include "Components/InputComponent.h"


using namespace std;

std::vector<BaseObject> objects;

int main() {
	InputComponent::init().go();
	InputComponent::init().join();
}
