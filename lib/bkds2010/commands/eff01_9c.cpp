#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "eff01_9c.h"

using namespace std;

eff01_9c::eff01_9c(std::shared_ptr<effect> eff) : command(eff) {

}

void eff01_9c::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(nextCommand[3]);
	tmpResp.addByte(0x01);

	conn()->addResponse(tmpResp);
}
