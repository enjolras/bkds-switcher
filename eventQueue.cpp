#include <cstdio>
#include "eventQueue.h"
#include "node.h"

eventQueue::eventQueue() {

}

void eventQueue::addNode(node* nodeName) {
	nodes_[nodeName->nodeId()] = nodeName;
}

void eventQueue::addEvent(event& newEvent) {
	events_.push(newEvent) ;

	printf("---- ADDED NEW EVENT: SENDER: %02x - EVENT: %02x - PARAMS: %02x\n",newEvent.sender(),newEvent.type(),newEvent.params()[0]);

}

void eventQueue::propagate() {

	while(!events_.empty()) {
		event tmpEvent = events_.front();
		printf("---- PROPAGATING EVENT: %02x - EVENT: %02x - PARAMS: %02x\n",tmpEvent.sender(),tmpEvent.type(),tmpEvent.params()[0]);
		for(std::map<unsigned char,node*>::iterator it=nodes_.begin(); it!=nodes_.end(); it++) {
			if(tmpEvent.sender() == it->first) {
				printf("-------- NOT PROPAGATING TO %02x AS IT IS THE SENDER\n",it->first);
			} else {
				printf("-------- PROPAGATING TO %02x\n",it->first);
				it->second->execEvent(tmpEvent);
			}
		}

		events_.pop();
	}

}
