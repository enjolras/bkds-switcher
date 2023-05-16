#ifndef SYSINFO_H
#define SYSINFO_H

#include "command.h"

class sysinfo : public command {
public:
	sysinfo(effect*);
	void exec(unsigned char*);
};

#endif 
