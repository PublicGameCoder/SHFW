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
	void addNewListener(void(*functionListener)(), EventType eventType);
	void call(Event &e);
private:
	static EventHandler* instance;
	std::map<EventType, void(*)()> _listeners;
};
#endif // !SHEVENTHANDLER_H
