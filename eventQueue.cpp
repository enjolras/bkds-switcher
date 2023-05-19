#include "eventQueue.h"
#include "event.h"

eventQueue::eventQueue() {

}

void eventQueue::addNode(node* nodeName) {
	nodes_[nodeName->nodeId()] = nodeName;
}

void eventQueue::addEvent(event* newEvent) {
	events_.push(newEvent) ;
}

void eventQueue::propagate() {

}
