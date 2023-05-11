#ifndef SELECT_XPT_H
#define SELECT_XPT_H

#include <map>
#include "command.h"

class connectionHandler;
class effect;

class select_xpt : public command {
public:
	select_xpt(connectionHandler*, effect*);
	void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
