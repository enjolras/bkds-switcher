#ifndef EFFECT_H
#define EFFECT_H

#include <map>
#include <string>

class connectionHandler;
class effectDispatcher;
class command;

class effect {
public:
	effect(unsigned char,effectDispatcher*);
	void exec(unsigned char*);
	void addCommand(unsigned char,command*);
	std::string name();

protected:
	effectDispatcher* effDisp();
	void setName(std::string);

private:
	effectDispatcher *effDisp_;
	std::string name_;
	unsigned char eff_;
	std::map<unsigned char,command*> commands_;
};

#endif
