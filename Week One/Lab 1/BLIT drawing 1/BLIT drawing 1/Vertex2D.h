#pragma once
#include "Vector.h"
#include "Color.h"
class Vertex2D 
{
public:
	Vector2 point;
	Color vertColor;
	Vertex2D();
	Vertex2D(Vector2 _point, Color c);
	Vertex2D(Vector2 _point);
	Vertex2D(Color c);
private:

};
Vertex2D::Vertex2D()
{
	point = Vector2::Zero();
	vertColor = Color::White();
}
Vertex2D::Vertex2D(Vector2 _point, Color c)
{
	point = _point;
	vertColor = c;
}
Vertex2D::Vertex2D(Vector2 _point)
{
	point = _point;
	vertColor = Color::White();
}
Vertex2D::Vertex2D(Color c)
{
	point = Vector2::Zero();
	vertColor = c;
}