#include "Vector2Int.h"

Vector2Int::Vector2Int(int _x, int _y)
{
	x = _x;
	y = _y;
}
Vector2Int::Vector2Int()
{
	x = 0;
	y = 0;
}
Vector2Int Vector2Int::operator+(Vector2Int const& _ref)
{

	Vector2Int res;
	res.x = this->x + _ref.x;
	res.y = this->y + _ref.y;
	return res;
}
Vector2Int Vector2Int::operator-(Vector2Int const& _ref)
{
	Vector2Int res;
	res.x = this->x - _ref.x;
	res.y = this->y - _ref.y;
	return res;
}
Vector2Int Vector2Int::operator=(Vector2Int const& _ref)
{
	this->x = _ref.x;
	this->y = _ref.y;
	return *this;
}
bool Vector2Int::operator==(Vector2Int const& _ref)
{
	if (this == &_ref) return true;
	if (_ref.x == this->x && _ref.y == this->y) return true;
	return false;
}
Vector2Int Vector2Int::operator/(Vector2Int const& _ref)
{
	Vector2Int res;
	res.x = this->x / _ref.x;
	res.y = this->y / _ref.y;
	return res;
}
Vector2Int Vector2Int::operator*(Vector2Int const& _ref)
{
	Vector2Int res;
	res.x = this->x * _ref.x;
	res.y = this->y * _ref.y;
	return res;
}
Vector2Int Vector2Int::operator/(int const& _ref)
{
	Vector2Int res;
	res.x = (int)(this->x / _ref);
	res.y = (int)(this->y / _ref);
	return res;
}
Vector2Int Vector2Int::operator*(int const& _ref)
{
	Vector2Int res;
	res.x = (int)(this->x * _ref);
	res.y = (int)(this->y * _ref);
	return res;
}
Vector2Int Vector2Int::operator/(float const& _ref)
{
	Vector2Int res;
	res.x = (int)(this->x / _ref);
	res.y = (int)(this->y / _ref);
	return res;
}
Vector2Int Vector2Int::operator*(float const& _ref)
{
	Vector2Int res;
	res.x = (int)(this->x * _ref);
	res.y = (int)(this->y * _ref);
	return res;
}
float Vector2Int::Distance(Vector2Int _pos1, Vector2Int _pos2)
{
	float res = 0;
	float p1Dif = (float)(_pos2.y - _pos1.y) * (float)(_pos2.y - _pos1.y);
	float p2Dif = (float)(_pos2.x - _pos1.x) * (float)(_pos2.x - _pos1.x);
	res = sqrt(p1Dif + p2Dif);
	return res;
}
std::string Vector2Int::ToString()
{
	return std::to_string(x) + ", " + std::to_string(y);
}
Vector2Int Vector2Int::Zero() { return Vector2Int(0, 0); }
Vector2Int Vector2Int::One() { return Vector2Int(1, 1); }
Vector2Int Vector2Int::Up() { return Vector2Int(0, 1); }
Vector2Int Vector2Int::Down() { return Vector2Int(0, -1); }
Vector2Int Vector2Int::Left() { return Vector2Int(-1, 0); }
Vector2Int Vector2Int::Right() { return Vector2Int(1, 0); }