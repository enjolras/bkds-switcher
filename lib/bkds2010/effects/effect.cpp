#include <stdio.h>
#include <iostream>
#include "../effectDispatcher.h"
#include "effect.h"

using namespace std;

effect::effect(unsigned char eff, std::shared_ptr<effectDispatcher> effDisp) : eff_(eff),effDisp_(effDisp) {

}

std::shared_ptr<effectDispatcher> effect:effDisp() {
	return effDisp_;
}

void effect::addCommand(unsigned char cmdId, command *cmd) {
    commands_[cmdId] = cmd;
}

void effect::exec(unsigned char *nextCommand) {

    map<unsigned char,std::shared_ptr<command>>::iterator it;
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

unsigned char effect::whoAmI() {
    return eff_;
}

void effect::setName(std::string name) {
    name_ = name;
}

std::string effect::name() {
    return name_;
}

