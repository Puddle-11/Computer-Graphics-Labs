#pragma once
#include "Shader.h"
#include "Canvas.h"
#include "Mesh.h"
#include "Vector2.h"
#include "Vector3.h"
#include <vector>
void DrawShaderLine(Vertex4D& p1, Vertex4D& p2);
void DrawMesh(Mesh& m);
void WorldtoNDC();

Vector2Int NDCtoScreen(Vector4 _NDCpos /*Between (-1,-1,-1), (1,1,1)*/);
void DrawPlane(Vector2 _size, int cells, Color c1);
void DrawPlane(Vector2 _size, int cells, Color c1, Color c2);
void DrawPlane(Vector2 _size, int cells, Color c1, Color c2, Color c3);
void DrawPlane(Vector2 _size, int cells, Color c1, Color c2, Color c3, Color c4);
Vector2Int NDCtoScreen(Vector4 _NDCpos /*Between (-1,-1,-1), (1,1,1)*/)
{

	//Filter x point to lie between -1, 1 to 0, 2
	_NDCpos.x += 1;
	_NDCpos.y += 1;


	_NDCpos.x *= ImageWidth / 2;
	_NDCpos.y = ImageHeight - _NDCpos.y * (ImageHeight / 2);

	return Vector2Int((int)_NDCpos.x, (int)_NDCpos.y);
}
void DrawPlane(Vector2 _size, int cells, Color c1)
{
	DrawPlane(_size, cells, c1, c1, c1, c1);
}
void DrawPlane(Vector2 _size, int cells, Color c1, Color c2)
{
	DrawPlane(_size, cells, c1, c2, c1, c2);
}
void DrawPlane(Vector2 _size, int cells, Color c1, Color c2, Color c3)
{
	DrawPlane(_size, cells, c1, c2, c3, c2);
}
void DrawPlane(Vector2 _size, int cells, Color c1, Color c2, Color c3, Color c4)
{

	std::vector<std::vector<Vertex4D>> points;
	for (int x = 0; x < cells + 1; x++)
	{
		points.push_back(std::vector<Vertex4D>());
		for (int y = 0; y < cells + 1; y++)
		{
			points[x].push_back(Vertex4D(Vector4(x * _size.x - ((_size.x * cells - 1) / 2), 0, y * _size.y - ((_size.y * cells - 1) / 2), 1), c1));
			
			Color c = c1;
			Color yCol;
			Color xCol;
			float xRatio = x / ((float)cells + 1);
			float yRatio = y / ((float)cells + 1);
			xCol = Color::CLerp(c1, c2, xRatio * 255);
			yCol = Color::CLerp(c3, c4, xRatio * 255);
			c = Color::CLerp(xCol, yCol, yRatio * 255);
			points[x][y].vertColor = c;
			Vector4 vec = points[x][y].point;

		}
	}
	for (int x = 0; x < cells; x++)
	{
		for (int y = 0; y < cells; y++)
		{
			if (x == cells - 1 && y < cells - 1)
			{

				DrawShaderLine(points[x][y], points[x][y + 1]);

			}
			else if (y == cells - 1 && x < cells - 1)
			{
				DrawShaderLine(points[x][y], points[x + 1][y]);

			}
			else if (x < cells - 1 && y < cells - 1)
			{
				DrawShaderLine(points[x][y], points[x + 1][y]);
				DrawShaderLine(points[x][y], points[x][y + 1]);
			}
		}
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

