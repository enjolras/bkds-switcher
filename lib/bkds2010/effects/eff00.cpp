#include "eff00.h"
#include "eff00_cmds.h"

eff00::eff00(unsigned char eff,std::shared_ptr<effectDispatcher> const& effDisp) : effect(eff,effDisp) {

}
