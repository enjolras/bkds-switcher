#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "effect_chr.h"

using namespace std;

effect_chr::effect_chr(std::shared_ptr<effect> eff) : command(eff) {

	config_[0x05] = 0x01;
	config_[0x0a] = 0x01;

}

void effect_chr::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(nextCommand[3]);
	if(nextCommand[2] >= 0x80) {
		config_[nextCommand[3]] = nextCommand[4];
	}
	tmpResp.addByte(config_[nextCommand[3]]);

	conn()->addResponse(tmpResp);
}
