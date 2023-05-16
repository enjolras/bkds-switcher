#ifndef EFFECT_H
#define EFFECT_H

#include <map>
#include <string>
#include <memory>

class effectDispatcher;
class command;

class effect {
public:
	effect(unsigned char,std::shared_ptr<effectDispatcher> const&);
	void exec(unsigned char*);
	void addCommand(unsigned char,std::shared_ptr<command>);
	std::string name();
	unsigned char whoAmI();

protected:
	std::shared_ptr<effectDispatcher> effDisp();
	void setName(std::string);

private:
	std::shared_ptr<effectDispatcher> effDisp_;
	std::string name_;
	unsigned char eff_;
	std::map<unsigned char,std::shared_ptr<command> > commands_;
};

#endif
