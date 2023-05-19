#ifndef BKDSOBS_H
#define BKDSOBS_H

#include "../../node.h"
#include "../../event.h"

class obsConn;

class bkdsobs : public node {
public:
	bkdsobs(eventQueue *eventQ);
	void run();
	void execEvent(event &ev);

private:
	obsConn* obs_;
	eventQueue* eventQ_;
};

#endif
