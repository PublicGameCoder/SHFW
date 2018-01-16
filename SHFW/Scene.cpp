#include "Scene.h"

Scene::Scene() : Entity()
{
	_camera = new Camera();

	_isRunning = true;
}

Scene::~Scene()
{
	delete _camera;
}

void Scene::updateScene()
{
	this->_updateEntity(this);

	//check for closing framework
	if (input()->getKeyDown(KeyCode::Esc)) {
		std::cout << "terminating..." << std::endl;
		this->isRunning(false);
	}
}


void Scene::_updateEntity(Entity* entity)
{
	// update entity
	entity->update();

	// update all children
	std::vector<Entity*> children = entity->children();
	std::vector<Entity*>::iterator child = children.begin();

	while (child < children.end()) {
		this->_updateEntity(*child);
		++child;
	}
}
