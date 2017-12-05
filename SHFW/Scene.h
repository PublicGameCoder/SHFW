#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"

class Scene : public Entity
{
public:
	Scene();
	virtual ~Scene();

	bool isRunning() { return Scene::running; };

	void setRunning(bool state) { Scene::running = state; };

	void update();

private:
	void _updateEntity(Entity* entity);

	bool running;
};

#endif // !SCENE_H
