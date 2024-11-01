#pragma once
#include "RasterSurface.h"
class BLITVars
{
public:
	#define ImageWidth 500
	#define ImageHeight 500

	
	struct Vector2Int
	{
		int x;
		int y;
		Vector2Int(int _x, int _y)
		{
			x = _x;
			y = _y;
		}
		Vector2Int()
		{
			x = 0;
			y = 0;
		}
		~Vector2Int()
		{

		}
		Vector2Int& operator+(Vector2Int const& _ref) {
			if (this != &_ref) {
				this->x = this->x + _ref.x;
				this->y = this->y + _ref.y;
			}
			return *this;
		}
		Vector2Int& operator-(Vector2Int const& _ref) {
			if (this != &_ref) {
				this->x = this->x - _ref.x;
				this->y = this->y - _ref.y;
			}
			return *this;
		}
		Vector2Int operator=(Vector2Int const& _ref) {
			if (this != &_ref) {
				this->x = _ref.x;
				this->y = _ref.y;
			}
			return *this;
		}
		bool operator==(Vector2Int const& _ref) {
			if (this == &_ref) return true;
			if (_ref.x == this->x && _ref.y == this->y) return true;

			return false;
		}
		Vector2Int operator/(Vector2Int const& _ref) {
			this->x = this->x / _ref.x;
			this->y = this->y / _ref.y;
			return *this;
		}
		Vector2Int operator*(Vector2Int const& _ref) {
			this->x = this->x * _ref.x;
			this->y = this->y * _ref.y;
			return *this;
		}
		Vector2Int operator/(int const& _ref) {
			this->x = this->x / _ref;
			this->y = this->y / _ref;
			return *this;
		}
		Vector2Int operator*(int const& _ref) {
			this->x = this->x * _ref;
			this->y = this->y * _ref;
			return *this;
		}
		Vector2Int operator/(float const& _ref) {
			this->x = this->x / _ref;
			this->y = this->y / _ref;
			return *this;
		}
		Vector2Int operator*(float const& _ref) {
			this->x = this->x * _ref;
			this->y = this->y * _ref;
			return *this;
		}
	};
	struct Vector2
	{
		float x = 0;
		float y = 0;
		Vector2(float _x, float _y)
		{
			x = _x;
			y = _y;
		}
		Vector2()
		{
			x = 0;
			y = 0;
		}
		~Vector2()
		{

		}
		Vector2& operator+(Vector2 const& _ref) {
			if (this != &_ref) {
				this->x = this->x + _ref.x;
				this->y = this->y + _ref.y;
			}
			return *this;
		}
		Vector2& operator-(Vector2 const& _ref) {
			if (this != &_ref) {
				this->x = this->x - _ref.x;
				this->y = this->y - _ref.y;
			}
			return *this;
		}
		Vector2 operator=(Vector2 const& _ref) {
			if (this != &_ref) {
				this->x = _ref.x;
				this->y = _ref.y;
			}
			return *this;
		}
		bool operator==(Vector2 const& _ref) {
			if (this == &_ref) return true;
			if (_ref.x == this->x && _ref.y == this->y) return true;
			
			return false;
		}
		Vector2 operator/(Vector2 const& _ref) {
			this->x = this->x / _ref.x;
			this->y = this->y / _ref.y;
			return *this;
		}
		Vector2 operator*(Vector2 const& _ref) {
			this->x = this->x * _ref.x;
			this->y = this->y * _ref.y;
			return *this;
		}
		Vector2 operator/(int const& _ref) {
			this->x = this->x / _ref;
			this->y = this->y / _ref;
			return *this;
		}
		Vector2 operator*(int const& _ref) {
			this->x = this->x * _ref;
			this->y = this->y * _ref;
			return *this;
		}
		Vector2 operator/(float const& _ref) {
			this->x = this->x / _ref;
			this->y = this->y / _ref;
			return *this;
		}
		Vector2 operator*(float const& _ref) {
			this->x = this->x * _ref;
			this->y = this->y * _ref;
			return *this;
		}
	};

	int GetArraySize();
	int GetX(int _total);
	int GetY(int _total);

	static bool InScreenBounds(Vector2Int _pos)
	{
		if (_pos.y > ImageHeight - 1 || _pos.x > ImageWidth - 1) return false;
		return true;
	}
	static int PosToIndex(Vector2Int _pos) 
	{
		return _pos.x + (_pos.y * ImageWidth);
	}
	static unsigned int BGRAtoRGBA(unsigned int _original) 
	{
		unsigned int R = _original & 0x000000FF;
		unsigned int G = _original & 0x00000000;
		unsigned int B = _original & 0x000000FF;
		unsigned int A = _original & 0xFF000000;



		return B;
	}
private:

};


