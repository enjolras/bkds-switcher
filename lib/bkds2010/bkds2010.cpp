#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "ping.h"
#include "select_xpt.h"
#include "tbar.h"
#include "key.h"
#include "auto_rate.h"
#include "eventmem.h"
#include "wipe.h"
#include "trans.h"
#include "dsk.h"
#include "eff00_13.h"
#include "eff01_a1.h"
#include "eff01_9c.h"
#include "eff01_8a.h"
#include "effect_keyer.h"
#include "effect_matte.h"
#include "effect_chr.h"
#include "eff25_82.h"
#include "eff2e_86.h"
#include "enable.h"
#include "sysinfo.h"
#include "setup_systm.h"
#include "wipepos.h"
#include "wipeparams.h"
#include "mixparams.h"
#include "matteparams.h"
#include "gpiin.h"
#include "util.h"

void init_effects(effectDispatcher*,connectionHandler*);

int start() {

	connectionHandler *conn = new connectionHandler();
	effectDispatcher *effDisp = new effectDispatcher(conn);

	init_effects(effDisp,conn);
	conn->connect();

	while(true) {
		effDisp->exec();
		conn->commitResponses();
	}

	return 0;
}

void init_effects(effectDispatcher *effDisp, connectionHandler *conn) {

	effect *tmpEff;
	command *tmpCmd;

	tmpEff = new effect(EFF_PPROW,conn);
	tmpEff->setName("PP ROW");

	tmpCmd = (command*)new select_xpt(conn,tmpEff);
	tmpEff->addCommand(0x07,tmpCmd);
	tmpEff->addCommand(0x87,tmpCmd);

	tmpCmd = (command*)new eff00_13(conn,tmpEff);
	tmpEff->addCommand(0x13,tmpCmd);

	tmpCmd = (command*)new key(conn,tmpEff);
	tmpEff->addCommand(0x1a,tmpCmd);
	tmpEff->addCommand(0x9a,tmpCmd);
	tmpEff->addCommand(0xda,tmpCmd);

	tmpCmd = (command*)new auto_rate(conn,tmpEff);
	tmpEff->addCommand(0x18,tmpCmd);
	tmpEff->addCommand(0x98,tmpCmd);

	tmpCmd = (command*)new dsk(conn,tmpEff);
	tmpEff->addCommand(0x90,tmpCmd);
	tmpEff->addCommand(0x93,tmpCmd);
	tmpEff->addCommand(0xd3,tmpCmd);

	tmpCmd = (command*)new matteparams(conn,tmpEff);
	tmpEff->addCommand(0x31,tmpCmd);
	tmpEff->addCommand(0xb1,tmpCmd);
	effDisp->addEffect(tmpEff);

	tmpCmd = (command*)new matteparams(conn,tmpEff);
	tmpEff->addCommand(0x32,tmpCmd);
	tmpEff->addCommand(0xb2,tmpCmd);
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_ME1ROW,conn);
	tmpEff->setName("ME1 ROW");

	tmpCmd = (command*)new select_xpt(conn,tmpEff);
	tmpEff->addCommand(0x00,tmpCmd);	// READ XPT PGM BUS
	tmpEff->addCommand(0x80,tmpCmd);	// WRITE XPT PGM BUS
	tmpEff->addCommand(0x01,tmpCmd);	// READ XPT PST BUS
	tmpEff->addCommand(0x81,tmpCmd);	// WRITE XPT PST BUS
	tmpEff->addCommand(0x07,tmpCmd);	// READ XPT KEY1 BUS
	tmpEff->addCommand(0x87,tmpCmd);	// WRITE XPT KEY1 BUS
	tmpEff->addCommand(0x0d,tmpCmd);	// READ XPT KEY2 BUS
	tmpEff->addCommand(0x8d,tmpCmd);	// WRITE XPT KEY2 BUS

	tmpCmd = (command*) new util(conn,tmpEff);
	tmpEff->addCommand(0x0f,tmpCmd);
	tmpEff->addCommand(0x8f,tmpCmd);

	tmpCmd = (command*)new trans(conn,tmpEff);
	tmpEff->addCommand(0x10,tmpCmd);
	tmpEff->addCommand(0x90,tmpCmd);
	tmpEff->addCommand(0x11,tmpCmd);
	tmpEff->addCommand(0x91,tmpCmd);

	tmpCmd = (command*)new auto_rate(conn,tmpEff);
	tmpEff->addCommand(0x18,tmpCmd);
	tmpEff->addCommand(0x98,tmpCmd);

	tmpCmd = (command*)new eff01_a1(conn,tmpEff);
	tmpEff->addCommand(0x21,tmpCmd);
	tmpEff->addCommand(0xa1,tmpCmd);

	tmpCmd = (command*)new eff01_9c(conn,tmpEff);
	tmpEff->addCommand(0x1c,tmpCmd);
	tmpEff->addCommand(0x9c,tmpCmd);

	tmpCmd = (command*)new eff01_8a(conn,tmpEff);
	tmpEff->addCommand(0x0a,tmpCmd);
	tmpEff->addCommand(0x8a,tmpCmd);

	tmpCmd = (command*)new key(conn,tmpEff);
	tmpEff->addCommand(0x1a,tmpCmd);
	tmpEff->addCommand(0x9a,tmpCmd);
	tmpEff->addCommand(0xda,tmpCmd);

	tmpCmd = (command*)new wipe(conn,tmpEff);
	tmpEff->addCommand(0x1b,tmpCmd);
	tmpEff->addCommand(0x9b,tmpCmd);
	tmpEff->addCommand(0xdb,tmpCmd);

	tmpCmd = (command*)new wipepos(conn,tmpEff);
	tmpEff->addCommand(0x29,tmpCmd);
	tmpEff->addCommand(0xa9,tmpCmd);

	tmpCmd = (command*)new wipeparams(conn,tmpEff);
	tmpEff->addCommand(0x2b,tmpCmd);
	tmpEff->addCommand(0xab,tmpCmd);

	tmpCmd = (command*)new mixparams(conn,tmpEff);
	tmpEff->addCommand(0x2f,tmpCmd);
	tmpEff->addCommand(0xaf,tmpCmd);

	tmpCmd = (command*)new matteparams(conn,tmpEff);
	tmpEff->addCommand(0x30,tmpCmd);
	tmpEff->addCommand(0xb0,tmpCmd);

	tmpCmd = (command*)new matteparams(conn,tmpEff);
	tmpEff->addCommand(0x31,tmpCmd);
	tmpEff->addCommand(0xb1,tmpCmd);

	tmpCmd = (command*)new matteparams(conn,tmpEff);
	tmpEff->addCommand(0x32,tmpCmd);
	tmpEff->addCommand(0xb2,tmpCmd);

	tmpCmd = (command*)new matteparams(conn,tmpEff);
	tmpEff->addCommand(0x37,tmpCmd);
	tmpEff->addCommand(0xb7,tmpCmd);

	tmpCmd = (command*)new matteparams(conn,tmpEff);
	tmpEff->addCommand(0x39,tmpCmd);
	tmpEff->addCommand(0xb9,tmpCmd);

	tmpCmd = (command*)new matteparams(conn,tmpEff);
	tmpEff->addCommand(0x3a,tmpCmd);
	tmpEff->addCommand(0xba,tmpCmd);

	tmpCmd = (command*)new tbar(conn,tmpEff);
	tmpEff->addCommand(0xa8,tmpCmd);

	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_10_UNK,conn);
	tmpEff->setName("EFF10 UNK");

	tmpCmd = (command*)new effect_chr(conn,tmpEff);
	tmpEff->addCommand(0x1a,tmpCmd);
	tmpEff->addCommand(0x9a,tmpCmd);

	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_FRMEM1,conn);
	tmpEff->setName("FRMEM1");
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_FRMEM2,conn);
	tmpEff->setName("FRMEM2");
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_MATTE,conn);
	tmpEff->setName("MATTE");
    tmpCmd = (command*)new matteparams(conn,tmpEff);
    tmpEff->addCommand(0x2a,tmpCmd);
    tmpEff->addCommand(0xaa,tmpCmd);

	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_VPROC,conn);
	tmpEff->setName("VPROC");
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_CCR,conn);
	tmpEff->setName("CCR");
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_SYSCTRL,conn);
	tmpEff->setName("SYSTEM CONTROL");

	tmpCmd = (command*)new enable(conn,tmpEff);
	tmpEff->addCommand(0x00,tmpCmd);
	tmpEff->addCommand(0x80,tmpCmd);

	tmpCmd = (command*)new sysinfo(conn,tmpEff);
	tmpEff->addCommand(0x10,tmpCmd);
	tmpEff->addCommand(0x90,tmpCmd);

	tmpCmd = (command*)new effect_keyer(conn,tmpEff);
	tmpEff->addCommand(0x13,tmpCmd);
	tmpEff->addCommand(0x93,tmpCmd);

	tmpCmd = (command*)new effect_matte(conn,tmpEff);
	tmpEff->addCommand(0x16,tmpCmd);
	tmpEff->addCommand(0x96,tmpCmd);

	tmpCmd = (command*)new gpiin(conn,tmpEff);
	tmpEff->addCommand(0x17,tmpCmd);
	tmpEff->addCommand(0x97,tmpCmd);

	tmpCmd = (command*)new setup_systm(conn,tmpEff);
	tmpEff->addCommand(0x11,tmpCmd);
	tmpEff->addCommand(0x91,tmpCmd);

	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_EVENTMEM,conn);
	tmpEff->setName("EVENT MEMORY");
	tmpCmd = (command*)new eventmem(conn,tmpEff);
	tmpEff->addCommand(0x88,tmpCmd);
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_PRGPGM,conn);
	tmpEff->setName("PROGRAM FIRMWARE");
	tmpCmd = (command*)new eff2e_86(conn,tmpEff);
	tmpEff->addCommand(0x06,tmpCmd);
	tmpEff->addCommand(0x86,tmpCmd);
	tmpEff->addCommand(0x00,tmpCmd);
	tmpEff->addCommand(0x80,tmpCmd);
	tmpEff->addCommand(0x03,tmpCmd);
	tmpEff->addCommand(0x83,tmpCmd);
	effDisp->addEffect(tmpEff);

	tmpEff = new effect(0x25,conn);
	tmpCmd = (command*) new eff25_82(conn,tmpEff);
	tmpEff->addCommand(0x82,tmpCmd);
	tmpEff->addCommand(0x80,tmpCmd);
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_AUX1,conn);
	tmpEff->setName("AUX 1");
	tmpCmd = (command*)new select_xpt(conn,tmpEff);
	tmpEff->addCommand(0x00,tmpCmd);		// READ XPT AUX1
	tmpEff->addCommand(0x80,tmpCmd);		// WRITE XPT AUX1
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_AUX2,conn);
	tmpEff->setName("AUX 2");
	tmpCmd = (command*)new select_xpt(conn,tmpEff);
	tmpEff->addCommand(0x00,tmpCmd);		// READ XPT AUX2
	tmpEff->addCommand(0x80,tmpCmd);		// WRITE XPT AUX2
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_AUX3,conn);
	tmpEff->setName("AUX 3");
	tmpCmd = (command*)new select_xpt(conn,tmpEff);
	tmpEff->addCommand(0x00,tmpCmd);		// READ XPT AUX3
	tmpEff->addCommand(0x80,tmpCmd);		// WRITE XPT AUX3
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_AUX4,conn);
	tmpEff->setName("AUX 4");
	tmpCmd = (command*)new select_xpt(conn,tmpEff);
	tmpEff->addCommand(0x00,tmpCmd);		// READ XPT AUX4
	tmpEff->addCommand(0x80,tmpCmd);		// WRITE XPT AUX4
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_AUX5,conn);
	tmpEff->setName("AUX 5");
	tmpCmd = (command*)new select_xpt(conn,tmpEff);
	tmpEff->addCommand(0x00,tmpCmd);		// READ XPT AUX5
	tmpEff->addCommand(0x80,tmpCmd);		// WRITE XPT AUX5
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_AUX6,conn);
	tmpEff->setName("AUX 6");
	tmpCmd = (command*)new select_xpt(conn,tmpEff);
	tmpEff->addCommand(0x00,tmpCmd);		// READ XPT AUX6
	tmpEff->addCommand(0x80,tmpCmd);		// WRITE XPT AUX6
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_EDITPVW,conn);
	tmpEff->setName("EDIT PVW");
	tmpCmd = (command*)new select_xpt(conn,tmpEff);
	tmpEff->addCommand(0x00,tmpCmd);		// READ XPT EDITPVW
	tmpEff->addCommand(0x80,tmpCmd);		// WRITE XPT EDITPVW
	effDisp->addEffect(tmpEff);


	tmpEff = new effect(EFF_PING,conn);
	tmpEff->setName("PING");
	tmpCmd = (command*)new ping(conn,tmpEff);		// PING
	tmpEff->addCommand(0x80,tmpCmd);
	effDisp->addEffect(tmpEff);

}
