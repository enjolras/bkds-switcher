#include "eff18.h"
#include "eff_defines.h"
#include "eff18_cmds.h"
#include "../commands/matteparams.h"

eff18::eff18(unsigned char eff,effectDispatcher* effDisp) : effect(eff,effDisp) {

	setName("MATTE");

	command* tmpCmd;

    tmpCmd = (command*)new matteparams(this);
    addCommand(0x2a,tmpCmd);
    addCommand(0xaa,tmpCmd);

}
