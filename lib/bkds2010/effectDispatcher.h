#ifndef EFFECTDISPATCHER_H
#define EFFECTDISPATCHER_H

#include <map>
#include <string>

class connectionHandler;
class effect;
class command;

class effect {
public:
	effect(unsigned char,connectionHandler*);
	void addCommand(unsigned char,command*);
	unsigned char myId();
	void setName(std::string);
	std::string name();
	void exec(unsigned char*);

private:
	unsigned char eff_;
	std::string name_;
	std::map<unsigned char,command*> commands_;
	connectionHandler *conn_;
};

class effectDispatcher {
public:
	effectDispatcher(connectionHandler*);
	void addEffect(effect*);
	void exec();

private:
	connectionHandler *conn_;
	std::map<unsigned char,effect*> effects_;
};

#endif
