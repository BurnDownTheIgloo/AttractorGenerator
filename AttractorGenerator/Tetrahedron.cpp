#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(Point3D location, int width): Shape(location), width(width)
{
	Point3D shapepoints[] =
	{Point3D(location.x, location.y - ((-sqrt(3) / (6.0 * sqrt(2))) * width), location.z + ((sqrt(3) / 3.0) * width)),
	Point3D(location.x + ((1.0 / 2.0) * width), location.y - ((-sqrt(3) / (6.0 * sqrt(2))) * width), location.z + ((-sqrt(3) / 6.0) * width)),
	Point3D(location.x + ((-1.0 / 2.0) * width), location.y - ((-sqrt(3) / (6.0 * sqrt(2))) * width), location.z + ((-sqrt(3) / 6.0) * width)),
	Point3D(location.x, location.y - ((sqrt(3)/sqrt(8))*width), location.z)};

	/*
	{Point3D(location.x + ((sqrt(3)/3.0)*width), location.y, location.z + ((-sqrt(3)/(6.0*sqrt(2)))*width)),
	Point3D(location.x + (( -sqrt(3)/6.0 )*width), location.y + ( (1.0/2.0)*width), location.z + (( -sqrt(3)/(6.0*sqrt(2)) )*width)),
	Point3D(location.x + ((-sqrt(3) / 6.0)*width), location.y + ((-1.0 / 2.0) * width), location.z + ((-sqrt(3) / (6.0 * sqrt(2))) * width)),
	Point3D(location.x, location.y, location.z + width)};
	*/

	for (int i = 0; i < 4; i++) {
		points[i] = shapepoints[i];
	}

	for (Point3D p : points) {
		for (Point3D p2 : points) {
			if (p == p2) continue;
			bool i = false;
			for (Line l : Shape::lines) {
				if ((l.p1 == p && l.p2 == p2) || (l.p1 == p2 && l.p2 == p)) i = true;
			}
			if (i) continue;
			Shape::lines.push_back({ p, p2 });
		}
	}
}
