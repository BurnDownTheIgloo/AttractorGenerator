#pragma once
#include "Shape.h"
class Cube :
	public Shape
{
private:
	int radius;
	Point3D points[8];
public:
	Cube(Point3D location, int radius);
	std::vector<Line> GetLines() override { return Shape::lines; }
	//void Draw(HDC hdc);
};

