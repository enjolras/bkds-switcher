#include "select_xpt.h"
#include "../response.h"
#include "../effects/effect.h"
#include "../../../event.h"

using namespace std;

select_xpt::select_xpt(effect* eff) : command(eff) {

	switch(eff->whoAmI()) {
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
		config_[nextCommand[2] | 0x80] = nextCommand[3] | ((nextCommand[2] | 0x80) == 0x80 && eff()->whoAmI() == 0x01 ? 0x80 : 0x00); // SET HIGH TALLY FOR PGM
	}
	tmpResp.addByte(config_[nextCommand[2] | 0x80]);

	eff()->addResponse(tmpResp);

	if(eff()->whoAmI() == 0x01 && nextCommand[2] == 0x80) {
		event ev(0x00,SET_CURRENT_PGM);
		ev.params()[0] = nextCommand[3];
		eff()->addEvent(ev);
	}
}
