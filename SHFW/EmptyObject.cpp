#include "EmptyObject.h"

EmptyObject::EmptyObject() : Entity() {

}

EmptyObject::~EmptyObject() {

}

static float size = 0;
void EmptyObject::update() {
	size += Time::deltaTime;

	float scl = Math::map(sin(size), 0, 1, 0.5, 0.8);
	this->scale.x = scl;
	this->scale.y = scl;
	this->scale.z = scl;

	float rotSpeed = Math::map(sin(size),0, 1, -1, 1);
	this->rotation.x -= rotSpeed * Time::deltaTime;
	this->rotation.y -= rotSpeed * Time::deltaTime;
}