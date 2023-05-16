#include "eff25.h"
#include "eff_defines.h"
#include "eff21_cmds.h"
#include "../commands/eff25_82.h"

eff25::eff25(unsigned char eff,effectDispatcher* effDisp) : effect(eff,effDisp) {

	setName("FIRMWARE PROGRAM 0x25");

	command* tmpCmd;

	tmpCmd = (command*) new eff25_82(this);
	addCommand(0x82,tmpCmd);
	addCommand(0x80,tmpCmd);

}
