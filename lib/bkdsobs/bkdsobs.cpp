#include "obsConn.h"
#include "bkdsobs.h"

bkdsobs::bkdsobs() {

	obs_ = new obsConn();

}

void bkdsobs::run() {
	obs_->run();
}

void bkdsobs::execEvent() {

}
