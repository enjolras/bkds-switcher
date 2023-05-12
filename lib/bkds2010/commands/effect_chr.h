#ifndef EFFECT_CHR_H
#define EFFECT_CHR_H

#include "command.h"


class effect;

class effect_chr : public command {
public:
	effect_chr(std::shared_ptr<effect>);
	void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif 
