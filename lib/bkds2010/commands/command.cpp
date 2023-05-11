#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "command.h"

using namespace std;

command::command(connectionHandler *conn, effect *eff) : conn_(conn), eff_(eff) {

}

connectionHandler* command::conn() {
	return conn_;
}

effect* command::eff() {
	return eff_;
}
