#ifndef TBAR_H
#define TBAR_H

#include "command.h"

class connectionHandler;
class effect;

class tbar : public command {
public:
	tbar(connectionHandler*, effect*);
	void exec(unsigned char*);

private:
	connectionHandler* conn_;
};

#endif 
