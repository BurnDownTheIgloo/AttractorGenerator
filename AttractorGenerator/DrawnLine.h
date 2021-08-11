#pragma once
#include "Shape.h"
class DrawnLine :
	public Shape
{
public:
	DrawnLine(Point3D point1, Point3D point2) { Shape::lines.push_back({ point1, point2 }); };
	virtual std::vector<Line> GetLines() { return lines; }
};

