#ifndef COMMAND_H
#define COMMAND_H

class response;
class effect;

class command {
public:
	command(effect*);
	virtual void exec(unsigned char*) = 0;

protected:
	effect* eff();

private:
	effect* eff_;
};

#endif
