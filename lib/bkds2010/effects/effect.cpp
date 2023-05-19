#include <cstdio>
#include "../effectDispatcher.h"
#include "../commands/command.h"
#include "effect.h"

using namespace std;

effect::effect(unsigned char eff, effectDispatcher* effDisp) : eff_(eff),effDisp_(effDisp) {

}

effectDispatcher* effect::effDisp() {
	return effDisp_;
}

void effect::addCommand(unsigned char cmdId, command* cmd) {

	printf("  ADDED COMMAND %02x TO EFFECT %02x\n",cmdId,eff_);
    commands_[cmdId] = cmd;
}

void effect::addResponse(response &resp) {
	effDisp()->addResponse(resp);
}

void effect::addEvent(event &ev) {
	effDisp()->addEvent(ev);
}

void effect::exec(unsigned char *nextCommand) {

    map<unsigned char,command*>::iterator it;
    it = commands_.find(nextCommand[2]);
    if(it != commands_.end()) {
        it->second->exec(nextCommand);
    } else {
        printf("EFFECT %02x (%s) - UNKNOWN COMMAND %02x - DATA: ",whoAmI(),name().c_str(),nextCommand[2]);
        for(int i=0;i<=nextCommand[0];i++) {
            printf("%02x ",nextCommand[i]);
        }
        printf("\n");
    }
}

unsigned char effect::whoAmI() {
    return eff_;
}

void effect::setName(std::string name) {
    name_ = name;
}

std::string effect::name() {
    return name_;
}

