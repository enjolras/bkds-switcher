#ifndef EFFECT_KEYER_H
#define EFFECT_KEYER_H

#include "command.h"

class connectionHandler;
class effect;

class effect_keyer : public command {
public:
	effect_keyer(connectionHandler*, effect*);
	void exec(unsigned char*);

private:
	unsigned char config_[256][256];
};

#endif 
