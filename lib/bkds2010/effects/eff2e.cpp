#include "eff2e.h"
#include "eff_defines.h"
#include "eff2e_cmds.h"
#include "../commands/eff2e_86.h"

eff2e::eff2e(unsigned char eff,effectDispatcher* effDisp) : effect(eff,effDisp) {

	setName("FIRMWARE PROGRAM 0x2E");

	command* tmpCmd;

	tmpCmd = (command*)new eff2e_86(this);
    addCommand(0x06,tmpCmd);
    addCommand(0x86,tmpCmd);
    addCommand(0x00,tmpCmd);
    addCommand(0x80,tmpCmd);
    addCommand(0x03,tmpCmd);
    addCommand(0x83,tmpCmd);

}
