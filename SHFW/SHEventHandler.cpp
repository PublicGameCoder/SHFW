#include "SHEventHandler.h"
#include "SHEventListener.h"

EventHandler* EventHandler::instance = NULL;

EventHandler::EventHandler() {

}

EventHandler::~EventHandler() {

}
void EventHandler::addNewListener(std::function< void(WindowResizeEvent)> functionListener, EventType eventType) {
	std::pair<EventType, std::function< void(WindowResizeEvent)>> entry1 = std::pair<EventType, std::function< void(WindowResizeEvent)>>(eventType, functionListener);
	this->_listeners.insert(entry1);
}



void EventHandler::call(WindowResizeEvent e) {
	std::map<EventType, std::function<void(WindowResizeEvent)>>::iterator it = this->_listeners.begin();
	while (it != _listeners.end()) {
		EventType et = it->first;
		if (et != EventType::UNKNOWN && et == e.getType()) {
			std::function<void(WindowResizeEvent)> const &f = it->second;
			f(e);
		}
		++it;
	}
}