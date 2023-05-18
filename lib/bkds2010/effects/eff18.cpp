#include "eff18.h"
#include "eff_defines.h"
#include "eff18_cmds.h"
#include "../commands/matteparams.h"
#include "../commands/matte_colormix.h"

eff18::eff18(unsigned char eff,effectDispatcher* effDisp) : effect(eff,effDisp) {

	setName("MATTE");

	command* tmpCmd;

	tmpCmd = (command*)new matte_colormix(this);
	addCommand(0x10,tmpCmd);
	addCommand(0x90,tmpCmd);
	addCommand(0xd0,tmpCmd);

    tmpCmd = (command*)new matteparams(this);
    addCommand(0x2a,tmpCmd);
    addCommand(0xaa,tmpCmd);

}
