#include "eff10.h"
#include "eff_defines.h"
#include "eff10_cmds.h"
#include "../commands/effect_chr.h"

eff10::eff10(unsigned char eff,effectDispatcher* effDisp) : effect(eff,effDisp) {

	setName("CHRKEY");

	command* tmpCmd;

    tmpCmd = (command*)new effect_chr(this);
    addCommand(0x1a,tmpCmd);
    addCommand(0x9a,tmpCmd);

}
