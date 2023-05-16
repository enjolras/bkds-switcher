#ifndef EFF00_H
#define EFF00_H

#include "effect.h"

class eff00 : public effect {
public:
	eff00(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
