#include <stdio.h>
#include <iostream>
#include <sstream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "tbar.h"

using namespace std;

tbar::tbar(connectionHandler *conn, effect *eff) : conn_(conn), command(conn, eff) {

}

void tbar::exec(unsigned char *nextCommand) {

	float tbarval;

	tbarval = (float)nextCommand[3]/255;

//	DEBUG_NC

}
