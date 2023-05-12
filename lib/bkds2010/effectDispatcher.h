#ifndef EFFECTDISPATCHER_H
#define EFFECTDISPATCHER_H

#include <map>
#include <string>

class connectionHandler;
class effect;

class effectDispatcher {
public:
	effectDispatcher(connectionHandler*);
	connectionHandler* conn();
	void addEffect(effect*);
	void exec();

private:
	connectionHandler *conn_;
	std::map<unsigned char,effect*> effects_;
};

#endif
