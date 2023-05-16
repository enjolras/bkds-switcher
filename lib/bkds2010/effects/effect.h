#ifndef EFFECT_H
#define EFFECT_H

#include <map>
#include <string>

class command;
class effectDispatcher;
class response;

class effect {
public:
	effect(unsigned char,effectDispatcher*);
	void exec(unsigned char*);
	void addCommand(unsigned char,command*);
	std::string name();
	unsigned char whoAmI();
	void addResponse(response&);
	void setName(std::string);
	effectDispatcher* effDisp();

private:
	effectDispatcher* effDisp_;
	std::string name_;
	unsigned char eff_;
	std::map<unsigned char,command*> commands_;
};

#endif
