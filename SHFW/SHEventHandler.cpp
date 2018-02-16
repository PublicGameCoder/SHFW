#include "SHEventHandler.h"
#include "SHEventListener.h"

EventHandler* EventHandler::instance = NULL;

EventHandler::EventHandler() {

}

EventHandler::~EventHandler() {

}

void EventHandler::addNewListener(void(*functionListener)(), EventType eventType) {
	std::pair<EventType, void(*)()> entry1 = std::pair<EventType, void(*)()>(eventType, functionListener);
	this->_listeners.insert(entry1);
}



void EventHandler::call(Event &e) {
	std::map<EventType, void(*)()>::iterator it = this->_listeners.begin();
	while (it != _listeners.end()) {
		EventType et = it->first;
		if (et != EventType::UNKNOWN && et == e.getType()) {
			void(*foo)() = it->second;

			void(*f)(Event) = (void(*)(Event)) foo;
			f(e);
		}
		++it;
	}
}