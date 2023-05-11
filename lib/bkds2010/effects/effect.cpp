#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effect.h"

using namespace std;

command::command(connectionHandler *conn) : conn_(conn) {

}

connectionHandler* command::conn() {
	return conn_;
}
