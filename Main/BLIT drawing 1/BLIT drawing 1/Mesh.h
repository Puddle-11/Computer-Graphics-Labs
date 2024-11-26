#pragma once
#include "Vertex4D.h"
#include "ScreenBounds.h"
class Mesh
{
public:
	Mesh();
	~Mesh();
	Mesh(const Mesh& _ref);
	int vertCount;
	int triCount;
	unsigned int* texture;
	int textureSize;
	ScreenBounds scrBounds;


	Vector4 center = Vector4::Zero();
	void SetTexture(const unsigned int* _text, int _count, ScreenBounds _scrBounds);

	void SetVerts(Vertex4D* points, int vertCount);
	void SetTris(int* tris, int triCount);
	void SetTris(const unsigned int* tris, int _triCount);
	void Rotate(Matrix rotationMatrix);
	void SetColor(Color objCol);
	void Transform(Vector4 _offset);
	Mesh operator=(const Mesh& _ref);


	static Mesh TrianglePyramid();
	static Mesh SquarePyramid();
	static Mesh Cube();
	static Mesh UniqueCube();

	Vertex4D* verticies;
	Color objectColor;
	int* triangles;
};

