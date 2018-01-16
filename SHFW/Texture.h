#ifndef TEXTURE_H
#define TEXTURE_H

#include <sstream>
#include <string>
#include "Time.h"
#include <ctime>
#include <glfw3.h>
#include "Color.h"

struct PixelBuffer
{
	int width;
	int height;

	unsigned char bitdepth;

	int filter;

	int wrap;
	unsigned char* data;

	PixelBuffer()
	{
		width = 0;
		height = 0;
		bitdepth = 0;
		filter = 0;
		wrap = 0;
		data = (unsigned char*)0;
	}
	PixelBuffer(int w, int h, unsigned char b, int f, int wr)
	{
		width = w;
		height = h;
		bitdepth = b;
		filter = f;
		wrap = wr;
		long size = w * h * b;
		data = new unsigned char[size];
		for (long i=0; i<size; i++) {
			data[i] = 255;
		}
	}

	~PixelBuffer() {
		delete[] data;
		data = 0;
	}

	void setPixel(int x, int y, RGBAColor color)
	{
		int start = ((y*this->width) + x) * this->bitdepth;
		if (start > this->width * this->height * this->bitdepth || start < 0) { return; }

		if (this->bitdepth == 1) {
			int value = (color.r + color.g + color.b) / 3;
			this->data[start+0] = value;
		}
		if (this->bitdepth == 3 || this->bitdepth == 4) {
			this->data[start+0] = color.r;
			this->data[start+1] = color.g;
			this->data[start+2] = color.b;
		}
		if (this->bitdepth == 4) {
			this->data[start+3] = color.a;
		}
	}

	RGBAColor getPixel(int x, int y)
	{
		RGBAColor color = RGBAColor(0,0,0,255);
		int start = ((y*this->width) + x) * this->bitdepth;
		if (start > this->width * this->height * this->bitdepth || start < 0) { return color; }

		if (this->bitdepth == 1) {
			color.r = this->data[start+0];
			color.g = this->data[start+0];
			color.b = this->data[start+0];
		}
		if (this->bitdepth == 3 || this->bitdepth == 4) {
			color.r = this->data[start+0];
			color.g = this->data[start+1];
			color.b = this->data[start+2];
		}
		if (this->bitdepth == 4) {
			color.a = this->data[start+3];
		}
		return color;
	}

	void destroy() {
		delete[] data;
		data = 0;
	}
};

class Texture
{
public:
	Texture();
	virtual ~Texture();

	GLuint getGLTexture() { return _gltexture[0]; };

	PixelBuffer* pixels() { return _pixelbuffer; };

	int width() { return _width; };

	int height() { return _height; };

	int depth() { return _depth; };

	GLuint loadTGAImage(const std::string& filename, int filter, int wrap, int dim = 2);

	int writeTGAImage();

	GLuint createWhitePixels(int width, int height);

	void createFromBuffer(PixelBuffer* pixels, int dim = 2);

	unsigned char warranty() { return _warrantybit; };

private:
	void BGR2RGB(PixelBuffer* pixels);

	int _width;
	int _height;
	int _depth;

	GLuint _gltexture[1];

	unsigned char _warrantybit;
	PixelBuffer* _pixelbuffer;

	void deletePixelBuffer() {
		if (_pixelbuffer != NULL) {
			delete _pixelbuffer;
			_pixelbuffer = NULL;
		}
	};
};


#endif // TEXTURE_H
