#pragma once
#include "Point3D.h"


struct Line {
	Point3D p1;
	Point3D p2;
};

class Shape
{
protected:
	Point3D location;
	std::vector<Line> lines;
	//void DrawLines(HDC hdc, std::vector<Line> lines);
public:
	Shape() : location(Point3D(0, 0, 0)) {};
	Shape(Point3D location): location(location) {}
	virtual std::vector<Line> GetLines() { return lines; }
};
