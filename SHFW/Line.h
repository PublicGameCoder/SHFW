#ifndef LINE_H
#define LINE_H

#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

#include <glm/glm.hpp>

#include "Color.h"

class Line
{
public:
	Line();
	Line(const std::string& filename);
	virtual ~Line();

	RGBAColor color;

	std::string filename() { return _filename; };

	bool loadLineFile(const std::string& filename);

	void addPoint(float x, float y, float z = 0.0f);

	void editPoint(unsigned int id, float x, float y, float z = 0.0f);

	void createCircle(int radius, int segments);

	void createBox(int hw, int hh);

	std::vector<glm::vec3>& points() { return _points; };

	bool dynamic() { return _dynamic; };

	void dynamic(bool d) { _dynamic = d; };

	bool closed() { return _closed; };

	void closed(bool c) { _closed = c; };

private:
	std::string _filename;
	std::vector<glm::vec3> _points;

	int _guid;
	static int _nextGuid;

	bool _dynamic;
	bool _closed;
};

#endif /* LINE_H */
