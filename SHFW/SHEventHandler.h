#ifndef SHEVENTHANDLER_H
#define SHEVENTHANDLER_H

class EventListener;

#include <map>

#include "SHEvent.h"
#include "WindowResizeEvent.h"
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
	void addNewListener(std::function<void(WindowResizeEvent)> functionListener, EventType eventType);
	void call(WindowResizeEvent e);
private:
	static EventHandler* instance;
	std::map<EventType, std::function<void(WindowResizeEvent)>> _listeners;
};
#endif // !SHEVENTHANDLER_H
