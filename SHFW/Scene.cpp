#include "Scene.h"

Scene::Scene(): Entity() {
	this->setRunning(true);
	//this->addSprite("assets/lilypad.tga");
}

Scene::~Scene() {
	this->setRunning(false);
}

void Scene::update() {
	if (input()->getKey(KeyCode::Esc)) {
		this->setRunning(false);
		std::cout << "Terminating.." << std::endl;
	}
}

void Scene::updateEntity(Entity* entity)
{
	entity->update();

	std::vector<Entity*> childs = entity->getChilds();
	for each (Entity* child in childs) {
		child->update();
	}
}