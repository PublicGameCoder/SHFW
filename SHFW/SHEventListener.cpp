#include "SHEventListener.h"
#include "SHEventHandler.h"

	EventListener::EventListener() {
		_handler = EventHandler::getManager();
	}

	EventListener::~EventListener() {

	}
	/*
	void EventListener::registerEvents(std::function<void(Event)>&& functionListener, EventType eventType) {
		_handler->addNewListener(functionListener, eventType);
	}*/