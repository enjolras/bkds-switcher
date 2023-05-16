#include "eff00.h"
#include "eff_defines.h"
#include "eff00_cmds.h"
#include "../commands/select_xpt.h"
#include "../commands/eff00_13.h"
#include "../commands/key.h"
#include "../commands/auto_rate.h"
#include "../commands/dsk.h"
#include "../commands/matteparams.h"

eff00::eff00(unsigned char eff,effectDispatcher* effDisp) : effect(eff,effDisp) {

	setName("PPROW");

	command* tmpCmd;

	tmpCmd = (command*)new select_xpt(this);
	addCommand((unsigned char)RD_SELECT_XPT,tmpCmd);
	addCommand((unsigned char)WR_SELECT_XPT,tmpCmd);

    tmpCmd = (command*)new eff00_13(this);
    addCommand(0x13,tmpCmd);

    tmpCmd = (command*)new key(this);
    addCommand(0x1a,tmpCmd);
    addCommand(0x9a,tmpCmd);
    addCommand(0xda,tmpCmd);

    tmpCmd = (command*)new auto_rate(this);
    addCommand(0x18,tmpCmd);
    addCommand(0x98,tmpCmd);

    tmpCmd = (command*)new dsk(this);
    addCommand(0x90,tmpCmd);
    addCommand(0x93,tmpCmd);
    addCommand(0xd3,tmpCmd);

    tmpCmd = (command*)new matteparams(this);
    addCommand(0x31,tmpCmd);
    addCommand(0xb1,tmpCmd);

    tmpCmd = (command*)new matteparams(this);
    addCommand(0x32,tmpCmd);
    addCommand(0xb2,tmpCmd);

}
