#include "eff25_82.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

eff25_82::eff25_82(effect* eff) : command(eff) {

}

void eff25_82::exec(unsigned char *nextCommand) {

	response tmpResp;
	response tempRes[256];

	if((nextCommand[2] | 0x80) == 0x80) {
		for(int i=0;i<256;i++) {
			tempRes[i].addByte(nextCommand[1]);
			tempRes[i].addByte(nextCommand[2] | 0x80 );
			for(int j=3; j<=nextCommand[0];j++) {
				tempRes[i].addByte(nextCommand[j]);
			}
			tempRes[i].debugResponse();
			eff()->addResponse(tempRes[i]);
		}
	} else {
		tmpResp.addByte(nextCommand[1]);
		tmpResp.addByte(nextCommand[2] | 0x80);
		for(int i=3; i<=nextCommand[0];i++) {
			tmpResp.addByte(nextCommand[i]);
		}
		eff()->addResponse(tmpResp);
	}

}
