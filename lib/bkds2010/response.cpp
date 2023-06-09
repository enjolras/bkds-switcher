#include <cstring>
#include <cstdio>

#include "response.h"

using namespace std;

response::response() {

	memset(resp_,0,sizeof(resp_));

}

void response::addByte(unsigned char byte) {

	resp_[0]++;
	resp_[resp_[0]] = byte;

}

unsigned char* response::getData() {
	return resp_;
}

void response::debugResponse() {
	printf("RESPONSE: ");
	for(int i=0;i<=getData()[0];i++) {
		printf("%02x ",getData()[i]);
	}
	printf("\n");
}
