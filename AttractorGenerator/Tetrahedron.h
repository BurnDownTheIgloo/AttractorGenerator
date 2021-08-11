#pragma once
#include "Shape.h"
class Tetrahedron :
	public Shape
{
private:
	int width;
	Point3D points[4];
public:
	Tetrahedron(Point3D location, int radius);
	std::vector<Line> GetLines() override { return Shape::lines; }
};

