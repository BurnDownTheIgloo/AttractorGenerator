#pragma once
#include <iostream>
#include <vector>
#include "framework.h"
#include "AttractorGenerator.h"
#include "Point3D.h"
#include "Shape.h"
#include "Camera.h"
class Region
{
private:
	POINT screen_center;

	Camera camera;
	long qminusd;
	long d;
	std::vector<Shape> shapes;
	
public:
	Region() : screen_center({ 100,100 }), qminusd(100), d(100), camera(Camera()) {};
	Region(POINT origin, long screen_to_origin, long eye_to_screen) : 
		screen_center(origin), 
		qminusd(screen_to_origin), 
		d(eye_to_screen), 
		camera(Camera()) {};

	POINT GetScreenCenter() { return screen_center; }
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

