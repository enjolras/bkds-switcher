#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "eventmem.h"

using namespace std;

eventmem::eventmem(connectionHandler *conn, effect *eff) : command(conn, eff) {

}

void eventmem::exec(unsigned char *nextCommand) {

}
