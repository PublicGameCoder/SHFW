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
	obj->position.x = 200;
	obj->position.y = 200;

	obj->scale = Point3(.2,.2,.2);

	EmptyObject* l = new EmptyObject();
	l->addLine((new Line())->filename());
	Line* li = l->line();

	Vector3 pos1 = Vector3(0, -150);
	Vector3 pos2 = Vector3(200, -150);
	li->addPoint(pos1.x, pos1.y);
	li->addPoint(pos2.x, pos2.y);

	scene->addChild(l);

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

		static float pp = 0;
		if (InputManager::getManager()->getKey(KeyCode::Period)) {
			pp += 100 * Time::deltaTime;
		}
		if (InputManager::getManager()->getKey(KeyCode::Comma)) {
			pp -= 100 * Time::deltaTime;
		}
		static float p;
		p = pp;
		p = Math::map(p, 0, 100, 0, 1);
		p = Math::constrain(p, 0, 1);
		obj->position = Math::lerp(pos1, pos2, p);
	}

	return 0;
}