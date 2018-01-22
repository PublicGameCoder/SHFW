#ifndef SHEVENT_H
#define SHEVENT_H

enum EventType {
	UNKNOWN,
	EnumWindowResizeEvent
};

class Event {
public:
	Event();
	virtual ~Event();

	EventType getType() {
		return _type;
	}
protected:
	EventType _type;
};

#endif // !SHEVENT_H
