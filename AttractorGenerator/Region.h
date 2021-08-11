#pragma once
#include <iostream>
#include "framework.h"
#include "AttractorGenerator.h"
#include "Point3D.h"
#include <vector>
#include "Cube.h"
class Region
{
private:
	//HDC hdc;
	POINT screen_center;
	long qminusd;
	long d;
	std::vector<Shape> shapes;
	
public:
	Region() : screen_center({ 100,100 }), qminusd(100), d(100) {};
	Region(POINT origin, long screen_to_origin, long eye_to_screen) : 
		screen_center(origin), 
		qminusd(screen_to_origin), 
		d(eye_to_screen) {};

	//HDC GetHDC() { return hdc; }

	POINT GetOrigin() { return screen_center; }
	long GetEyeToScreen() { return d; }
	long GetEyeToOrigin() { return d + qminusd; }
	void AddShape(Shape s) { shapes.push_back(s); }
	//void AddLine(Line l) { //TODO implement. }
	std::vector<Shape>& GetShapes() { return shapes; }

	POINT PointTo2D(const Point3D point);
	POINT PointToScreenPlot(const POINT point);
	POINT PointToScreenPlot(const Point3D point);

	void Draw(HDC hdc);
};

