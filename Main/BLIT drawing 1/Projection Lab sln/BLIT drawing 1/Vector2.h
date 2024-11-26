#pragma once
class Vector2
{
public:
	float x = 0;
	float y = 0;
	Vector2(float _x, float _y);
	Vector2();

	Vector2 operator+(Vector2 const& _ref);
	Vector2 operator-(Vector2 const& _ref);
	Vector2 operator=(Vector2 const& _ref);
	bool operator==(Vector2 const& _ref);
	Vector2 operator/(Vector2 const& _ref);
	Vector2 operator*(Vector2 const& _ref);
	Vector2 operator/(int const& _ref);
	Vector2 operator*(int const& _ref);
	Vector2 operator/(float const& _ref);
	Vector2 operator*(float const& _ref);

	static Vector2 Zero();
	static Vector2 One();
	static Vector2 Left();
	static Vector2 Right();
	static Vector2 Up();
	static Vector2 Down();

};
