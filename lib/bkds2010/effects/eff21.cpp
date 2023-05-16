#include "eff21.h"
#include "eff_defines.h"
#include "eff21_cmds.h"
#include "../commands/eventmem.h"

eff21::eff21(unsigned char eff,effectDispatcher* effDisp) : effect(eff,effDisp) {

	setName("EVENT MEMORY");

	command* tmpCmd;

    tmpCmd = (command*)new eventmem(this);
    addCommand(0x88,tmpCmd);

}
