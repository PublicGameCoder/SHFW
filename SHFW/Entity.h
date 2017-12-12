#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include "Sprite.h"
#include "InputManager.h"
class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual void update();
	std::vector<Entity*> getChilds() {
		return this->childs;
	}
	Sprite* getSprite() { return this->sprite; }
	void addSprite(std::string file_path);
private:
	std::vector<Entity*> childs;
	InputManager* _input;
	Sprite* sprite;
protected:
	InputManager* input() { return this->_input; };
};

#endif // !ENTITY_H
