#ifndef GPIIN_H
#define GPIIN_H

#include "command.h"


class effect;

class gpiin : public command {
public:
    gpiin(std::shared_ptr<effect>);
    void exec(unsigned char*);

private:
	unsigned char status00[0x0a][2];
	unsigned char status03[4];
	unsigned char status08[6][6];
};

#endif
