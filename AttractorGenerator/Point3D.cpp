#include "Point3D.h"

bool Point3D::operator==(Point3D p)
{
	return (x == p.x && y == p.y && z == p.z);
}
