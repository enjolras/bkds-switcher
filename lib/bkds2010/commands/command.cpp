#include <stdio.h>
#include <iostream>
#include "../effectDispatcher.h"
#include "command.h"

using namespace std;

command::command(std::shared_ptr<effect> eff) : eff_(eff) {

}

std::shared_ptr<effect> command::eff() {
	return eff_;
}
