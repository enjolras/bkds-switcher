#include "eff2e_86.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

eff2e_86::eff2e_86(effect* eff) : command(eff) {

}

void eff2e_86::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);

	if(nextCommand[2] == 0x80 || nextCommand[2] == 0x83) {
		tmpResp.addByte(nextCommand[3]) ;
	}

	eff()->addResponse(tmpResp);
}
