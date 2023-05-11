#ifndef SETUP_SYSTM_H
#define SETUP_SYSTM_H

#include "command.h"

class connectionHandler;
class effect;

class setup_systm : public command {
public:
	setup_systm(connectionHandler*, effect*);
	void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif 
