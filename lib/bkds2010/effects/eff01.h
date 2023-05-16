#ifndef EFF01_H
#define EFF01_H

#include "effect.h"

class eff01 : public effect {
public:
	eff01(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
