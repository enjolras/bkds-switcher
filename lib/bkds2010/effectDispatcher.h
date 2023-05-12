#ifndef EFFECTDISPATCHER_H
#define EFFECTDISPATCHER_H

#include <map>
#include <string>
#include <memory>

class connectionHandler;
class effect;

class effectDispatcher {
public:
	effectDispatcher(std::shared_ptr<connectionHandler>);
	std::shared_ptr<connectionHandler> conn();
	void addEffect(std::shared_ptr<effect>);
	void exec();

private:
	std::shared_ptr<connectionHandler> conn_;
	std::map<unsigned char,std::shared_ptr<effect> > effects_;
};

#endif
