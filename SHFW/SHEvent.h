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

	template <class T>
	Event(T* data) {
		_data = data;
		_type = EventType::UNKNOWN;
	}

	virtual ~Event() {

	}

	EventType getType() {
		return _type;
	}

	template <class T>
	const T getData() const {
		return _data;
	}

	template <class T>
	T Event::_data = NULL;


protected:
	EventType _type;
};

#endif // !SHEVENT_H
