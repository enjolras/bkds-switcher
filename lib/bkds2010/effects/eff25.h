#ifndef EFF25_H
#define EFF25_H

#include "effect.h"

class eff25 : public effect {
public:
	eff25(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
