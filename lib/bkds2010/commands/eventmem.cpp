#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "eventmem.h"

using namespace std;

eventmem::eventmem(std::shared_ptr<effect> eff) : command(eff) {

}

void eventmem::exec(unsigned char *nextCommand) {

}
