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

effect::effect(unsigned char eff, connectionHandler *conn) : eff_(eff), conn_(conn) {

}

void effect::addCommand(unsigned char cmdId, command *cmd) {
	commands_[cmdId] = cmd;
}

void effect::exec(unsigned char *nextCommand) {

	map<unsigned char,command*>::iterator it;
	it = commands_.find(nextCommand[2]);
	if(it != commands_.end()) {
		it->second->exec(nextCommand);
	} else {
		printf("UNKNOWN COMMAND - EFFECT: %02x - COMMAND %02x - DATA: ",nextCommand[1],nextCommand[2]);
		for(int i=0;i<=nextCommand[0];i++) {
			printf("%02x ",nextCommand[i]);
		}
		printf("\n");
	}
}

unsigned char effect::myId() {
	return eff_;
}

void effect::setName(std::string name) {
	name_ = name;
}

std::string effect::name() {
	return name_;
}
