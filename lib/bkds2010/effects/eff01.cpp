#include "eff01.h"
#include "eff_defines.h"
#include "eff01_cmds.h"
#include "../commands/select_xpt.h"
#include "../commands/key.h"
#include "../commands/auto_rate.h"
#include "../commands/dsk.h"
#include "../commands/matteparams.h"
#include "../commands/util.h"
#include "../commands/trans.h"
#include "../commands/eff01_a1.h"
#include "../commands/eff01_9c.h"
#include "../commands/eff01_8a.h"
#include "../commands/finekey.h"
#include "../commands/wipe.h"
#include "../commands/wipepos.h"
#include "../commands/wipeparams.h"
#include "../commands/mixparams.h"
#include "../commands/tbar.h"

eff01::eff01(unsigned char eff,effectDispatcher* effDisp) : effect(eff,effDisp) {

	setName("ME1ROW");

	command* tmpCmd;

	tmpCmd = (command*)new select_xpt(this);
    addCommand(0x00,tmpCmd);    // READ XPT PGM BUS
    addCommand(0x80,tmpCmd);    // WRITE XPT PGM BUS
    addCommand(0x01,tmpCmd);    // READ XPT PST BUS
    addCommand(0x81,tmpCmd);    // WRITE XPT PST BUS
    addCommand(0x07,tmpCmd);    // READ XPT KEY1 BUS
    addCommand(0x87,tmpCmd);    // WRITE XPT KEY1 BUS
    addCommand(0x0d,tmpCmd);    // READ XPT KEY2 BUS
    addCommand(0x8d,tmpCmd);    // WRITE XPT KEY2 BUS

    tmpCmd = (command*) new util(this);
    addCommand(0x0f,tmpCmd);
    addCommand(0x8f,tmpCmd);

    tmpCmd = (command*)new trans(this);
    addCommand(0x10,tmpCmd);
    addCommand(0x90,tmpCmd);
    addCommand(0x11,tmpCmd);
    addCommand(0x91,tmpCmd);

    tmpCmd = (command*)new auto_rate(this);
    addCommand(0x18,tmpCmd);
    addCommand(0x98,tmpCmd);

	tmpCmd = (command*)new finekey(this);
	addCommand(0x2c,tmpCmd);
	addCommand(0xac,tmpCmd);

    tmpCmd = (command*)new eff01_a1(this);
    addCommand(0x21,tmpCmd);
    addCommand(0xa1,tmpCmd);

    tmpCmd = (command*)new eff01_9c(this);
    addCommand(0x1c,tmpCmd);
    addCommand(0x9c,tmpCmd);

    tmpCmd = (command*)new eff01_8a(this);
    addCommand(0x0a,tmpCmd);
    addCommand(0x8a,tmpCmd);

    tmpCmd = (command*)new key(this);
    addCommand(0x1a,tmpCmd);
    addCommand(0x9a,tmpCmd);
    addCommand(0xda,tmpCmd);

    tmpCmd = (command*)new wipe(this);
    addCommand(0x1b,tmpCmd);
    addCommand(0x9b,tmpCmd);
    addCommand(0xdb,tmpCmd);

    tmpCmd = (command*)new wipepos(this);
    addCommand(0x29,tmpCmd);
    addCommand(0xa9,tmpCmd);

    tmpCmd = (command*)new wipeparams(this);
    addCommand(0x2b,tmpCmd);
    addCommand(0xab,tmpCmd);

    tmpCmd = (command*)new mixparams(this);
    addCommand(0x2f,tmpCmd);
    addCommand(0xaf,tmpCmd);

    tmpCmd = (command*)new matteparams(this);
    addCommand(0x30,tmpCmd);
    addCommand(0xb0,tmpCmd);

    tmpCmd = (command*)new matteparams(this);
    addCommand(0x31,tmpCmd);
    addCommand(0xb1,tmpCmd);

    tmpCmd = (command*)new matteparams(this);
    addCommand(0x32,tmpCmd);
    addCommand(0xb2,tmpCmd);

    tmpCmd = (command*)new matteparams(this);
    addCommand(0x37,tmpCmd);
    addCommand(0xb7,tmpCmd);

    tmpCmd = (command*)new matteparams(this);
    addCommand(0x39,tmpCmd);
    addCommand(0xb9,tmpCmd);

    tmpCmd = (command*)new matteparams(this);
    addCommand(0x3a,tmpCmd);
    addCommand(0xba,tmpCmd);

    tmpCmd = (command*)new tbar(this);
    addCommand(0xa8,tmpCmd);

}
