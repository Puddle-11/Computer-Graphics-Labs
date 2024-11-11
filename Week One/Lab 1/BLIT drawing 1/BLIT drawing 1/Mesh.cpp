
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

void Mesh::SetColor(Color objCol)
{
    objectColor = objCol;
}

void Mesh::SetVerts(Vertex4D* points, int _vertCount)
{
    vertCount = _vertCount;
    delete[] verticies;
    verticies = points;
}

void Mesh::SetTris(int* tris, int _triCount)
{
    if (_triCount % 3 != 0) return;
    triCount = _triCount;
    delete[] triangles;
    triangles = tris;
}

void Mesh::Rotate(Matrix rotationMatrix)
{


}
void Mesh::Transform(Vector4 _offset)
{
    center = center + _offset;
}



