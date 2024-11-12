#pragma once
#include "Vertex4D.h"
class Mesh
{
public:
	Mesh();
	~Mesh();
	Mesh(const Mesh& _ref);
	int vertCount;
	int triCount;
	Vector4 center = Vector4::Zero();
	void SetVerts(Vertex4D* points, int vertCount);
	void SetTris(int* tris, int triCount);
	void Rotate(Matrix rotationMatrix);
	void SetColor(Color objCol);
	void Transform(Vector4 _offset);
	Mesh operator=(const Mesh& _ref);


	static Mesh TrianglePyramid();
	static Mesh SquarePyramid();
	static Mesh Cube();


	Vertex4D* verticies;
	Color objectColor;
	int* triangles;
};

