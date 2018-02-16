#ifndef CANVAS_H
#define CANVAS_H

#include "Entity.h"

struct Pixel {

	Point2i position;
	RGBAColor color;

	Pixel(Point2i pos, RGBAColor c) { position = pos; color = c; };
};

struct PixelSprite {

	std::vector<Pixel> pixels;

	Point2i position;


	RGBAColor pallete[10] = {
		MAGENTA,
		WHITE,
		BLUE,
		MAGENTA,
		RED,
		GREEN,
		YELLOW,
		PINK,
		ORANGE,
		GRAY
	};

	void init(char* data, int w, int h) {
		RGBAColor color;
		size_t size = w*h;
		for (size_t i = 0; i < size; i++) {
			int y=i/w;
			int x=i%w;

			int value = (int) data[i];
			if (value != 0) {
				color = pallete[value];
				this->pixels.push_back( Pixel(Point2i(x-(w/2), (y*-1)+(h/2)), color) );
			}
		}
	};

	void createLine(Vector2f vec, RGBAColor color) {
		float x0 = 0.0f;
		float y0 = 0.0f;
		float x1 = vec.x;
		float y1 = vec.y;

		bool steep = false;
		if (std::abs(x0-x1) < std::abs(y0-y1)) {
			std::swap(x0, y0);
			std::swap(x1, y1);
			steep = true;
		}
		if (x0 > x1) {
			std::swap(x0, x1);
			std::swap(y0, y1);
		}
		int dx = x1-x0;
		int dy = y1-y0;
		int derror2 = std::abs(dy)*2;
		int error2 = 0;
		int y = y0;
		for (int x = x0; x <= x1; x++) {
			if (steep) {
				this->pixels.push_back( Pixel(Point2i(y,x), color) );
			} else {
				this->pixels.push_back( Pixel(Point2i(x,y), color) );
			}
			error2 += derror2;

			if (error2 > dx) {
				y += (y1 > y0 ? 1 : -1);
				error2 -= dx*2;
			}
		}
	};

	// https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
	void createCircle(int radius, RGBAColor color) {
		int x = radius;
		int y = 0;
		int err = 0;

		while (x >= y) {
			this->pixels.push_back( Pixel(Point2i( x, y), color) );
			this->pixels.push_back( Pixel(Point2i( y, x), color) );
			this->pixels.push_back( Pixel(Point2i(-y, x), color) );
			this->pixels.push_back( Pixel(Point2i(-x, y), color) );
			this->pixels.push_back( Pixel(Point2i(-x, -y), color) );
			this->pixels.push_back( Pixel(Point2i(-y, -x), color) );
			this->pixels.push_back( Pixel(Point2i( y, -x), color) );
			this->pixels.push_back( Pixel(Point2i( x, -y), color) );

			if (err <= 0) {
				y += 1;
				err += 2*y + 1;
			}
			if (err > 0) {
				x -= 1;
				err -= 2*x + 1;
			}
		}
	}

	PixelSprite rotated(float a) {
		PixelSprite copy;
		copy.position = this->position;
		size_t s = pixels.size();
		for (size_t i = 0; i < s; i++) {
			Vector2f v = Vector2f(pixels[i].position.x, pixels[i].position.y, 0);
			v.rotate(a);
			int x = nearbyint(v.x+0.1);
			int y = nearbyint(v.y+0.1);
			copy.pixels.push_back(Pixel(Point2i(x, y), pixels[i].color));
		}
		return copy;
	};
};


class Canvas: public Entity
{
	public:
		Canvas();

		Canvas(int pixelsize);

		virtual ~Canvas();

		virtual void update();

		void init(int pixelsize);

		void setPixel(int x, int y, RGBAColor color);

		RGBAColor getPixel(int x, int y);

		void clearPixel(int x, int y);

		void fill(RGBAColor color);

		int width() { return _width; };

		int height() { return _height; };

		void drawSprite(const PixelSprite& spr);

		void clearSprite(const PixelSprite& spr);

		RGBAColor backgroundcolor;

	private:

		PixelBuffer* _framebuffer;

		int _width;
		int _height;
};

#endif /* CANVAS_H */
