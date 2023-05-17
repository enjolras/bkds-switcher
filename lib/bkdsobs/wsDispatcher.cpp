#include <iostream>
#include <json/json.h>
#include "wsDispatcher.h"

using namespace std;

wsDispatcher::wsDispatcher() {

}

void wsDispatcher::exec(std::string inStr, std::string& outStr) {

	Json::Value root;
	Json::Value rootOut;
	Json::CharReaderBuilder builder;
	const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
	JSONCPP_STRING err;
	const auto rawJsonLength = static_cast<int>(inStr.length());
	Json::StreamWriterBuilder outbuilder;

	reader->parse(inStr.c_str(), inStr.c_str() + rawJsonLength, &root, &err);

	switch(root["op"].asInt()) {
		case 0:
			rootOut["op"] = 1;
			Json::Value data;
			data["rpcVersion"] = 1;
			rootOut["d"] = data;
			break;
	}

	outStr = Json::writeString(outbuilder, rootOut);

}
