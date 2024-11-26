#pragma once

#include "Vector4.h"
#include "Color.h"
class Vertex4D
{
public:
	Vector4 point;
	Color vertColor;
	Vertex4D();
	Vertex4D(Vector4 _point, Color c);
	Vertex4D(Vector4 _point);
	Vertex4D(Color c);

	static Vertex4D Zero()
	{
		return Vertex4D(Vector4(0, 0, 0, 0), Color::White());
	}
private:

};

