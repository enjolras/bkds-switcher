#ifndef EFF00_H
#define EFF00_H

#include "effect.h"

class connectionHandler*;

class eff00 : public effect {
public:
	eff00(unsigned char,connectionHandler*);
	void init();
	void exec(unsigned char*);
};

#endif
