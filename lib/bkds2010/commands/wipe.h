#ifndef WIPE_H
#define WIPE_H

#include "command.h"


class effect;

class wipe : public command {
public:
    wipe(std::shared_ptr<effect>);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
