#ifndef EVENT_H
#define EVENT_H

#define SET_CURRENT_PGM		0x00
#define SET_CURRENT_PVW		0x01

class event {
public:
	event(unsigned char,unsigned char);
	unsigned char sender();
	unsigned char type();
	unsigned char *params();

private:
	unsigned char sender_;
	unsigned char type_;
	unsigned char params_[256];
};

#endif
