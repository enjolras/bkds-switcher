#include "matte_colormix.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

matte_colormix::matte_colormix(effect* eff) : command(eff) {

}

void matte_colormix::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	switch(nextCommand[2]) {
		case 0x10:
			tmpResp.addByte(0x90);
			break;
		default:
			tmpResp.addByte(nextCommand[2]);
			break;
	}

	eff()->addResponse(tmpResp);

}
