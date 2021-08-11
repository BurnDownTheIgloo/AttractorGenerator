#include "Camera.h"

Camera::Camera(Point3D eye, double lens_length, double lens_width, double camera_yaw, double camera_pitch) : location(eye), lens_length(lens_length), lens_width(lens_width) 
{ 
	if (abs(camera_yaw) > 360) yaw = std::fmod(camera_yaw, 360); else yaw = camera_yaw;
	if (camera_pitch > 90) pitch = 90; else if (camera_pitch < -90) pitch = -90; else pitch = camera_pitch;
}