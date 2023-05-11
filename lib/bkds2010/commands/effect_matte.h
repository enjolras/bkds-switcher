#ifndef EFFECT_MATTE_H
#define EFFECT_MATTE_H

#include "command.h"

class connectionHandler;
class effect;

class effect_matte : public command {
public:
	effect_matte(connectionHandler*, effect*);
	void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif 
