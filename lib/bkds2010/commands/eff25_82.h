#ifndef EFF25_82_H
#define EFF25_82_H

#include "command.h"

class eff25_82 : public command {
public:
	eff25_82(effect*);
	void exec(unsigned char*);
};

#endif 
