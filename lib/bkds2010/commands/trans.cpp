#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "trans.h"

using namespace std;

trans::trans(std::shared_ptr<effect> eff) : command(eff) {

    config_[0x90] = 0x01;
    config_[0x91] = 0x02;

}

void trans::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	if(nextCommand[2] >= 0x80) {
		config_[nextCommand[2]] = nextCommand[3];
	}
	tmpResp.addByte(config_[nextCommand[2] | 0x80]);

	conn()->addResponse(tmpResp);

    // TRANS TYPE MIX CAN HAVE DIFFERENT VALUES DEPENDING ON MIX TYPE:
    // 02 - REGULAR MIX
    // 10 - SUPER MIX (WITH PARAMETERS)
    // 08 - NON ADDITIVE MIX (WITH PARAMETERS)

}
