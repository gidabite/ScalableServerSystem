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
#include <cstring>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

std::vector<BaseObject> objects;

int main(int argc, char* argv[]) {

	ClientMeneger::init(INET, argv[1]);
	InputComponent::init().go();
	OutputComponent::init().go();
	HandlerComponent::init().go();

	string str = argv[2];
	str = "../Adapter/GameServers" + str;;

	int fd;
	if ( (fd = open(str.c_str(), O_RDONLY)) <= 0 ) {
		perror("open");
	    return 1;
	}
	int i = 0;
	if ( read(fd, &i, sizeof(int)) == -1 )
		 perror("read() failed. CPU process");
	close(fd);
	unlink(str.c_str());

	InputComponent::init().Cancel();
	OutputComponent::init().Cancel();
	HandlerComponent::init().Cancel();


	InputComponent::init().join();
	OutputComponent::init().join();
	HandlerComponent::init().join();

	str = argv[1];
	str = "Server " + str + " is canceled!";

	cout << str << endl;
	cout.flush();
}
