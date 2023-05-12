#ifndef EFFECT_MATTE_H
#define EFFECT_MATTE_H

#include "command.h"


class effect;

class effect_matte : public command {
public:
	effect_matte(std::shared_ptr<effect>);
	void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif 
