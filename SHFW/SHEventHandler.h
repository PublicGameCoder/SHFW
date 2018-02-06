#ifndef SHEVENTHANDLER_H
#define SHEVENTHANDLER_H

class EventListener;

#include <map>
#include "SHEvents.h"
#include <functional>
#include <iostream>

class EventHandler {
public:
	static EventHandler* getManager() {
		if (EventHandler::instance == NULL) {
			EventHandler::instance = new EventHandler();
		}
		return EventHandler::instance;
	}
	EventHandler();
	virtual ~EventHandler();
	//void addNewListener(std::function<void(Event)> functionListener, EventType eventType);
	void call(Event e);
private:
	static EventHandler* instance;
	std::map<EventType, std::function<void(Event)>> _listeners;
};
#endif // !SHEVENTHANDLER_H
