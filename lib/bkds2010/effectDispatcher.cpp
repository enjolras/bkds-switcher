#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "effects/eff_defines.h"
#include "effects/eff00.h"
#include "commands/command.h"

using namespace std;

effectDispatcher::effectDispatcher(std::shared_ptr<connectionHandler> conn) : conn_(conn) {

	addEffect((std::shared_ptr<effect>)std::make_shared<eff00>((unsigned char)EFF_PPROW,shared_from_this()));	// PPROW

}

void effectDispatcher::addEffect(std::shared_ptr<effect> eff) {

	effects_[eff->whoAmI()] = eff;

	cout << "EFFECT " << eff->name();
	printf(" (%02x) ",eff->whoAmI());
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
