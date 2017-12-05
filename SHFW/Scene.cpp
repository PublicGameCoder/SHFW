#include "Scene.h"

Scene::Scene(): Entity() {
	this->setRunning(true);
}

Scene::~Scene() {
	this->setRunning(false);
}

void Scene::update() {

}

void Scene::_updateEntity(Entity* entity)
{
	// call update() for this entity
	entity->update();

	// update() all Children (recursively)
	std::vector<Entity*> children = entity->children();
	std::vector<Entity*>::iterator child;
	for (child = children.begin(); child != children.end(); child++) {
		this->_updateEntity(*child);
	}
}