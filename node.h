#ifndef NODE_H
#define NODE_H

#define SENDER_BKDS2010		0x00
#define SENDER_BKDSOBS		0x01

class event;

class node {
public:
	node();
	void setNodeId(unsigned char);
	unsigned char nodeId();
	virtual void execEvent(event*) = 0;

private:
	unsigned char nodeId_;
};

#endif
