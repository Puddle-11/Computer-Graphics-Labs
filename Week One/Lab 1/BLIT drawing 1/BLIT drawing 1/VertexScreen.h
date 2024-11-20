#pragma once
#include "Vector2Int.h"
#include "Color.h"
#include "Vector3.h"
class VertexScreen
{
public:
	Vector2Int point;
	Color vertColor;
	float z;
	Vector3 normal;
	VertexScreen();
	VertexScreen(Vector2Int _point, Color c);
	VertexScreen(Vector2Int _point);
	VertexScreen(Color c);
	void SetZ(float _val);
	float GetZ();
private:

};
void VertexScreen::SetZ(float _val)
{
	z = _val;
}
float VertexScreen::GetZ()
{
	return z;
}

VertexScreen::VertexScreen()
{
	point = Vector2Int::Zero();
	vertColor = Color::White();
}
VertexScreen::VertexScreen(Vector2Int _point, Color c)
{
	point = _point;
	vertColor = c;
}
VertexScreen::VertexScreen(Vector2Int _point)
{
	point = _point;
	vertColor = Color::White();
}
VertexScreen::VertexScreen(Color c)
{
	point = Vector2Int::Zero();
	vertColor = c;
}