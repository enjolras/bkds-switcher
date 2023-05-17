#ifndef BKDS2010_H
#define BKDS2010_H

class connectionHandler;
class effectDispatcher;

class bkds2010 {
public:
	bkds2010();
	void run();
	void execEvent();

private:
	connectionHandler* conn_;
	effectDispatcher* effDisp_;
};

#endif
