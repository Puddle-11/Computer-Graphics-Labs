#pragma once
#include "Shader.h"
#include "Canvas.h"
#include "Mesh.h"
#include "Vector2.h"
#include "Vector3.h"
void DrawShaderLine(Vertex4D& p1, Vertex4D& p2);
void DrawMesh(Mesh& m);
void WorldtoNDC();

Vector2Int NDCtoScreen(Vector4 _NDCpos /*Between (-1,-1,-1), (1,1,1)*/);

Vector2Int NDCtoScreen(Vector4 _NDCpos /*Between (-1,-1,-1), (1,1,1)*/)
{

	//Filter x point to lie between -1, 1 to 0, 2
	_NDCpos.x += 1;
	_NDCpos.y += 1;


	_NDCpos.x *= ImageWidth / 2;
	_NDCpos.y = ImageHeight - _NDCpos.y * (ImageHeight / 2);

	return Vector2Int((int)_NDCpos.x, (int)_NDCpos.y);
}


void DrawPlane(Vector2 _size, int cells, Color c)
{
	Vertex4D p1, p2, p3, p4;


	for (size_t i = 0; i < cells + 1; i++)
	{

		p1.point = Vector4(_size.x / 2, 0, _size.y/(float)cells * i - (_size.y/2), 1);
		p2.point = Vector4(-_size.x / 2, 0, _size.y / (float)cells * i - (_size.y / 2), 1);

		p3.point = Vector4(_size.x / (float)cells * i - (_size.y / 2), 0, + (_size.y / 2), 1);
		p4.point = Vector4(_size.y / (float)cells * i - (_size.y / 2), 0,-(_size.y / 2), 1);

		p1.vertColor = c;
		p2.vertColor = c;
		p3.vertColor = c;
		p4.vertColor = c;

		DrawShaderLine(p3,p4);
		DrawShaderLine(p1, p2);

	}


}
void DrawMesh(Mesh& m)
{

	for (int i = 0; i < m.triCount; i++)
	{
		if (m.triangles[i] >= 0 || m.triangles[i] < m.vertCount)
		{
			if ((i + 1) % 3 == 0)
			{
				if (i <= 2) continue;
				if (!(m.triangles[i - 2] >= 0 || m.triangles[i - 2] < m.vertCount)) continue;

				DrawShaderLine(m.verticies[m.triangles[i]], m.verticies[m.triangles[i - 2]]);
			}
			else
			{
				if (!(m.triangles[i - 2] >= 0 || m.triangles[i - 2] < m.vertCount)) continue;

				DrawShaderLine(m.verticies[m.triangles[i]], m.verticies[m.triangles[i + 1]]);
			}
		}
	}
}

void DrawShaderLine(Vertex4D& p1, Vertex4D& p2)
{

	Vertex4D cpy1 = p1;
	Vertex4D cpy2 = p2;

	if (PixelShader)
	{

	}
	if (VertexShader)
	{
		VertexShader(cpy1);
		VertexShader(cpy2);
	}

	if (cpy1.point.w < NearPlane || cpy2.point.w < NearPlane) return;


	VertexScreen pixelPoint1;
	VertexScreen pixelPoint2;

	pixelPoint1.point = NDCtoScreen(cpy1.point);
	pixelPoint2.point = NDCtoScreen(cpy2.point);

	pixelPoint1.vertColor = p1.vertColor;
	pixelPoint2.vertColor = p2.vertColor;

	//Plot(pixelPoint1.point, cpy1.vertColor, 0);
	//DrawLine(pixelPoint1, pixelPoint2);

	float r = 0;
	int yChange = abs(pixelPoint2.point.y - pixelPoint1.point.y);
	int xChange = abs(pixelPoint2.point.x - pixelPoint1.point.x);

	int maxChange = xChange > yChange ? xChange : yChange;
	VertexScreen currVert = VertexScreen(pixelPoint1.point, pixelPoint1.vertColor);

	for (int i = 0; i <= maxChange; i++)
	{
		r = (float)i / (float)abs(maxChange);
		currVert.point = Vector2Int((int)floor(lerp((float)pixelPoint1.point.x, (float)pixelPoint2.point.x, r) + 0.5), (int)floor(lerp((float)pixelPoint1.point.y, (float)pixelPoint2.point.y, r) + 0.5));
		currVert.vertColor = Color::CLerp(pixelPoint2.vertColor, pixelPoint1.vertColor, (int)(r * 255));
		currVert.SetZ(lerp(cpy1.point.w, cpy2.point.w, r));

		if (PixelShader)
		{
			PixelShader(currVert);
		}

		Plot(currVert.point, currVert.vertColor, 0);
	}


}

