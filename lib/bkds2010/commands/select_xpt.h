#ifndef SELECT_XPT_H
#define SELECT_XPT_H

#include "command.h"

class select_xpt : public command {
public:
	select_xpt(effect*);
	void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
