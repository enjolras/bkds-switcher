#ifndef EFFECT_H
#define EFFECT_H

#include <map>
#include <string>

class connectionHandler;
class effect;

class command {
public:
	effect(connectionHandler*);
	virtual void exec(unsigned char*) = 0;

protected:
	connectionHandler* conn();

private:
	connectionHandler *conn_;
};

#endif
