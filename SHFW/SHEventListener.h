#ifndef SHEVENTLISTENER_H
#define SHEVENTLISTENER_H

class EventHandler;

#include "SHEvents.h"
#include <functional>
#include <iostream>

class EventListener{
public:
	EventListener();
	virtual ~EventListener();
protected:
	void registerEvents(void(*functionListener)(), EventType eventType);
private:
	EventHandler* _handler;
};

#endif // !SHEVENTLISTENER_H
