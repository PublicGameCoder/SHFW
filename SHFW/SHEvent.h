#ifndef SHEVENT_H
#define SHEVENT_H

#include <map>

enum EventType {
	UNKNOWN,
	EnumWindowResizeEvent,
	EnumScrollEvent
};

class Event {
public:

	Event() {
		_type = EventType::UNKNOWN;
	}

	virtual ~Event() {

	}

	EventType getType() {
		return _type;
	}

protected:
	EventType _type;
};

#endif // !SHEVENT_H
