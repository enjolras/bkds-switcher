#include "dsk.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

dsk::dsk(effect* eff) : command(eff) {

}

void dsk::exec(unsigned char *nextCommand) {

	response tmpResp;

	switch(nextCommand[2]) {
		case 0xd3:
		case 0x93:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2]);
			break;
		case 0x90:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2]);
			tmpResp.addByte(nextCommand[3]);
			break;
	}

	eff()->addResponse(tmpResp);
}
