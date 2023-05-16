#ifndef EFFECT_MATTE_H
#define EFFECT_MATTE_H

#include "command.h"

class effect_matte : public command {
public:
	effect_matte(effect*);
	void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif 
