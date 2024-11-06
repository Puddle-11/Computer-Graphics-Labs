#include "Vector4.h"
Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}
Vector4::Vector4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}
Vector4 Vector4::operator+(Vector4 const& _ref)
{

	Vector4 res;
	res.x = this->x + _ref.x;
	res.y = this->y + _ref.y;
	res.z = this->z + _ref.z;
	res.z = this->z + _ref.w;

	return res;
}
Vector4 Vector4::operator-(Vector4 const& _ref)
{
	Vector4 res;
	res.x = this->x - _ref.x;
	res.y = this->y - _ref.y;
	res.z = this->z - _ref.z;
	res.z = this->z - _ref.w;

	return res;
}
Vector4 Vector4::operator=(Vector4 const& _ref)
{
	this->x = _ref.x;
	this->y = _ref.y;
	this->z = _ref.z;
	this->z = _ref.w;

	return *this;
}
bool Vector4::operator==(Vector4 const& _ref)
{
	if (this == &_ref) return true;
	if (_ref.x == this->x && _ref.y == this->y && _ref.z == this->z && _ref.w == this->w) return true;
	return false;
}
Vector4 Vector4::operator/(Vector4 const& _ref)
{
	Vector4 res;
	res.x = this->x / _ref.x;
	res.y = this->y / _ref.y;
	res.z = this->z / _ref.z;
	res.w = this->w / _ref.w;

	return res;
}
Vector4 Vector4::operator*(Vector4 const& _ref)
{
	Vector4 res;
	res.x = this->x * _ref.x;
	res.y = this->y * _ref.y;
	res.z = this->z * _ref.z;
	res.w = this->w * _ref.w;

	return res;
}
Vector4 Vector4::operator/(int const& _ref)
{
	Vector4 res;
	res.x = this->x / _ref;
	res.y = this->y / _ref;
	res.z = this->z / _ref;
	res.w = this->w / _ref;

	return res;
}
Vector4 Vector4::operator*(int const& _ref)
{
	Vector4 res;
	res.x = this->x * _ref;
	res.y = this->y * _ref;
	res.z = this->z * _ref;
	res.w = this->w * _ref;

	return res;
}
Vector4 Vector4::operator/(float const& _ref)
{
	Vector4 res;
	res.x = this->x / _ref;
	res.y = this->y / _ref;
	res.z = this->z / _ref;
	res.w = this->w / _ref;

	return res;
}
Vector4 Vector4::operator*(float const& _ref)
{
	Vector4 res;
	res.x = this->x * _ref;
	res.y = this->y * _ref;
	res.z = this->z * _ref;
	res.w = this->w * _ref;

	return res;
}

float Vector4::Total() { return x + y + z + w; }

float Vector4::DotProduct(Vector4 v1, Vector4 v2) { return (v1 * v2).Total(); }

Vector4 Vector4::Zero() { return Vector4(0, 0, 0, 0); }
Vector4 Vector4::One() { return Vector4(1, 1, 1, 1); }
Vector4 Vector4::Left() { return Vector4(-1, 0, 0, 0); }
Vector4 Vector4::Right() { return Vector4(1, 0, 0, 0); }
Vector4 Vector4::Up() { return Vector4(0, 1, 0, 0); }
Vector4 Vector4::Down() { return Vector4(0, -1, 0, 0); }
Vector4 Vector4::Forward() { return Vector4(0, 0, 1, 0); }
Vector4 Vector4::Backward() { return Vector4(0, 0, -1, 0); }
Vector4 Vector4::Ana() { return Vector4(0, 0, 0, 1); }
Vector4 Vector4::Kata() { return Vector4(0, 0, 0, -1); }