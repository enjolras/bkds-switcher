#include <stdio.h>
#include <iostream>
#include <sstream>
#include "effectDispatcher.h"
#include "tbar.h"

using namespace std;

tbar::tbar(std::shared_ptr<effect> eff) : conn_(conn), command(eff) {

}

void tbar::exec(unsigned char *nextCommand) {

	float tbarval;

	tbarval = (float)nextCommand[3]/255;

}
