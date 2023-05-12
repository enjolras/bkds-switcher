#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "eff00_13.h"

using namespace std;

eff00_13::eff00_13(std::shared_ptr<effect> eff) : command(eff) {

}

void eff00_13::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(0x01);

	conn()->addResponse(tmpResp);
}
