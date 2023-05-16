#include "eff_aux.h"
#include "eff_defines.h"
#include "eff_aux_cmds.h"
#include "../commands/select_xpt.h"

eff_aux::eff_aux(unsigned char eff,effectDispatcher* effDisp) : effect(eff,effDisp) {

	command* tmpCmd;

    tmpCmd = (command*)new select_xpt(this);
    addCommand(0x00,tmpCmd); 
    addCommand(0x80,tmpCmd); 

}
