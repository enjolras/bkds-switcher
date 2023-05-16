#include "eff01_8a.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

eff01_8a::eff01_8a(effect* eff) : command(eff) {

}

void eff01_8a::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(0x01);

	eff()->addResponse(tmpResp);
}
