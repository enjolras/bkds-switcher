#ifndef EFF21_H
#define EFF21_H

#include "effect.h"

class eff21 : public effect {
public:
	eff21(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
