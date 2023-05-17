#include <cstdio>
#include <cstdbool>
#include <cstdlib>
#include <unistd.h>
#include <thread>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "bkds2010.h"

bkds2010::bkds2010() {

	conn_ = new connectionHandler();
	effDisp_ = new effectDispatcher(conn_);

	effDisp_->init();
	conn_->connect();
}

void bkds2010::run() {

	std::thread effDispThr(&effectDispatcher::exec,effDisp_);
	effDispThr.detach();

}

void bkds2010::execEvent() {

}
