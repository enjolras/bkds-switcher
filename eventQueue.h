#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <map>
#include <queue>

class event;
class node;

class eventQueue {
public:
	eventQueue();
	void addNode(node*);
	void addEvent(event*);
	void propagate();

private:
	std::map<unsigned char,node*> nodes_;
	std::queue<event*> events_;
};

#endif
