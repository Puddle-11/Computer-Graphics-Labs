#pragma once
class Vector4
{
public:
	float x;
	float y;
	float z;
	float w;
	Vector4();
	Vector4(float _x, float _y, float _z, float _w);
	Vector4 operator+(Vector4 const& _ref);
	Vector4 operator-(Vector4 const& _ref);
	Vector4 operator=(Vector4 const& _ref);
	bool operator==(Vector4 const& _ref);
	Vector4 operator/(Vector4 const& _ref);
	Vector4 operator*(Vector4 const& _ref);
	Vector4 operator/(int const& _ref);
	Vector4 operator*(int const& _ref);
	Vector4 operator/(float const& _ref);
	Vector4 operator*(float const& _ref);
	float Total();

	static float DotProduct(Vector4 v1, Vector4 v2);

	static Vector4 Zero();
	static Vector4 One();
	static Vector4 Left();
	static Vector4 Right();
	static Vector4 Up();
	static Vector4 Down();
	static Vector4 Forward();
	static Vector4 Backward();
	static Vector4 Ana();
	static Vector4 Kata();
};