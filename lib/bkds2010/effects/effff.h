#ifndef EFFFF_H
#define EFFFF_H

#include "effect.h"

class effff : public effect {
public:
	effff(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
