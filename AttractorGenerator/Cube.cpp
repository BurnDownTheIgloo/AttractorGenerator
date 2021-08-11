#include "Cube.h"

Cube::Cube(Point3D location, int radius) : Shape(location), radius(radius)
{
	Point3D shapepoints[] =  
	{Point3D(location.x + radius, location.y + radius, location.z + radius),
	Point3D(location.x + radius, location.y + radius, location.z - radius),
	Point3D(location.x + radius, location.y - radius, location.z + radius),
	Point3D(location.x + radius, location.y - radius, location.z - radius),
	Point3D(location.x - radius, location.y + radius, location.z + radius),
	Point3D(location.x - radius, location.y + radius, location.z - radius),
	Point3D(location.x - radius, location.y - radius, location.z + radius),
	Point3D(location.x - radius, location.y - radius, location.z - radius)};

	for (int i = 0; i < 8; i++) {
		points[i] = shapepoints[i];
	}

	for (Point3D p : points) {
		//lines.push_back({ p, Point3D(p.x + 10, p.y, p.z) });
		for (Point3D p2 : points) {
			if (p == p2) continue;
			bool i = false;
			for (Line l : Shape::lines) {
				if ((l.p1 == p && l.p2 == p2) || (l.p1 == p2 && l.p2 == p)) i = true;
			}
			if (i) continue;
			if (p.x == p2.x && p.y == p2.y && p.z != p2.z) Shape::lines.push_back({ p, p2 });
			else if (p.x == p2.x && p.y != p2.y && p.z == p2.z) Shape::lines.push_back({ p,p2 });
			else if (p.x != p2.x && p.y == p2.y && p.z == p2.z) Shape::lines.push_back({ p, p2 });
		}
	}
}
/*
void Cube::Draw(HDC hdc)
{
	DrawLines(hdc, lines);
}
*/