#include <iostream>

#include "SHFWConfig.h"
#include "Sprite.h"

Sprite::Sprite()
{
	this->texturename = AUTOGENWHITE;

	this->fragmentshader = DEFAULTFRAGMENTSHADERPATH;
	this->vertexshader = DEFAULTVERTEXSHADERPATH;

	spriteposition = Point3(0.0f, 0.0f, 0.0f); // spritebatch only
	spriterotation = Point3(0.0f, 0.0f, 0.0f); // spritebatch only
	spritescale = Point3(1.0f, 1.0f, 1.0f); // spritebatch only

	pivot = Point2(0.5f, 0.5f);
	uvdim = Point2(1.0f, 1.0f);
	uvoffset = Point2(0.0f, 0.0f);
	size = Point2(0, 0);

	for (size_t i = 0; i < 8; i++) {
		customParams[i] = Point3(0.0f, 0.0f, 0.0f);
	}

	this->palette = NULL;

	this->frame = 0;

	this->filter = DEFAULTFILTER;
	this->wrap = DEFAULTWRAP;

	this->dyntexture = NULL;
	this->dynamic = false;

	this->circlemesh = 0; // false
	this->which = -1; // disabled

	this->useculling = 0;

	color = RGBAColor(255, 255, 255, 255);
}

Sprite::~Sprite()
{
	//if (this->dyntexture != NULL) {
	// TODO this leaks the dynamic textures (get rid of !dynamic)
	if (this->dyntexture != NULL && !this->dynamic) {
		delete this->dyntexture;
		this->dyntexture = NULL;
	}

	if (this->palette != NULL) {
		delete this->palette;
		this->palette = NULL;
	}
}

void Sprite::setPalette(const std::string& filename)
{
	if (this->palette != NULL) {
		delete this->palette;
		this->palette = NULL;
	}
	this->palette = new Texture();
	this->palette->loadTGAImage(filename, 0, 0, 1); // filename, filter, wrap, dimension
}

void Sprite::setupSprite(const std::string& filename, float pivotx, float pivoty, float uvwidth, float uvheight)
{
	this->setupSprite(filename, pivotx, pivoty, uvwidth, uvheight, DEFAULTFILTER, DEFAULTWRAP);
}

void Sprite::setupCircleSprite(const std::string& filename, int radius, int segments)
{
	this->setupSegmentSprite(filename, radius, segments, -1);
}

void Sprite::setupSegmentSprite(const std::string& filename, int radius, int segments, int which)
{
	this->texturename = filename;
	this->circlemesh = segments; // only a single segment (triangle)
	this->which = which; // which segment

	this->filter = DEFAULTFILTER;
	this->wrap = DEFAULTWRAP;

	size.x = radius * 2;
	size.y = radius * 2;
}

void Sprite::setupSprite(const std::string& filename, float pivotx, float pivoty, float uvwidth, float uvheight, int filter, int wrap)
{
	this->texturename = filename;

	this->filter = filter;
	this->wrap = wrap;

	pivot.x = pivotx;
	pivot.y = pivoty;

	// 1.00000 = 1x1 spritesheet (basic sprite)
	// 0.50000 = 2x2 spritesheet
	// 0.25000 = 4x4 spritesheet
	// 0.12500 = 8x8 spritesheet
	// 0.06250 = 16x16 spritesheet
	// 0.03125 = 32x32 spritesheet
	uvdim.x = uvwidth;
	uvdim.y = uvheight;
}

void Sprite::setupSpriteByPixelBuffer(PixelBuffer* pixels)
{
	std::cout << "Sprite::setupSpriteByPixelBuffer() " <<  std::endl;
	if (this->dyntexture != NULL) {
		delete this->dyntexture;
		this->dyntexture = NULL;
	}

	this->filter = pixels->filter;
	this->wrap = pixels->wrap;

	size.x = pixels->width;
	size.y = pixels->height;

	this->dyntexture = new Texture();
	this->dyntexture->createFromBuffer(pixels);
	this->dynamic = true;
}

void Sprite::setupSpriteTGAPixelBuffer(const std::string& filename, int filter, int wrap)
{
	std::cout << "Sprite::setupSpriteByPixelBuffer() " <<  std::endl;
	if (this->dyntexture != NULL) {
		delete this->dyntexture;
		this->dyntexture = NULL;
	}

	this->dyntexture = new Texture();
	this->dyntexture->loadTGAImage(filename, filter, wrap);
	this->dynamic = true;

	size.x = (float) this->dyntexture->width();
	size.y = (float) this->dyntexture->height();

	this->filter = filter;
	this->wrap = wrap;
}

int Sprite::setFrame(int f)
{
	int w = 1.0f / uvdim.x;
	int h = 1.0f / uvdim.y;

	if (f >= w*h) {
		this->frame = 0;
		uvoffset.x = 0;
		uvoffset.y = 0;
		return this->frame;
	}

	int ypos=f/w;
	int xpos=f%w;

	uvoffset.x = xpos * uvdim.x;
	uvoffset.y = ypos * uvdim.y;

	this->frame = f;

	return this->frame;
}
