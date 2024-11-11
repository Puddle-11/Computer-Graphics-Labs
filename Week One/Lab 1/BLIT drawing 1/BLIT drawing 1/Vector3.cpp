#include "Vector3.h"
Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}
Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}
Vector3 Vector3::operator+(Vector3 const& _ref)
{

	Vector3 res;
	res.x = this->x + _ref.x;
	res.y = this->y + _ref.y;
	res.z = this->z + _ref.z;
	return res;
}
Vector3 Vector3::operator-(Vector3 const& _ref)
{
	Vector3 res;
	res.x = this->x - _ref.x;
	res.y = this->y - _ref.y;
	res.z = this->z - _ref.z;

	return res;
}
Vector3 Vector3::operator=(Vector3 const& _ref)
{
	this->x = _ref.x;
	this->y = _ref.y;
	this->z = _ref.z;

	return *this;
}
bool Vector3::operator==(Vector3 const& _ref)
{
	if (this == &_ref) return true;
	if (_ref.x == this->x && _ref.y == this->y && _ref.z == this->z) return true;
	return false;
}
Vector3 Vector3::operator/(Vector3 const& _ref)
{
	Vector3 res;
	res.x = this->x / _ref.x;
	res.y = this->y / _ref.y;
	res.z = this->z / _ref.z;

	return res;
}
Vector3 Vector3::operator*(Vector3 const& _ref)
{
	Vector3 res;
	res.x = this->x * _ref.x;
	res.y = this->y * _ref.y;
	res.z = this->z * _ref.z;

	return res;
}
Vector3 Vector3::operator/(int const& _ref)
{
	Vector3 res;
	res.x = this->x / _ref;
	res.y = this->y / _ref;
	res.z = this->z / _ref;

	return res;
}
Vector3 Vector3::operator*(int const& _ref)
{
	Vector3 res;
	res.x = this->x * _ref;
	res.y = this->y * _ref;
	res.z = this->z * _ref;

	return res;
}
Vector3 Vector3::operator/(float const& _ref)
{
	Vector3 res;
	res.x = this->x / _ref;
	res.y = this->y / _ref;
	res.z = this->z / _ref;
	return res;
}
Vector3 Vector3::operator*(float const& _ref)
{
	Vector3 res;
	res.x = this->x * _ref;
	res.y = this->y * _ref;
	res.z = this->z * _ref;
	return res;
}
std::string Vector3::ToString()
{
	std::string res = "";
	res = std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
	return res;

}
Vector3 Vector3::operator*(Matrix const& _ref)
{

	Vector3 res;
	res.x = (x * _ref.matrixValues[0][0]) + (y * _ref.matrixValues[1][0]) + (z * _ref.matrixValues[2][0]);
	res.y = (x * _ref.matrixValues[0][1]) + (y * _ref.matrixValues[1][1]) + (z * _ref.matrixValues[2][1]);
	res.z = (x * _ref.matrixValues[0][2]) + (y * _ref.matrixValues[1][2]) + (z * _ref.matrixValues[2][2]);
	return res;

}

 Vector3 Vector3::Zero() { return Vector3(0, 0, 0); }
 Vector3 Vector3::One() { return Vector3(1, 1, 1); }
 Vector3 Vector3::Left() { return Vector3(-1, 0, 0); }
 Vector3 Vector3::Right() { return Vector3(1, 0, 0); }
 Vector3 Vector3::Up() { return Vector3(0, 1, 0); }
 Vector3 Vector3::Down() { return Vector3(0, -1, 0); }
 Vector3 Vector3::Forward() { return Vector3(0, 0, 1); }
 Vector3 Vector3::Backward() { return Vector3(0, 0, -1); }