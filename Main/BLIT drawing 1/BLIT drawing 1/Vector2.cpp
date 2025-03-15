#include "Vector2.h"

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2 Vector2::operator+(Vector2 const& _ref)
{

	Vector2 res;
	res.x = this->x + _ref.x;
	res.y = this->y + _ref.y;
	return res;
}
Vector2 Vector2::operator-(Vector2 const& _ref)
{
	Vector2 res;
	res.x = this->x - _ref.x;
	res.y = this->y - _ref.y;
	return res;
}
Vector2 Vector2::operator=(Vector2 const& _ref)
{
	this->x = _ref.x;
	this->y = _ref.y;
	return *this;
}
bool Vector2::operator==(Vector2 const& _ref)
{
	if (this == &_ref) return true;
	if (_ref.x == this->x && _ref.y == this->y) return true;
	return false;
}
Vector2 Vector2::operator/(Vector2 const& _ref)
{
	Vector2 res;
	res.x = this->x / _ref.x;
	res.y = this->y / _ref.y;
	return res;
}
Vector2 Vector2::operator*(Vector2 const& _ref)
{
	Vector2 res;
	res.x = this->x * _ref.x;
	res.y = this->y * _ref.y;
	return res;
}
Vector2 Vector2::operator/(int const& _ref)
{
	Vector2 res;
	res.x = this->x / _ref;
	res.y = this->y / _ref;
	return res;
}
Vector2 Vector2::operator*(int const& _ref)
{
	Vector2 res;
	res.x = this->x * _ref;
	res.y = this->y * _ref;
	return res;
}
Vector2 Vector2::operator/(float const& _ref)
{
	Vector2 res;
	res.x = this->x / _ref;
	res.y = this->y / _ref;
	return res;
}
Vector2 Vector2::operator*(float const& _ref)
{
	Vector2 res;
	res.x = this->x * _ref;
	res.y = this->y * _ref;
	return res;
}
std::string Vector2::ToString()
{
	return std::to_string(x) + ", " + std::to_string(y);
}

Vector2 Vector2::Zero() { return Vector2(0, 0); }
Vector2 Vector2::One() { return Vector2(1, 1); }
Vector2 Vector2::Left() { return Vector2(-1, 0); }
Vector2 Vector2::Right() { return Vector2(1, 0); }
Vector2 Vector2::Up() { return Vector2(0, 1); }
Vector2 Vector2::Down() { return Vector2(0, -1); }