#include "util.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

util::util(effect* eff) : command(eff) {

	data = 0x58;

}

void util::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	if(nextCommand[2] >= 0x80) {
		data = nextCommand[3];
	}
	tmpResp.addByte(data);

	eff()->addResponse(tmpResp);

}
