#include <iostream>

#include "Entity.h"

int Entity::_nextGuid = 0;

Entity::Entity()
{
	_guid = _nextGuid;
	_nextGuid++;

	_parent = NULL;

	position = Point3(0.0f, 0.0f, 0.0f);
	rotation = Point3(0.0f, 0.0f, 0.0f);
	scale = Point3(1.0f, 1.0f, 1.0f);

	_worldposition = Point3(0.0f, 0.0f, 0.0f);
	_worldrotation = Point3(0.0f, 0.0f, 0.0f);
	_worldscale = Point3(1.0f, 1.0f, 1.0f);

	_sprite = NULL;
	_line = NULL;
}

Entity::~Entity()
{
	//printf("Entity dtor %d\n", _guid);
	deleteSprite();
	deleteLine();
	deleteSpritebatch();
	deleteLinebatch();
}

void Entity::addChild(Entity* child)
{
	if(child->_parent != NULL) {
		child->_parent->removeChild(child);
	}
	child->_parent = this;
	this->_children.push_back(child);
}

void Entity::removeChild(Entity* child)
{
	std::vector<Entity *>::iterator it = this->_children.begin();
	while (it != _children.end()) {
		if ((*it)->_guid == child->_guid) {
			child->_parent = NULL;
			it = _children.erase(it);
		} else {
			++it;
		}
	}
}

Entity* Entity::getChild(unsigned int i)
{
	if (i < _children.size()) {
		return _children[i];
	}
	return NULL;
}

void Entity::addLine(const std::string& filename)
{
	// loaded from file: this line must be static, add to linebatch only
	Line* line = new Line(filename);
	_linebatch.push_back(*line);
}

void Entity::addLine(Line* line)
{
	// if dynamic, we want to keep a pointer to it in our _line member
	if (line->dynamic()) {
		this->deleteLine();
		_line = new Line();
		*_line = *line;
	} else {
		// this line is static, add to linebatch only
		_linebatch.push_back(*line);
	}
}

void Entity::addSprite(Sprite* spr)
{
	this->deleteSprite();
	_sprite = new Sprite();
	*_sprite = *spr;
}

void Entity::addDynamicSprite(PixelBuffer* pixels)
{
	this->deleteSprite();
	_sprite = new Sprite();
	_sprite->setupSpriteByPixelBuffer(pixels);
}

void Entity::addSprite(const std::string& filename)
{
	this->addSprite(filename, 0.5f, 0.5f);
}

void Entity::addCircleSprite(const std::string& filename, int radius, int segments)
{
	this->deleteSprite();
	_sprite = new Sprite();
	_sprite->setupCircleSprite(filename, radius, segments);
}

void Entity::addSegmentSprite(const std::string& filename, int radius, int segments, int which)
{
	this->deleteSprite();
	_sprite = new Sprite();
	_sprite->setupSegmentSprite(filename, radius, segments, which);
}

void Entity::addSprite(const std::string& filename, float pivotx, float pivoty)
{
	this->deleteSprite();
	_sprite = new Sprite();
	_sprite->setupSprite(filename, pivotx, pivoty, 1.0f, 1.0f, DEFAULTFILTER, DEFAULTWRAP); // trilinear filter, mirror repeat
}

void Entity::addSprite(const std::string& filename, float pivotx, float pivoty, int filter, int wrap)
{
	this->deleteSprite();
	_sprite = new Sprite();
	_sprite->setupSprite(filename, pivotx, pivoty, 1.0f, 1.0f, filter, wrap);
}

void Entity::addSpriteSheet(const std::string& filename, int u, int v)
{
	this->deleteSprite();
	_sprite = new Sprite();
	float uvwidth = 1.0f / u;
	float uvheight = 1.0f / v;
	_sprite->setupSprite(filename, 0.5f, 0.5f, uvwidth, uvheight, DEFAULTFILTER, DEFAULTWRAP); // trilinear filter, mirror repeat
}

void Entity::addGrid(const std::string& filename, int u, int v, int cols, int rows, int sizex, int sizey)
{
	this->deleteSpritebatch();
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {
			Sprite* s = new Sprite();
			s->useCulling(1);
			s->spriteposition.x = x * sizex;
			s->spriteposition.y = y * sizey;
			float uvwidth = 1.0f / u;
			float uvheight = 1.0f / v;
			s->setupSprite(filename, 0.5f, 0.5f, uvwidth, uvheight, 3, 0); // trilinear filter, repeat
			_spritebatch.push_back(s);
		}
	}

	std::cout << "grid added: " << _spritebatch.size() << " sprites." << std::endl;
}
