#pragma once
#include "Point3D.h"
class Camera
{
private:
	Point3D location;
	double lens_length;
	double lens_width;
	double yaw;
	double pitch;
public:
	Camera() : location(Point3D(0, 0, 300)), lens_length(50), lens_width(50), yaw(0), pitch(0) {};
	Camera(Point3D location, double lens_length, double lens_width, double camera_yaw, double camera_pitch);

	Point3D GetLocation() { return location; }
	void SetLocation(Point3D new_location) { location = new_location; }
	
	double GetLensLength() { return lens_length; }
	double SetLensLength(double new_lens_length) { lens_length = new_lens_length; }
	double GetLensWidth() { return lens_width; }
	double SetLensWidth(double new_lens_width) { lens_width = new_lens_width; }
	double GetYaw() { return yaw; }
	double SetYaw(double new_yaw) { yaw = new_yaw; }
	double GetPitch() { return pitch; }
	double SetPitch(double new_pitch) { pitch = new_pitch; }
};

