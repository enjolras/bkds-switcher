#include "command.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

command::command(effect* eff) : eff_(eff) {
}

effect* command::eff() {
	return eff_;
}
