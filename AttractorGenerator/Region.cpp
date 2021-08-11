#include "Region.h"

POINT Region::PointTo2D(const Point3D point)
{
	long dh = d;
	long q = d + qminusd;
	double x2 = dh * (point.x / ((q) + point.z));
	double y2 = dh * (point.y / ((q) + point.z));
	return { static_cast<int>(x2), static_cast<int>(y2) };
}

POINT Region::PointToScreenPlot(const POINT point)
{
	return { point.x + screen_center.x, point.y + screen_center.y };
}

POINT Region::PointToScreenPlot(const Point3D point)
{
	return PointToScreenPlot(PointTo2D(point));
}

void Region::Draw(HDC hdc)
{
	for (Shape s : shapes) {
		for (Line line : s.GetLines()) {
			POINT points[2];
			points[0] = PointToScreenPlot(line.p1);
			points[1] = PointToScreenPlot(line.p2);
			BYTE types[] = { PT_MOVETO, PT_LINETO };
			PolyDraw(hdc, points, types, 2);
		}
	}
}
