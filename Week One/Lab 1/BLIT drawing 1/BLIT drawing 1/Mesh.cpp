
#include "Mesh.h"

Mesh::Mesh()
{
	verticies = new Vertex4D[0];
	triangles = new int[0];
}


Mesh::~Mesh()
{
	delete[] verticies;
	delete[] triangles;
}

Mesh Mesh::operator=(const Mesh& _ref)
{
	this->SetTris(_ref.triangles, _ref.triCount);
	this->SetVerts(_ref.verticies, _ref.vertCount);
	return *this;
}



void Mesh::SetColor(Color objCol)
{
	objectColor = objCol;
}
Mesh::Mesh(const Mesh& _ref)
{
	this->SetTris(_ref.triangles, _ref.triCount);
	this->SetVerts(_ref.verticies, _ref.vertCount);
}
static Mesh TrianglePyramid()
{


}
 Mesh Mesh::SquarePyramid()
{
	Mesh m;
	Vertex4D pyramidVerts[5]
	{
	Vertex4D(Vector4(0.5, 0, 0.5, 1), Color::White()),
	Vertex4D(Vector4(0.5, 0, -0.5, 1), Color::White()),
	Vertex4D(Vector4(-0.5, 0, -0.5, 1), Color::White()),
	Vertex4D(Vector4(-0.5, 0, 0.5, 1), Color::White()),

	Vertex4D(Vector4(0, 1, 0, 1), Color::White()),
	};
	int pyramimdTris[18]{
		0,1,4,
		1,2,4,
		2,3,4,
		0,3,4,

		0,1,2,
		2,3,0
	};
	m.SetVerts(pyramidVerts, 5);
	m.SetTris(pyramimdTris, 18);
	return m;
}
Mesh Mesh::Cube()
{
	
	Mesh m;
	Vertex4D cubeVerts[8]
	{
	Vertex4D(Vector4(-0.5, -0.5, 0.5, 1), Color::White()),
	Vertex4D(Vector4(-0.5, 0.5, 0.5, 1), Color::White()),
	Vertex4D(Vector4(0.5, 0.5, 0.5, 1), Color::White()),
	Vertex4D(Vector4(0.5, -0.5, 0.5, 1), Color::White()),

	Vertex4D(Vector4(-0.5, -0.5, -0.5, 1), Color::White()),
	Vertex4D(Vector4(-0.5, 0.5,  -0.5, 1), Color::White()),
	Vertex4D(Vector4(0.5, 0.5,  -0.5, 1), Color::White()),
	Vertex4D(Vector4(0.5, -0.5, -0.5, 1), Color::White()),
	};
	int cubeTris[36]{

		0,1,2,
		3,2,0,

		4,5,6,
		7,6,4,

		0,4,5,
		5,1,0,

		3,7,6,
		6,2,3,

		1,5,2,
		5,6,2,

		0,4,3,
		4,7,3,
	};
	m.SetVerts(cubeVerts, 8);
	m.SetTris(cubeTris, 36);
	return m;
}

void Mesh::SetVerts(Vertex4D* points, int _vertCount)
{
	vertCount = _vertCount;
	delete[] verticies;
	verticies = new Vertex4D[vertCount];

	for (size_t i = 0; i < vertCount; i++)
	{
		verticies[i] = points[i];
	}
}

void Mesh::SetTris(int* tris, int _triCount)
{
	if (_triCount % 3 != 0) return;
	triCount = _triCount;
	delete[] triangles;
	triangles = new int[triCount];
	for (size_t i = 0; i < triCount; i++)
	{
		triangles[i] = tris[i];
	}
}

void Mesh::Rotate(Matrix rotationMatrix)
{


}
void Mesh::Transform(Vector4 _offset)
{
	center = center + _offset;
}



