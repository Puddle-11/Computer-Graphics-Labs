#pragma once
#pragma once
#include "Vector.h"
#include "Color.h"
class Vertex3D
{
public:
	Vector3 point;
	Color vertColor;
	Vertex3D();
	Vertex3D(Vector3 _point, Color c);
	Vertex3D(Vector3 _point);
	Vertex3D(Color c);
private:

};
Vertex3D::Vertex3D()
{
	point = Vector3::Zero();
	vertColor = Color::White();
}
Vertex3D::Vertex3D(Vector3 _point, Color c)
{
	point = _point;
	vertColor = c;
}
Vertex3D::Vertex3D(Vector3 _point)
{
	point = _point;
	vertColor = Color::White();
}
Vertex3D::Vertex3D(Color c)
{
	point = Vector3::Zero();
	vertColor = c;
}