#ifndef CONNECTION_HANDLER_H
#define CONNECTION_HANDLER_H

#include <queue>
#include <string>
#include "response.h"
#include "../../event.h"

class eventQueue;

class connectionHandler {
public:
	connectionHandler(eventQueue*);
	unsigned char* getNextCommand();
	void addResponse(response &);
	void addEvent(event&);
	void commitResponses();
	void connect();
	
private:
	int fd;
	unsigned char readBuf[256];
	std::queue<response> responses;
	int setInterfaceAttribs(int, int);
	void setBlocking(int);
	void sendAck();
	eventQueue *eventQ_;
};

#endif
