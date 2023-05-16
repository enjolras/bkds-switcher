#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory>
#include "connectionHandler.h"
#include "effectDispatcher.h"

int start() {

	std::shared_ptr<connectionHandler> conn = std::make_shared<connectionHandler>();
	std::shared_ptr<effectDispatcher> effDisp = std::make_shared<effectDispatcher>(conn);

	conn->connect();

	while(true) {
		effDisp->exec();
		conn->commitResponses();
	}

	return 0;
}
