#ifndef EFF25_82_H
#define EFF25_82_H

#include "command.h"

class connectionHandler;
class effect;

class eff25_82 : public command {
public:
	eff25_82(connectionHandler*, effect*);
	void exec(unsigned char*);
};

#endif 
