#include "Entity.h"

Entity::Entity() {
	this->_input = InputManager::getManager();
}

Entity::~Entity() {
	for each (Entity* child in childs) {
		delete child;
	}
}

void Entity::update() {

}

void Entity::addSprite(std::string file_path) {
	this->sprite = new Sprite(file_path);
}