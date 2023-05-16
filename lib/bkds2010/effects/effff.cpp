#include "effff.h"
#include "eff_defines.h"
#include "effff_cmds.h"
#include "../commands/ping.h"

effff::effff(unsigned char eff,effectDispatcher* effDisp) : effect(eff,effDisp) {

	setName("PING");

	command* tmpCmd;

    tmpCmd = (command*)new ping(this);       // PING
    addCommand(0x80,tmpCmd);

}
