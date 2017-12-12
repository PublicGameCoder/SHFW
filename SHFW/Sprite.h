#ifndef SPRITE_H
#define SPRITE_H

#include <string>

class Sprite
{
	public:
		Sprite(std::string image_path);
		virtual ~Sprite();

	private:
		std::string filePath;
};

#endif /* SPRITE_H */
