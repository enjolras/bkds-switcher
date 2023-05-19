#include <cstring>
#include <cstdio>

#include "event.h"

using namespace std;

event::event(unsigned char sender, unsigned char type) : sender_(sender), type_(type) {

	memset(params_,0,sizeof(params_));

}

unsigned char event::sender() {

	return sender_;

}

unsigned char event::type() {

	return type_;

}

unsigned char *event::params() {

	return params_;

}
