#ifndef BKDS2010_H
#define BKDS2010_H

#include "../../node.h"
#include "../../event.h"

class connectionHandler;
class effectDispatcher;

class bkds2010 : public node {
public:
	bkds2010(eventQueue *eventQ);
	void run();
	void execEvent(event &ev);

private:
	connectionHandler* conn_;
	effectDispatcher* effDisp_;
	eventQueue* eventQ_;
};

#endif
