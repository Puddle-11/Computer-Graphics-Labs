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
Vector4 Vector4::Normalize()
{
	float xPow = x * x;
	float yPow = y * y;
	float zPow = z * z;
	float length = sqrt(xPow + yPow + zPow);

	return Vector4(x / length, y / length, z / length, w);
}
Vector4 Vector4::operator+(Vector4 const& _ref)
{

	Vector4 res;
	res.x = this->x + _ref.x;
	res.y = this->y + _ref.y;
	res.z = this->z + _ref.z;
	res.w = this->w + _ref.w;

	return res;
}
Vector4 Vector4::operator-(Vector4 const& _ref)
{
	Vector4 res;
	res.x = this->x - _ref.x;
	res.y = this->y - _ref.y;
	res.z = this->z - _ref.z;
	res.w = this->w - _ref.w;

	return res;
}
Vector4 Vector4::operator=(Vector4 const& _ref)
{
	this->x = _ref.x;
	this->y = _ref.y;
	this->z = _ref.z;
	this->w = _ref.w;

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
Vector4 Vector4::operator*(Matrix m)
{
	Vector4 Res;
	float sums[4]
	{
		0,0,0,0
	};
	float originalVals[4]{
		this->x,
		this->y,
		this->z,
		this->w,
	};
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			float mVal = m.matrixValues[x][y];
			float oVal = originalVals[x];
			sums[y] += mVal * oVal;


		}

	}
	Res.x = sums[0];
	Res.y = sums[1];
	Res.z = sums[2];
	Res.w = sums[3];


	return Res;
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
std::string Vector4::ToString()
{
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
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