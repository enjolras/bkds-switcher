#include <iostream>
#include <unistd.h>
#include "lib/bkds2010/bkds2010.h"
#include "lib/bkdsobs/bkdsobs.h"
#include "eventQueue.h"

int main() {

	eventQueue* eventQ = new eventQueue();

	bkds2010* bkds2010_ = new bkds2010(eventQ);
	bkdsobs* bkdsobs_ = new bkdsobs(eventQ);

	eventQ->addNode((node *)bkds2010_);
	eventQ->addNode((node *)bkdsobs_);

	bkds2010_->run();
	bkdsobs_->run();

	while(true) {
		eventQ->propagate();
		usleep(100);
	}
}
