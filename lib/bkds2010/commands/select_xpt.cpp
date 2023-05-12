#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "select_xpt.h"

using namespace std;

select_xpt::select_xpt(std::shared_ptr<effect> eff) : command(eff) {

	switch(eff->myId()) {
		case 0x00:
			config_[0x87] = 0x00;
			break;
		case 0x01:
		    config_[0x80] = 0x80;
   			config_[0x81] = 0x00;
		    config_[0x87] = 0x00;
		    config_[0x8d] = 0x00;
			break;
		case 0x30:
		case 0x31:
		case 0x32:
		case 0x33:
		case 0x34:
		case 0x35:
		case 0x3f:
			config_[0x80] = 0x00;
			break;
		}
}

void select_xpt::exec(unsigned char *nextCommand) {

	response tmpResp;
	tmpResp.addByte(nextCommand[1]);
	if(nextCommand[2] < 0x80) {
		tmpResp.addByte(nextCommand[2] | 0x80);
	} else {
		tmpResp.addByte(nextCommand[2]);
		config_[nextCommand[2] | 0x80] = nextCommand[3] | ((nextCommand[2] | 0x80) == 0x80 && eff()->myId() == 0x01 ? 0x80 : 0x00); // SET HIGH TALLY FOR PGM
	}
	tmpResp.addByte(config_[nextCommand[2] | 0x80]);

	conn()->addResponse(tmpResp);

}
