#include "Core.h"
#include "PreviewScene.h"
#include "StandardAssets.h"
#include <iostream>

int main()
{
	Core core;

	PreviewScene* scene = new PreviewScene();
	EmptyObject* obj = new EmptyObject();
	obj->addSprite("assets/lilypad.tga");
	scene->addChild(obj);
	
	obj->position.x += 50;
	obj->position.y += 50;

	while (scene->isRunning())
	{
		core.run(scene);
	}

	return 0;
}