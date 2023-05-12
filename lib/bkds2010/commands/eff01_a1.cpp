#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "eff01_a1.h"

using namespace std;

eff01_a1::eff01_a1(std::shared_ptr<effect> eff) : command(eff) {

}

void eff01_a1::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	if(nextCommand[2] >= 0x80) {
		config_[0] = nextCommand[3];
		config_[1] = nextCommand[4];
	}
	tmpResp.addByte(config_[0]);
	tmpResp.addByte(config_[1]);

	conn()->addResponse(tmpResp);
}
