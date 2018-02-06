#include "SHEventHandler.h"
#include "SHEventListener.h"

EventHandler* EventHandler::instance = NULL;

EventHandler::EventHandler() {

}

EventHandler::~EventHandler() {

}
/*
void EventHandler::addNewListener(std::function< void(Event)> functionListener, EventType eventType) {
	std::pair<EventType, std::function< void(Event)>> entry1 = std::pair<EventType, std::function< void(Event)>>(eventType, functionListener);
	this->_listeners.insert(entry1);
}*/



void EventHandler::call(Event e) {
	/*
	std::map<EventType, std::function<void(Event)>>::iterator it = this->_listeners.begin();
	while (it != _listeners.end()) {
		EventType et = it->first;
		if (et != EventType::UNKNOWN && et == e.getType()) {
			std::function<void(Event)> const &f = it->second;
			f(e);
		}
		++it;
	}
	*/
}