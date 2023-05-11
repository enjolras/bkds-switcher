#include <stdio.h>
#include <iostream>
#include <sstream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "tbar.h"

using namespace std;

tbar::tbar(connectionHandler *conn, effect *eff) : conn_(conn), command(conn, eff) {

}

void tbar::exec(unsigned char *nextCommand) {

	float tbarval;

	tbarval = (float)nextCommand[3]/255;

//	printf("%.4f\n",tbarval);

	std::string outStr ;
	char buff[256];
	sprintf(buff,"{\"op\":6,\"d\":{\"requestType\":\"SetTBarPosition\",\"requestId\":\"1234\",\"requestData\":{\"position\":%.4f,\"release\":false}}}",tbarval);
	outStr = buff;
	conn_->sendToObs(outStr);

//	DEBUG_NC

}
