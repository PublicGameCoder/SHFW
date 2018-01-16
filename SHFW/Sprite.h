#ifndef SPRITEH
#define SPRITEH

#include <glm/glm.hpp>

#include "Texture.h"
#include "Color.h"
#include "PointT.h"

class Sprite
{
public:
	Sprite();
	virtual ~Sprite();

	std::string getTextureName() { return texturename; };

	void setTextureName(std::string texturename) { texturename = texturename; };

	std::string getFragmentShader() { return fragmentshader; };

	std::string getVertexShader() { return vertexshader; };

	void setFragmentShader(std::string fragmentshader) { fragmentshader = fragmentshader; };

	void setVertexShader(std::string vertexshader) { vertexshader = vertexshader; };

	int setFrame(int f);

	int getFrame() { return frame; };

	Point3 spriteposition;
	Point3 spriterotation;
	Point3 spritescale;

	Point2 pivot;
	Point2 uvdim;
	Point2 uvoffset;
	Point2 size;
	RGBAColor color;

	Point3 customParams[8];

	void setupSprite(const std::string& filename, float pivotx, float pivoty, float uvwidth, float uvheight);

	void setupCircleSprite(const std::string& filename, int radius, int segments);

	void setupSegmentSprite(const std::string& filename, int radius, int segments, int which);

	void setupSprite(const std::string& filename, float pivotx, float pivoty, float uvwidth, float uvheight, int filter, int wrap);

	void setupSpriteByPixelBuffer(PixelBuffer* pixels);

	void setupSpriteTGAPixelBuffer(const std::string& filename, int filter, int wrap);

	void setPalette(const std::string& filename);

	Texture* getPalette() { return palette; };

	Texture* getTexture() { return dyntexture; };

	bool isDynamic() { return dynamic; };

	void isDynamic(bool d) { dynamic = d; };

	void setFilter(int f) { filter = f; };

	int getFilter() { return filter; };

	void setWrap(int w) { wrap = w; };

	int getWrap() { return wrap; };

	int isWhich() { return which; };

	int getCircleMesh() { return circlemesh; };

	int useCulling() { return useculling; };

	void useCulling(int c) { useculling = c; };

private:
	int frame;

	std::string texturename;

	std::string fragmentshader;
	std::string vertexshader;

	Texture* palette;

	Texture* dyntexture;
	bool dynamic;

	int filter;
	int wrap;

	int circlemesh;
	int which;

	int useculling;
};

#endif /* SPRITEH */
