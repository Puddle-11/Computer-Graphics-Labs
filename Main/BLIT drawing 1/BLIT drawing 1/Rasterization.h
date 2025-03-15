#pragma once
#include "Shader.h"
#include "Canvas.h"
#include "Mesh.h"
#include "Vector2.h"
#include "Vector3.h"
#include "ScreenBounds.h"
#include <vector>
void DrawShaderLine(Vertex4D& p1, Vertex4D& p2);
void DrawMesh(Mesh& m, bool useColor = false);


Vector2Int NDCtoScreen(Vector4 _NDCpos /*Between (-1,-1,-1), (1,1,1)*/);
Vector2Int NDCtoScreen(Vector4 _NDCpos, ScreenBounds _bounds);
void DrawPlane(Vector2 _size, int cells, Color c1);
void DrawPlane(Vector2 _size, int cells, Color c1, Color c2);
void DrawPlane(Vector2 _size, int cells, Color c1, Color c2, Color c3);
void DrawPlane(Vector2 _size, int cells, Color c1, Color c2, Color c3, Color c4);
void DrawShaderTriangle(Vertex4D p1, Vertex4D p2, Vertex4D p3, bool useColor = false, unsigned int* texture = nullptr, ScreenBounds scrbnds = ScreenBounds(0, 0), int textureSize = 0);





Vector2Int NDCtoScreen(Vector4 _NDCpos /*Between (-1,-1,-1), (1,1,1)*/)
{
	return NDCtoScreen(_NDCpos, ScreenBounds(ImageWidth, ImageHeight));
}
Vector2Int NDCtoScreen(Vector4 _NDCpos, ScreenBounds _bounds)
{
	//Filter x point to lie between -1, 1 to 0, 2
	_NDCpos.x += 1;
	_NDCpos.y += 1;


	_NDCpos.x *= _bounds.Width / 2;
	_NDCpos.y = _bounds.Height - _NDCpos.y * (_bounds.Height / 2);

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

void DrawMesh(Mesh& m, bool useColor)
{
	for (int i = 0; i < m.triCount; i++)
	{
		if (m.triangles[i] >= 0 || m.triangles[i] < m.vertCount)
		{
			if (i % 3 == 0)
			{

				DrawShaderTriangle(m.verticies[m.triangles[i]], m.verticies[m.triangles[i + 1]], m.verticies[m.triangles[i + 2]], useColor, m.texture, m.scrBounds, m.textureSize);
			}
		}
	}
}

void DrawShaderTriangle(Vertex4D p1, Vertex4D p2, Vertex4D p3, bool useColor, unsigned int* texture, ScreenBounds scrbnds, int textureSize)
{

	Color c;
	Vertex4D cpy1 = p1;
	Vertex4D cpy2 = p2;
	Vertex4D cpy3 = p3;
	Vector3 planeNormal = Cross(p1.point-p2.point, p1.point -p3.point).Normalize();
	if (VertexShader)
	{
		VertexShader(cpy1);
		VertexShader(cpy2);
		VertexShader(cpy3);
	}

	if (cpy1.point.w < NearPlane || cpy2.point.w < NearPlane || cpy3.point.w < NearPlane) return;


	//coordinates are relative using p1 as origin, p1->p2 as beta and p1->p3 as delta

	VertexScreen sp1;
	VertexScreen sp2;
	VertexScreen sp3;
	Vector2Int min;
	Vector2Int max;

	sp1.point = NDCtoScreen(cpy1.point);
	sp2.point = NDCtoScreen(cpy2.point);
	sp3.point = NDCtoScreen(cpy3.point);

	sp1.normal = p1.normal;
	sp2.normal = p2.normal;
	sp3.normal = p3.normal;

	//if (!InScreenBounds(sp1.point) || !InScreenBounds(sp2.point) || !InScreenBounds(sp3.point)) return;
	min.x = std::min(sp1.point.x, sp2.point.x);
	min.y = std::min(sp1.point.y, sp2.point.y);

	max.x = std::max(sp1.point.x, sp2.point.x);
	max.y = std::max(sp1.point.y, sp2.point.y);

	min.x = min.x > sp3.point.x ? sp3.point.x : min.x;
	min.y = min.y > sp3.point.y ? sp3.point.y : min.y;

	max.x = max.x < sp3.point.x ? sp3.point.x : max.x;
	max.y = max.y < sp3.point.y ? sp3.point.y : max.y;
	sp1.vertColor = c;
	sp2.vertColor = c;
	sp3.vertColor = c;
	float alpha;

	for (int x = min.x; x < max.x; x++)
	{
		for (int y = min.y; y < max.y; y++)
		{
			Vector3 p;
			Vector2Int tp = Vector2Int(x, y);


			p.x = (sp2.point.y - sp3.point.y) * (tp.x - sp3.point.x) + (sp3.point.x - sp2.point.x) * (tp.y - sp3.point.y);
			p.x = p.x / ((sp2.point.y - sp3.point.y) * (sp1.point.x - sp3.point.x) + (sp3.point.x - sp2.point.x) * (sp1.point.y - sp3.point.y));

			p.y = (sp3.point.y - sp1.point.y) * (tp.x - sp3.point.x) + (sp1.point.x - sp3.point.x) * (tp.y - sp3.point.y);
			p.y = p.y / ((sp2.point.y - sp3.point.y) * (sp1.point.x - sp3.point.x) + (sp3.point.x - sp2.point.x) * (sp1.point.y - sp3.point.y));
			p.z = 1 - p.x - p.y;

			alpha = (cpy1.point.w * p.x + cpy2.point.w * p.y + cpy3.point.w * p.z);

			VertexScreen currVert;
			currVert.normal = planeNormal;
			Vector4 worldPos;

			if (p.x >= 0 && p.y >= 0 && p.z >= 0)
			{

				if (alpha < AccessPixelDepth(x, y, mainBounds, depth_pixels))
				{
					worldPos = (p1.point * p.x) + (p2.point * p.y) + (p3.point * p.z);
					currVert.worldPos = Vector3(worldPos.x, worldPos.y, worldPos.z);
					if (useColor)
					{
						Color p1c = p1.vertColor;
						Color p2c = p2.vertColor;
						Color p3c = p3.vertColor;
						unsigned int wRed = (p1c.GetRed() * p.x + p2c.GetRed() * p.y + p3c.GetRed() * p.z);
						unsigned int wGreen = (p1c.GetGreen() * p.x + p2c.GetGreen() * p.y + p3c.GetGreen() * p.z);
						unsigned int wBlue = (p1c.GetBlue() * p.x + p2c.GetBlue() * p.y + p3c.GetBlue() * p.z);

						c.SetGreen(wGreen);
						c.SetRed(wRed);
						c.SetBlue(wBlue);
					}
					else
					{
						float yr = (cpy1.uv.y * p.x + cpy2.uv.y * p.y + cpy3.uv.y * p.z);
						float xr = (cpy1.uv.x * p.x + cpy2.uv.x * p.y + cpy3.uv.x * p.z);
						Vector2Int pos = Vector2Int((int)(xr * scrbnds.Width), (int)(yr * scrbnds.Height));
						c.SetARGB(Access(pos, scrbnds, texture).GetARGB());
					}
					currVert.point = tp;
					currVert.vertColor = c;
					if (PixelShader)
					{
						PixelShader(currVert);
					}
					Plot(currVert.point, currVert.vertColor, 0);
					PlotDepth(tp, alpha);
				}
			}
		}
	}
}

void DrawShaderLine(Vertex4D& p1, Vertex4D& p2)
{

	Vertex4D cpy1 = p1;
	Vertex4D cpy2 = p2;

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

void PlotShadedPoint(Vertex4D _p1)
{
	if (VertexShader)
	{
		VertexShader(_p1);
	}
	VertexScreen sp1;
	sp1 = NDCtoScreen(_p1.point);
	sp1.vertColor = _p1.vertColor;
	if (_p1.point.w < NearPlane) return;

	if (PixelShader)
	{
		PixelShader(sp1);
	}
	Plot(sp1.point, sp1.vertColor, 0);
}