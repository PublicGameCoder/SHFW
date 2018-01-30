#include "Core.h"
#include "PreviewScene.h"
#include "StandardAssets.h"
#include <iostream>
#include "TargetTexture.h"

int main()
{
	Core core;

	TargetTexture* t = new TargetTexture();

	PreviewScene* scene = new PreviewScene();
	EmptyObject* obj = new EmptyObject();
	//obj->addSprite("assets/default.tga");
	obj->addSprite("assets/pencils.tga");
	scene->addChild(obj);
	obj->position.x += 200;
	obj->position.y += 200;

	while (scene->isRunning())
	{
		core.run(scene);
		if (InputManager::getManager()->getKey(Down)) {
			scene->camera()->position.y -= 200 * Time::deltaTime;
		}
		if (InputManager::getManager()->getKey(Up)) {
			scene->camera()->position.y += 200 * Time::deltaTime;
		}
		if (InputManager::getManager()->getKey(Right)) {
			//scene->camera()->position.x += 200 * Time::deltaTime;
			scene->camera()->position.x += 200 * Time::deltaTime;
		}
		if (InputManager::getManager()->getKey(Left)) {
			//scene->camera()->position.x -= 200 * Time::deltaTime;
			scene->camera()->position.x -= 200 * Time::deltaTime;
		}
		static double prevMouseX = 0;
		static double prevMouseY = 0;
		double mouseX = InputManager::getManager()->getMouseX();
		double mouseY = InputManager::getManager()->getMouseY();
		if (InputManager::getManager()->getMouse(1)) {
			if (prevMouseX != mouseX || prevMouseY != mouseY) {
				scene->camera()->rotation.y -= (mouseX - prevMouseX) * Time::deltaTime;
				scene->camera()->rotation.x -= (mouseY - prevMouseY) * Time::deltaTime;
			}
		}
		prevMouseX = mouseX;
		prevMouseY = mouseY;
	}

	return 0;
}