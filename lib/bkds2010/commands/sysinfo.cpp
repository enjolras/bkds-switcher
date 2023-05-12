#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "effectDispatcher.h"
#include "sysinfo.h"

using namespace std;

sysinfo::sysinfo(std::shared_ptr<effect> eff) : command(eff) {

}

void sysinfo::exec(unsigned char *nextCommand) {

    char tmptime[5];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(nextCommand[3]);
	switch(nextCommand[3]) {
		case 0x00:			// DATE FIRST PART
    		sprintf(tmptime,"0x%02d",tm.tm_mon+1);
			tmpResp.addByte(strtoul(tmptime, NULL, 16));
    		sprintf(tmptime,"0x%02d",tm.tm_mday);
			tmpResp.addByte(strtoul(tmptime, NULL, 16));
    		sprintf(tmptime,"0x%02d",tm.tm_year - 80);
			tmpResp.addByte(strtoul(tmptime, NULL, 16));
			break;
		case 0x01:			// DATE SECOND PART
    		sprintf(tmptime,"0x%02d",tm.tm_hour);
			tmpResp.addByte(strtoul(tmptime, NULL, 16));
    		sprintf(tmptime,"0x%02d",tm.tm_min);
			tmpResp.addByte(strtoul(tmptime, NULL, 16));
    		sprintf(tmptime,"0x%02d",tm.tm_sec);
			tmpResp.addByte(strtoul(tmptime, NULL, 16));
			break;
		case 0x09:			// SYSTEM
			tmpResp.addByte(0x02);
			break;
		case 0x0f:			// SWER
			tmpResp.addByte('1');
			tmpResp.addByte('.');
			tmpResp.addByte('0');
			tmpResp.addByte('0');
			tmpResp.addByte(' ');
			tmpResp.addByte('O');
			tmpResp.addByte('B');
			tmpResp.addByte('S');
			tmpResp.addByte(' ');
			tmpResp.addByte(' ');
			break;
	}

	conn()->addResponse(tmpResp);

	/* SYSTEM:
		0x00	D2 525
		0x01	D1 525
		0x02	D2 625
		0x03	D1 625

	*/
}
