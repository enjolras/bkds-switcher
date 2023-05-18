#ifndef MATTE_COLORMIX_H
#define MATTE_COLORMIX_H

#include "command.h"

class matte_colormix : public command {
public:
    matte_colormix(effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
