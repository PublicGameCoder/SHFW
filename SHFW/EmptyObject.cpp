#include "EmptyObject.h"

EmptyObject::EmptyObject() : Entity() {

}

EmptyObject::~EmptyObject() {

}
static float size = 0;
void EmptyObject::update() {
	size += Time::deltaTime;
	float scl = Math::map(sin(size),0, 1, 1, 2);
	this->scale.x = scl;
	this->scale.y = scl;
}