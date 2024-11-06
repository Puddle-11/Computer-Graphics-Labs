#pragma once
#include "Vector2Int.h"
#include "Color.h"
class VertexScreen
{
public:
	Vector2Int point;
	Color vertColor;
	VertexScreen();
	VertexScreen(Vector2Int _point, Color c);
	VertexScreen(Vector2Int _point);
	VertexScreen(Color c);
private:

};
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