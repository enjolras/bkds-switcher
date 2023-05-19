#include "node.h"

node::node() {

}

void node::setNodeId(unsigned char nodeId) {
	nodeId_ = nodeId;
}

unsigned char node::nodeId() {
	return nodeId_;
}
