#pragma once
class Vector3
{
public:
	float x = 0;
	float y = 0;
	float z = 0;
	Vector3();
	Vector3(float _x, float _y, float _z);
	Vector3 operator+(Vector3 const& _ref);
	Vector3 operator-(Vector3 const& _ref);
	Vector3 operator=(Vector3 const& _ref);
	bool operator==(Vector3 const& _ref);
	Vector3 operator/(Vector3 const& _ref);
	Vector3 operator*(Vector3 const& _ref);
	Vector3 operator/(int const& _ref);
	Vector3 operator*(int const& _ref);
	Vector3 operator/(float const& _ref);
	Vector3 operator*(float const& _ref);
	static Vector3 Zero();
	static Vector3 One();
	static Vector3 Left();
	static Vector3 Right();
	static Vector3 Up();
	static Vector3 Down();
	static Vector3 Forward();
	static Vector3 Backward();
};

