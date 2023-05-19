#include "node.h"
#include "eventQueue.h"
#include "event.h"

node::node(eventQueue* eventQueue) : eventQueue_(eventQueue) {

}

void node::setNodeId(unsigned char nodeId) {
	nodeId_ = nodeId;
}

unsigned char node::nodeId() {
	return nodeId_;
}

void node::execEvent(event& ev) {

}
