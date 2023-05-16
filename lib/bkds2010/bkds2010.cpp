#include <cstdio>
#include <cstdbool>
#include <cstdlib>
#include <unistd.h>
#include <thread>
#include "connectionHandler.h"
#include "effectDispatcher.h"

int bkds2010_init() {

	connectionHandler* conn = new connectionHandler();
	effectDispatcher* effDisp = new effectDispatcher(conn);

	effDisp->init();
	conn->connect();

	std::thread effDispThr(&effectDispatcher::exec,effDisp);

	while(true) {
		conn->commitResponses();
		usleep(100);
	}

	return 0;
}
