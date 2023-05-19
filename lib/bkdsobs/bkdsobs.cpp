#include <json/json.h>
#include "obsConn.h"
#include "bkdsobs.h"
#include "../../eventQueue.h"

bkdsobs::bkdsobs(eventQueue* eventQ) : eventQ_(eventQ), node(eventQ) {

	setNodeId(SENDER_BKDSOBS);

	obs_ = new obsConn();

}

void bkdsobs::run() {
	obs_->run();
}

void bkdsobs::execEvent(event &ev) {

	Json::Value rootout1;
	Json::StreamWriterBuilder outbuilder;

	rootout1["op"] = 6;
	Json::Value data;
	data["requestType"] = "SetCurrentProgramScene";
	data["requestId"] = "1234";
	Json::Value requestData;
	switch(ev.params()[0]) {
		case 0x00:
			requestData["sceneName"] = "CAM1";
			break;
		case 0x01:
			requestData["sceneName"] = "CAM2";
			break;
		case 0x02:
			requestData["sceneName"] = "CAM3";
			break;
		default:
			requestData["sceneName"] = "CAM1";
	}
	data["requestData"] = requestData;
	rootout1["d"] = data;

	std::string outStr;

	outStr = Json::writeString(outbuilder, rootout1);
	obs_->send(outStr);

}
