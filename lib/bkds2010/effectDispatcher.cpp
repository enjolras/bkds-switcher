#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "command.h"

using namespace std;

effectDispatcher::effectDispatcher(std::shared_ptr<connectionHandler> conn) : conn_(conn) {

}

void effectDispatcher::addEffect(std::shared_ptr<effect> eff) {

	effects_[eff->myId()] = eff;

	cout << "EFFECT " << eff->name();
	printf(" (%02x) ",eff->myId());
	cout << "ADDED TO DISPATCHER" << endl;
}

void effectDispatcher::exec() {

	map<unsigned char,std::shared_ptr<effect> >::iterator it;
	unsigned char *nextCommand = conn_->getNextCommand();

	it = effects_.find(nextCommand[1]);
	if(it != effects_.end()) {
		it->second->exec(nextCommand);
	} else {
		printf("UNKNOWN EFFECT %02x\n",nextCommand[1]);
	}

}

std::shared_ptr<connectionHandler> effectDispatcher::conn() {
	return conn_;
}
