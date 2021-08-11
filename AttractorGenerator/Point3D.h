#pragma once
#include <iostream>
#include "framework.h"
#include "AttractorGenerator.h"
#include <vector>
class Point3D
{
public:
	double x;
	double y;
	double z;
	Point3D() : x(0), y(0), z(0) {};
	Point3D(double x, double y, double z) : x(x), y(y), z(z) {};
	bool operator==(Point3D p);
};

