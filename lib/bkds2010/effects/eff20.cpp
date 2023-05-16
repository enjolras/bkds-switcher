#include "eff20.h"
#include "eff_defines.h"
#include "eff20_cmds.h"
#include "../commands/enable.h"
#include "../commands/sysinfo.h"
#include "../commands/effect_keyer.h"
#include "../commands/effect_matte.h"
#include "../commands/gpiin.h"
#include "../commands/setup_systm.h"

eff20::eff20(unsigned char eff,effectDispatcher* effDisp) : effect(eff,effDisp) {

	setName("SYSTEM CONTROL");

	command* tmpCmd;

    tmpCmd = (command*)new enable(this);
    addCommand(0x00,tmpCmd);
    addCommand(0x80,tmpCmd);

    tmpCmd = (command*)new sysinfo(this);
    addCommand(0x10,tmpCmd);
    addCommand(0x90,tmpCmd);

    tmpCmd = (command*)new effect_keyer(this);
    addCommand(0x13,tmpCmd);
    addCommand(0x93,tmpCmd);

    tmpCmd = (command*)new effect_matte(this);
    addCommand(0x16,tmpCmd);
    addCommand(0x96,tmpCmd);

    tmpCmd = (command*)new gpiin(this);
    addCommand(0x17,tmpCmd);
    addCommand(0x97,tmpCmd);

    tmpCmd = (command*)new setup_systm(this);
    addCommand(0x11,tmpCmd);
    addCommand(0x91,tmpCmd);

}
