#ifndef SYSINFO_H
#define SYSINFO_H

#include "command.h"


class effect;

class sysinfo : public command {
public:
	sysinfo(std::shared_ptr<effect>);
	void exec(unsigned char*);
};

#endif 
