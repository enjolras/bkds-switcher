#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>

class connectionHandler;
class effect;

class command {
public:
	command(connectionHandler*,effect*);
	virtual void exec(unsigned char*) = 0;

protected:
	connectionHandler* conn();
	effect* eff();

private:
	effect *eff_;
	connectionHandler *conn_;
};

#endif
