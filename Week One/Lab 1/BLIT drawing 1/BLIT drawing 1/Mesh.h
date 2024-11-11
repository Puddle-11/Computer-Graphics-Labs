#pragma once
#include "Vertex4D.h"
class Mesh
{
public:
	Mesh();
	~Mesh();
	int vertCount;
	int triCount;
	Vector4 center = Vector4::Zero();
	void SetVerts(Vertex4D* points, int vertCount);
	void SetTris(int* tris, int triCount);
	void Rotate(Matrix rotationMatrix);
	void SetColor(Color objCol);
	void Transform(Vector4 _offset);
	Vertex4D* verticies;
	Color objectColor;
	int* triangles;
};

