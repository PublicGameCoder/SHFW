#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include "Camera.h"

class Scene: public Entity
{
public:
	Scene();
	virtual ~Scene();

	bool isRunning() { return _isRunning; };
	void isRunning(bool newState) { _isRunning = newState; };

	Camera* camera() { return _camera; };

	void updateScene();

private:
	void _updateEntity(Entity* entity);

	Camera* _camera;

	bool _isRunning;
};

#endif /* SCENE_H */
