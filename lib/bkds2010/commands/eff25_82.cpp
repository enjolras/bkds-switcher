#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "eff25_82.h"

using namespace std;

eff25_82::eff25_82(std::shared_ptr<effect> eff) : command(eff) {

}

void eff25_82::exec(unsigned char *nextCommand) {

	response tmpResp;
	response tempRes[256];

	if((nextCommand[2] | 0x80) == 0x80) {
//		tmpResp.addByte(nextCommand[1]);
//		tmpResp.addByte(nextCommand[2]);
//		tmpResp.addByte(0x00);
//		tmpResp.addByte(0x01);
//		tmpResp.addByte(0x1c);
//		tmpResp.addByte(0x00);
//		tmpResp.addByte(0x7a);
		for(int i=0;i<256;i++) {
			tempRes[i].addByte(nextCommand[1]);
			tempRes[i].addByte(nextCommand[2] | 0x80 );
/*			tempRes[i].addByte(0x00);
			tempRes[i].addByte(0x01);
			tempRes[i].addByte(i);*/
//			tmpResp.addByte(0x01);
//			tmpResp.addByte(0x1c);
//			tmpResp.addByte(0x00);
			for(int j=3; j<=nextCommand[0];j++) {
				tempRes[i].addByte(nextCommand[j]);
			}
/*			tempRes[i].addByte(0x7f);
			tempRes[i].addByte(0x00);
			tempRes[i].addByte(i);*/
			tempRes[i].debugResponse();
			conn()->addResponse(tempRes[i]);
		}
	} else {
		tmpResp.addByte(nextCommand[1]);
		tmpResp.addByte(nextCommand[2] | 0x80);
		for(int i=3; i<=nextCommand[0];i++) {
			tmpResp.addByte(nextCommand[i]);
		}
		conn()->addResponse(tmpResp);
	}

}
