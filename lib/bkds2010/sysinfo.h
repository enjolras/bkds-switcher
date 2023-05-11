#ifndef SYSINFO_H
#define SYSINFO_H

#include "command.h"

class connectionHandler;
class effect;

class sysinfo : public command {
public:
	sysinfo(connectionHandler*, effect*);
	void exec(unsigned char*);
};

#endif 
