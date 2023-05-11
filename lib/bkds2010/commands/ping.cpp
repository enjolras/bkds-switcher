#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "ping.h"

using namespace std;

ping::ping(connectionHandler *conn, effect *eff) : command(conn, eff) {

}

void ping::exec(unsigned char *nextCommand) {

}
