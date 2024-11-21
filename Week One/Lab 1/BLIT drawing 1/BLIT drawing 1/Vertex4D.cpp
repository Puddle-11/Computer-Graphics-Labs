#include "Vertex4D.h"


Vertex4D::Vertex4D()
{
	point = Vector4::Zero();
	vertColor = Color::White();
	uv = Vector2::Zero();
}
Vertex4D::Vertex4D(Vector4 _point, Color c)
{
	point = _point;
	vertColor = c;
	normal = Vector3::Zero();

}
Vertex4D::Vertex4D(Vector4 _point)
{
	point = _point;
	vertColor = Color::White();
	normal = Vector3::Zero();

}
Vertex4D::Vertex4D(Color c)
{
	point = Vector4::Zero();
	vertColor = c;
	normal = Vector3::Zero();

}
Vertex4D::Vertex4D(Vector4 _point, Color c, Vector2 _uv)
{
	point = _point;
	vertColor = c;
	uv = _uv;
	normal = Vector3::Zero();
}
Vertex4D::Vertex4D(Vector4 _point, Color c, Vector2 _uv, Vector3 _normal)
{
	point = _point;
	vertColor = c;
	uv = _uv;
	normal = _normal;
}