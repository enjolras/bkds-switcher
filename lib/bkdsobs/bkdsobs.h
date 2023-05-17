#ifndef BKDSOBS_H
#define BKDSOBS_H

class obsConn;

class bkdsobs {
public:
	bkdsobs();
	void run();
	void execEvent();

private:
	obsConn* obs_;
};

#endif
