#include <cstdio>
#include <iostream>
#include <unistd.h>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "effects/eff_defines.h"
#include "effects/eff00.h"
#include "effects/eff01.h"
#include "effects/eff10.h"
#include "effects/eff14.h"
#include "effects/eff15.h"
#include "effects/eff18.h"
#include "effects/eff1e.h"
#include "effects/eff1f.h"
#include "effects/eff20.h"
#include "effects/eff21.h"
#include "effects/eff25.h"
#include "effects/eff2e.h"
#include "effects/eff_aux.h"
#include "effects/effff.h"

using namespace std;

effectDispatcher::effectDispatcher(connectionHandler* conn) : conn_(conn) {

}

void effectDispatcher::init() {

	addEffect((effect*)new eff00((unsigned char)EFF_PPROW,this));	// PPROW
	addEffect((effect*)new eff01((unsigned char)EFF_ME1ROW,this));	// ME1ROW
	addEffect((effect*)new eff10((unsigned char)EFF_CHRKEY,this));	// CHRKEY
	addEffect((effect*)new eff14((unsigned char)EFF_FRMEM1,this));	// FRMEM1
	addEffect((effect*)new eff15((unsigned char)EFF_FRMEM2,this));	// FRMEM2 
	addEffect((effect*)new eff18((unsigned char)EFF_MATTE,this));	// MATTE
	addEffect((effect*)new eff1e((unsigned char)EFF_VPROC,this));	// VPROC
	addEffect((effect*)new eff1f((unsigned char)EFF_CCR,this));		// CCR
	addEffect((effect*)new eff20((unsigned char)EFF_SYSCTRL,this));	// SYSCTRL
	addEffect((effect*)new eff21((unsigned char)EFF_EVENTMEM,this));// EVENTMEM
	addEffect((effect*)new eff25((unsigned char)EFF_PRGPGM2,this));	// PRGPGM2
	addEffect((effect*)new eff2e((unsigned char)EFF_PRGPGM,this));	// PRGPGM
	addEffect((effect*)new eff_aux((unsigned char)EFF_AUX1,this));	// AUX1
	addEffect((effect*)new eff_aux((unsigned char)EFF_AUX2,this));	// AUX2
	addEffect((effect*)new eff_aux((unsigned char)EFF_AUX3,this));	// AUX3
	addEffect((effect*)new eff_aux((unsigned char)EFF_AUX4,this));	// AUX4
	addEffect((effect*)new eff_aux((unsigned char)EFF_AUX5,this));	// AUX5
	addEffect((effect*)new eff_aux((unsigned char)EFF_AUX6,this));	// AUX6
	addEffect((effect*)new eff_aux((unsigned char)EFF_EDITPVW,this));	// EDIT PVW
	addEffect((effect*)new effff((unsigned char)EFF_PING,this));	// PING

}

void effectDispatcher::addEffect(effect* eff) {

	effects_[eff->whoAmI()] = eff;

	cout << "EFFECT " << eff->name();
	printf(" (%02x) ",eff->whoAmI());
	cout << "ADDED TO DISPATCHER" << endl;
}

void effectDispatcher::addResponse(response &resp) {
	conn()->addResponse(resp);
}

void effectDispatcher::exec() {
	while(true) {
		map<unsigned char,effect*>::iterator it;
		unsigned char *nextCommand = conn()->getNextCommand();

		it = effects_.find(nextCommand[1]);
		if(it != effects_.end()) {
			it->second->exec(nextCommand);
		} else {
			printf("UNKNOWN EFFECT %02x\n",nextCommand[1]);
		}
		conn()->commitResponses();
		usleep(100);
	}
}

connectionHandler* effectDispatcher::conn() {
	return conn_;
}
