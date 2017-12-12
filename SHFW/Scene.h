#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"

class Scene : public Entity
{
public:
	Scene();
	virtual ~Scene();

	bool isRunning() { return this->Scene::running; };

	void setRunning(bool state) { this->Scene::running = state; };

	void update();

private:
	void updateEntity(Entity* entity);

	bool running;
};

#endif // !SCENE_H
