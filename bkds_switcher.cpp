#include <iostream>
#include <unistd.h>
#include "lib/bkds2010/bkds2010.h"
#include "lib/bkdsobs/bkdsobs.h"

int main() {

	bkds2010* bkds2010_ = new bkds2010();
	bkdsobs* bkdsobs_ = new bkdsobs();

	bkds2010_->run();
	bkdsobs_->run();

	while(true) {
		usleep(100);
	}
}
