#pragma once

#include "Vector4.h"
#include "Color.h"
#include "Vector2.h"
#include "Vector3.h"
class Vertex4D
{
public:
	Vector4 point;
	Color vertColor;
	Vector2 uv;
	Vector3 normal;
	Vertex4D();
	Vertex4D(Vector4 _point, Color c, Vector2 _uv, Vector3 _normal);
	Vertex4D(Vector4 _point, Color c, Vector2 _uv);
	Vertex4D(Vector4 _point, Color c);
	Vertex4D(Vector4 _point);
	Vertex4D(Color c);

	static Vertex4D Zero()
	{
		return Vertex4D(Vector4(0, 0, 0, 0), Color::White());
	}
private:

};

