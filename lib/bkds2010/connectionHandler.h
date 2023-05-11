#ifndef CONNECTION_HANDLER_H
#define CONNECTION_HANDLER_H

#include <queue>
#include <string>

#define DEBUG_NC		for(int i=0;i<=nextCommand[0];i++) {printf("%02x ",nextCommand[i]);}printf("\n");

class response;
class obsConn;

class connectionHandler {
public:
	connectionHandler(obsConn*);
	unsigned char* getNextCommand();
	void addResponse(response &);
	void commitResponses();
	void connect();
	void sendToObs(std::string&);
	
private:
	int fd;
	unsigned char readBuf[256];
	std::queue<response> responses;
	int setInterfaceAttribs(int, int);
	void setBlocking(int);
	void sendAck();
	obsConn* obs_;
};

class response {
public:
	response();
	void addByte(unsigned char);
	unsigned char *getData();
	void debugResponse();

private:
	unsigned char resp_[256];
};

#endif
