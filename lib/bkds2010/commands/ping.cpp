#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "ping.h"

using namespace std;

ping::ping(std::shared_ptr<effect> eff) : command(eff) {

}

void ping::exec(unsigned char *nextCommand) {

}
