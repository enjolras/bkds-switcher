#ifndef KEY_H
#define KEY_H

#include "command.h"


class effect;

class key : public command {
public:
    key(std::shared_ptr<effect>);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
