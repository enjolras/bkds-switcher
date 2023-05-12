#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "enable.h"

using namespace std;

enable::enable(std::shared_ptr<effect> eff) : command(eff) {

}

void enable::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte((nextCommand[2] < 0x80 ? 0x08 : nextCommand[3]));

	conn()->addResponse(tmpResp);
}
