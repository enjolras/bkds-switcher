#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "command.h"

using namespace std;

effectDispatcher::effectDispatcher(connectionHandler *conn) : conn_(conn) {

}

void effectDispatcher::addEffect(effect *eff) {

	effects_[eff->myId()] = eff;

	cout << "EFFECT " << eff->name();
	printf(" (%02x) ",eff->myId());
	cout << "ADDED TO DISPATCHER" << endl;
}

void effectDispatcher::exec() {

	map<unsigned char,effect*>::iterator it;
	unsigned char *nextCommand = conn_->getNextCommand();

	it = effects_.find(nextCommand[1]);
	if(it != effects_.end()) {
		it->second->exec(nextCommand);
	} else {
		printf("UNKNOWN EFFECT %02x\n",nextCommand[1]);
	}

}

connectionHandler* effectDispatcher::conn() {
	return conn_;
}
