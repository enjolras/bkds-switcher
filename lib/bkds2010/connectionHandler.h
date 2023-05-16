#ifndef CONNECTION_HANDLER_H
#define CONNECTION_HANDLER_H

#include <queue>
#include <string>

#define DEBUG_NC		for(int i=0;i<=nextCommand[0];i++) {printf("%02x ",nextCommand[i]);}printf("\n");

class response;

class connectionHandler {
public:
	connectionHandler();
	unsigned char* getNextCommand();
	void addResponse(response &);
	void commitResponses();
	void connect();
	
private:
	int fd;
	unsigned char readBuf[256];
	std::queue<response> responses;
	int setInterfaceAttribs(int, int);
	void setBlocking(int);
	void sendAck();
};

#endif
