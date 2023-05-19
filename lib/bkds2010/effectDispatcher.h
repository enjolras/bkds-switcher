#ifndef EFFECTDISPATCHER_H
#define EFFECTDISPATCHER_H

#include <map>
#include <string>

class connectionHandler;
class effect;
class response;
class event;

class effectDispatcher {
public:
	effectDispatcher(connectionHandler*);
	connectionHandler* conn();
	void addEffect(effect*);
	void addEvent(event&);
	void exec();
	void init();
	void addResponse(response&);

private:
	connectionHandler* conn_;
	std::map<unsigned char,effect*> effects_;
};

#endif
