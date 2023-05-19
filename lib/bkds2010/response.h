#ifndef RESPONSE_H
#define RESPONSE_H

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
