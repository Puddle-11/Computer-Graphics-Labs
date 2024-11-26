#pragma once
#include <string>
class Vector2Int
{
public:
	int x;
	int y;

	Vector2Int(int _x, int _y);
	Vector2Int();
	Vector2Int operator+(Vector2Int const& _ref);
	Vector2Int operator-(Vector2Int const& _ref);
	Vector2Int operator=(Vector2Int const& _ref);
	bool	   operator==(Vector2Int const& _ref);
	Vector2Int operator/(Vector2Int const& _ref);
	Vector2Int operator*(Vector2Int const& _ref);
	Vector2Int operator/(int const& _ref);
	Vector2Int operator*(int const& _ref);
	Vector2Int operator/(float const& _ref);
	Vector2Int operator*(float const& _ref);
	static float Distance(Vector2Int _pos1, Vector2Int _pos2);
	std::string ToString();
	static Vector2Int Zero();
	static Vector2Int One();
	static Vector2Int Up();
	static Vector2Int Down();
	static Vector2Int Left();
	static Vector2Int Right();

};