#ifndef NODE_H
#define NODE_H

#define SENDER_BKDS2010		0x00
#define SENDER_BKDSOBS		0x01

class event;
class eventQueue;

class node {
public:
	node(eventQueue*);
	void setNodeId(unsigned char);
	unsigned char nodeId();
	eventQueue* eventQ();
	virtual void execEvent(event&);

private:
	eventQueue* eventQueue_;
	unsigned char nodeId_;
};

#endif
