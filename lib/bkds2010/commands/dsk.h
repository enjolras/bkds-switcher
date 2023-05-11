#ifndef DSK_H
#define DSK_H

#include "command.h"

class connectionHandler;
class effect;

class dsk : public command {
public:
    dsk(connectionHandler*, effect*);
    void exec(unsigned char*);
};

#endif
