#include "enable.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

enable::enable(effect* eff) : command(eff) {

}

void enable::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte((nextCommand[2] < 0x80 ? 0x08 : nextCommand[3]));

	eff()->addResponse(tmpResp);
}
