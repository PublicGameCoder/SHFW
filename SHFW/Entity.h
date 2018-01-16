#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <glm/glm.hpp>
#include <glm/gtx/matrix_decompose.hpp>

#include "SHFWConfig.h"
#include "Timer.h"
#include "Sprite.h"
#include "Line.h"
#include "VectorT.h"
#include "InputManager.h"
#include "SHTime.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void update() = 0;

	Point3 position;
	Point3 rotation;
	Point3 scale;

	void addChild(Entity* child);

	void removeChild(Entity* child);

	Entity* getChild(unsigned int i);

	const std::vector<Entity*>& children() { return _children; };

	Sprite* sprite() { return _sprite; };

	void addSprite(Sprite* spr);

	void addSprite(const std::string& filename);

	void addSprite(const std::string& filename, float pivotx, float pivoty);

	void addSprite(const std::string& filename, float pivotx, float pivoty, int filter, int wrap);

	void addSpriteSheet(const std::string& filename, int u, int v);

	void addGrid(const std::string& filename, int u, int v, int cols, int rows, int sizex, int sizey);

	void addCircleSprite(const std::string& filename, int radius, int segments);

	void addSegmentSprite(const std::string& filename, int radius, int segments, int which);

	void addDynamicSprite(PixelBuffer* pixels);

	Line* line() {
		if (_line != NULL) {
			return _line;
		} else {
			if (_linebatch.size() > 0) {
				return &_linebatch[0];
			}
		}
		return NULL;
	};

	void addLine(Line* line);

	void addLine(const std::string& filename);

	std::vector<Sprite*>& spritebatch() { return _spritebatch; };

	std::vector<Line>& linebatch() { return _linebatch; };

	int guid() { return _guid; };

	Entity* parent() { return _parent; };

	Point3 worldposition() { return _worldposition; };

	Point3 worldrotation() { return _worldrotation; };

	Point3 worldscale() { return _worldscale; };

	InputManager* input() { return InputManager::getManager(); };

	friend class Renderer;

protected:
	Point3 _worldposition;
	Point3 _worldrotation;
	Point3 _worldscale;

	std::vector<Sprite*> _spritebatch;
	std::vector<Line> _linebatch;

private:
	int _guid;
	static int _nextGuid;

	Entity* _parent;
	std::vector<Entity*> _children;

	Sprite* _sprite;
	Line* _line;

	void deleteSprite() {
		if (_sprite != NULL) {
			delete _sprite;
			_sprite = NULL;
		}
	};

	void deleteLine() {
		if (_line != NULL) {
			delete _line;
			_line = NULL;
		}
	};

	void deleteLinebatch() {
		_linebatch.clear();
	};

	void deleteSpritebatch() {
		int s = _spritebatch.size();
		for (int i = 0; i < s; i++) {
			delete _spritebatch[i];
		}
		_spritebatch.clear();
	};
};

#endif /* ENTITY_H */
