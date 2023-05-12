#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>
#include <memory>

class effect;

class command {
public:
	command(std::shared_ptr<effect>);
	virtual void exec(unsigned char*) = 0;

protected:
	std::shared_ptr<effect> eff();

private:
	std::shared_ptr<effect> eff_;
};

#endif
