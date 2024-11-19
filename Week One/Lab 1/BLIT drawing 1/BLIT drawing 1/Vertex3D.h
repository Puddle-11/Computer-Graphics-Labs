#pragma once
#include "Vector3.h"
#include "Vector2.h"
#include "Color.h"
class Vertex3D
{
public:
	Vector3 point;
	Color vertColor;
	Vector2 uv;
	Vertex3D();
	Vertex3D(Vector3 _point, Color c);
	Vertex3D(Vector3 _point);
	Vertex3D(Color c);

	static Vertex3D Zero()
	{
		return Vertex3D(Vector3(0, 0, 0), Color::White());
	}
private:

};


