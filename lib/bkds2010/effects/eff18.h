#ifndef EFF18_H
#define EFF18_H

#include "effect.h"

class eff18 : public effect {
public:
	eff18(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
