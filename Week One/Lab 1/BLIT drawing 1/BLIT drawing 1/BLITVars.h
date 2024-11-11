#pragma once
#include <cmath>

#include "GlobalDefines.h"

static Vector2Int IndexToPos(int _index, int _width);
static Vector2Int IndexToPos(int _index);
static bool InScreenBounds(Vector2Int _pos);
int ToIndex(Vector2Int _pos);
int ToIndex(Vector2Int _pos, int _width);

int ToIndex(Vector2Int _pos, int _width)
{
	return _pos.x + (_pos.y * _width);
}
int ToIndex(Vector2Int _pos) {
	return ToIndex(_pos, ImageWidth);
}
static bool InScreenBounds(Vector2Int _pos)
{
	if (_pos.y > ImageHeight - 1 || _pos.x > ImageWidth - 1 || _pos.x < 0 || _pos.y < 0) return false;
	return true;
}
static Vector2Int IndexToPos(int _index)
{
	return IndexToPos(_index, ImageWidth);
}
static Vector2Int IndexToPos(int _index, int _width)
{
	Vector2Int res = Vector2Int();
	res.x = _index % _width;
	res.y = (int)floor((float)_index / (float)_width);
	return res;
}

static Vector4 ScreenToNDC()
{

}
static float lerp(float p1, float p2, float ratio)
{
	return p1 + (p2 - p1) * ratio;
}
