#pragma once

#include "RasterSurface.h"
#include <cmath>
#include <iostream>
#include <numeric>
#include	<string>
class BLITVars
{
public:
#define ImageWidth 700
#define ImageHeight 500



	
	struct ScreenBounds {
		ScreenBounds(unsigned int _Width, unsigned int _Height)
		{
			Height = _Height;
			Width = _Width;
		}
		ScreenBounds()
		{
			Width = 0;
			Height = 0;
		}
		unsigned int Width;
		unsigned int Height;
	};








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

		int ToIndex(int _width)
		{
			return x + (y * _width);
		}
		int ToIndex() {
			return ToIndex(ImageWidth);
		}

		Vector2Int operator+(Vector2Int const& _ref) {

			Vector2Int res;
			res.x = this->x + _ref.x;
			res.y = this->y + _ref.y;
			return res;
		}
		Vector2Int& operator-(Vector2Int const& _ref) {
			Vector2Int res;
			res.x = this->x - _ref.x;
			res.y = this->y - _ref.y;
			return res;
		}
		Vector2Int operator=(Vector2Int const& _ref) {
			this->x = _ref.x;
			this->y = _ref.y;
			return *this;
		}
		bool operator==(Vector2Int const& _ref) {
			if (this == &_ref) return true;
			if (_ref.x == this->x && _ref.y == this->y) return true;
			return false;
		}
		Vector2Int operator/(Vector2Int const& _ref) {
			Vector2Int res;
			res.x = this->x / _ref.x;
			res.y = this->y / _ref.y;
			return res;
		}
		Vector2Int operator*(Vector2Int const& _ref) {
			Vector2Int res;
			res.x = this->x * _ref.x;
			res.y = this->y * _ref.y;
			return res;
		}
		Vector2Int operator/(int const& _ref) {
			Vector2Int res;
			res.x = this->x / _ref;
			res.y = this->y / _ref;
			return res;
		}
		Vector2Int operator*(int const& _ref) {
			Vector2Int res;
			res.x = this->x * _ref;
			res.y = this->y * _ref;
			return res;
		}
		Vector2Int operator/(float const& _ref) {
			Vector2Int res;
			res.x = this->x / _ref;
			res.y = this->y / _ref;
			return res;
		}
		Vector2Int operator*(float const& _ref) {
			Vector2Int res;
			res.x = this->x * _ref;
			res.y = this->y * _ref;
			return res;
		}
		static float Distance(Vector2Int _pos1, Vector2Int _pos2)
		{
			float res = 0;
			float p1Dif = (_pos2.y - _pos1.y) * (_pos2.y - _pos1.y);
			float p2Dif = (_pos2.x - _pos1.x) * (_pos2.x - _pos1.x);
			res = sqrt(p1Dif + p2Dif);
			return res;
		}
		static Vector2Int Zero() { return Vector2Int(0, 0); }
		static Vector2Int One() { return Vector2Int(1, 1); }
		static Vector2Int Up() { return Vector2Int(0, 1); }
		static Vector2Int Down() { return Vector2Int(0, -1); }
		static Vector2Int Left() { return Vector2Int(-1, 0); }
		static Vector2Int Right() { return Vector2Int(1, 0); }
		std::string ToString()
		{
			return std::to_string(x) + ", " + std::to_string(y);
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


	static bool InScreenBounds(Vector2Int _pos)
	{
		if (_pos.y > ImageHeight - 1 || _pos.x > ImageWidth - 1 || _pos.x < 0 || _pos.y < 0) return false;
		return true;
	}

	static Vector2Int IndexToPos(int _index)
	{
		return IndexToPos(_index, ImageWidth);
	}
	static Vector2Int IndexToPos(int _index, int _width)
	{
		Vector2Int res = Vector2Int();
		res.x = _index % _width;
		res.y = floor((float)_index / (float)_width);
		return res;
	}

private:

};


class Color
{
private:

	//i use two values for the sake of speed, and not having to convert everyt ime i want to get a color
	unsigned int ARGBcolor = 0;
	unsigned int ABGRcolor = 0;

public:
	//convert to different formats
	unsigned int ABGRtoARGB(unsigned int _original)
	{
		unsigned int A = _original & 0xFF000000;
		unsigned int B = _original & 0x00FF0000;
		unsigned int G = _original & 0x0000FF00;
		unsigned int R = _original & 0x000000FF;
		B = B >> 16;
		R = R << 16;
		return  R | G | B | A;
	}
	unsigned int ARGBtoABGR(unsigned int _original)
	{
		unsigned int A = _original & 0xFF000000;
		unsigned int R = _original & 0x00FF0000;
		unsigned int G = _original & 0x0000FF00;
		unsigned int B = _original & 0x000000FF;
		B = B << 16;
		R = R >> 16;
		return  R | G | B | A;
	}
	unsigned int ARGBtoBGRA(unsigned int _original) {
		unsigned int A = _original & 0xFF000000;
		unsigned int R = _original & 0x00FF0000;
		unsigned int G = _original & 0x0000FF00;
		unsigned int B = _original & 0x000000FF;
		A = A >> 24;
		R = R >> 8;
		G = G << 8;
		B = B << 24;
		return  R | G | B | A;
	}
	unsigned int BGRAtoARGB(unsigned int _original)
	{
		unsigned int B = _original & 0xFF000000;
		unsigned int G = _original & 0x00FF0000;
		unsigned int R = _original & 0x0000FF00;
		unsigned int A = _original & 0x000000FF;
		B = B >> 24;
		G = G >> 8;
		R = R << 8;
		A = A << 24;
		return  R | G | B | A;
	}
	Color()
	{
		SetARGB(0xFFFF00FF);
	}
	Color(unsigned int _color)
	{
		SetARGB(_color);
	}
	Color(unsigned int _R, unsigned int _G, unsigned  int _B, unsigned int _A)
	{
		SetRed(_R);
		SetBlue(_B);
		SetGreen(_G);
	}
	//Gives a value between 0-255
	unsigned int GetRed() { return (ARGBcolor & 0x00FF0000) >> 16; }
	unsigned int GetGreen() { return (ARGBcolor & 0x0000FF00) >> 8; }
	unsigned int GetBlue() { return (ARGBcolor & 0x000000FF); }
	unsigned int GetAlpha() { return (ARGBcolor & 0xFF000000) >> 24; }

	//Gives the full hex value for that color
	unsigned int GetRawRed() { return ARGBcolor & 0x00FF0000; }
	unsigned int GetRawGreen() { return ARGBcolor & 0x0000FF00; }
	unsigned int GetRawBlue() { return ARGBcolor & 0x000000FF; }
	unsigned int GetRawAlpha() { return ARGBcolor & 0xFF000000; }

	//returns the entire color value in a specific format
	unsigned int GetABGR() { return ABGRcolor; }
	unsigned int GetARGB() { return ARGBcolor; }
	unsigned int GetBGRA() { return ARGBtoBGRA(ARGBcolor); }


	void SetAlpha(unsigned int _alpha)
	{

		if (_alpha > 255) _alpha = 255; //Clamp incoming values
		ARGBcolor = ARGBcolor & 0x00FFFFFF; //remove the blue from the current color
		ABGRcolor = ABGRcolor & 0x00FFFFFF; //remove the blue from the current color
		_alpha = _alpha << 24;
		ARGBcolor = ARGBcolor | _alpha;
		ABGRcolor = ABGRcolor | _alpha;




	}
	void SetBlue(unsigned int _blue)
	{
		//Incoming colors will always be in the 0x000000FF format
		if (_blue > 255) _blue = 255; //Clamp incoming values
		ARGBcolor = ARGBcolor & 0xFFFFFF00; //remove the blue from the current color
		ARGBcolor = ARGBcolor | _blue;
		_blue = _blue << 16;
		ABGRcolor = ABGRcolor & 0xFF00FFFF; //Remove the blue from the current color
		ABGRcolor = ABGRcolor | _blue;
	}
	void SetGreen(unsigned int _green)
	{
		//Incoming colors will always be in the 0x000000FF format
		if (_green > 255) _green = 255; //Clamp incoming values
		_green = _green << 8;
		ARGBcolor = ARGBcolor & 0xFFFF00FF; //remove the blue from the current color
		ARGBcolor = ARGBcolor | _green;
		ABGRcolor = ABGRcolor & 0xFFFF00FF; //Remove the blue from the current color
		ABGRcolor = ABGRcolor | _green;
	}
	void SetRed(unsigned int _red)
	{
		//Incoming colors will always be in the 0x000000FF format
		if (_red > 255) _red = 255; //Clamp incoming values
		ABGRcolor = ABGRcolor & 0xFFFFFF00; //Remove the blue from the current color
		ABGRcolor = ABGRcolor | _red;
		_red = _red << 16;
		ARGBcolor = ARGBcolor & 0xFF00FFFF; //remove the blue from the current color
		ARGBcolor = ARGBcolor | _red;
	}
	//Takes in a 0x hex num instead of a 0-255 value, the hex num is in the format of ABGR

	void SetRawRedABGR(unsigned int _red) { SetRawBlueARGB(_red); }
	void SetRawGreenABGR(unsigned int _green) { SetRawGreenARGB(_green); }
	void SetRawBlueABGR(unsigned int _blue) { SetRawRedARGB(_blue); }
	void SetRawAlphaABGR(unsigned int _alpha) { SetRawAlphaARGB(_alpha); }

	//Takes in a 0x hex num instead of a 0-255 value, the hex num is in the format of ARGB
	void SetRawRedARGB(unsigned int _red)
	{
		_red = _red & 0x00FF0000;
		ARGBcolor = ARGBcolor & _red;
		_red = _red >> 16;
		ABGRcolor = ABGRcolor & _red;
	}
	void SetRawGreenARGB(unsigned int _blue)
	{
		_blue = _blue & 0x0000FF00;
		ARGBcolor = ARGBcolor & _blue;
		ABGRcolor = ABGRcolor & _blue;
	}
	void SetRawBlueARGB(unsigned int _blue)
	{
		_blue = _blue & 0x000000FF;
		ARGBcolor = ARGBcolor & _blue;
		_blue = _blue << 16;
		ABGRcolor = ABGRcolor & _blue;
	}
	void SetRawAlphaARGB(unsigned int _blue)
	{
		_blue = _blue & 0xFF000000;
		ARGBcolor = ARGBcolor & _blue;
		ABGRcolor = ABGRcolor & _blue;
	}
	void SetARGB(unsigned int _color)
	{
		ARGBcolor = _color;
		ABGRcolor = ARGBtoABGR(_color);
	}
	void SetABGR(unsigned int _color)
	{
		ABGRcolor = _color;
		ARGBcolor = ABGRtoARGB(_color);
	}
	void SetBGRA(unsigned int _color)
	{
		ARGBcolor = BGRAtoARGB(_color);
		ABGRcolor = ARGBtoABGR(ARGBcolor);
	}


	static Color CLerp(Color C1, Color C2, int _step)
	{
		Color Res;

		float a = _step / (float)255;
		Res.SetGreen(a * C1.GetGreen() + (1 - a) * C2.GetGreen());
		Res.SetRed(a * C1.GetRed() + (1 - a) * C2.GetRed());
		Res.SetBlue(a * C1.GetBlue() + (1 - a) * C2.GetBlue());
		Res.SetAlpha(a * C1.GetAlpha() + (1 - a) * C2.GetAlpha());
		return Res;

	}
	//Static colors
	static unsigned int GetAlphaARGB(unsigned int _col) { return (_col & 0xFF000000) >> 16; }

	static Color Red() { return Color(0xFF0000FF); }
	static Color Blue() { return Color(0xFF0000FF); }
	static Color Green() { return Color(0xFF00FF00); }
	static Color Magenta() { return Color(0xFFFF00FF); }
	static Color Yellow() { return Color(0xFFFFFF00); }
	static Color Cyan() { return Color(0xFF00FFFF); }
	static Color Black() { return Color(0xFF000000); }
	static Color White() { return Color(0xFFFFFFFF); }
	static Color Transparent() { return Color(0x00000000); }
	static Color Zero() { return Color(0x00000000); }
};












class ImageDef
{
public:
	std::string imageName;

	BLITVars::Vector2Int min;
	BLITVars::Vector2Int max;
	ImageDef();
	ImageDef(BLITVars::Vector2Int _min, BLITVars::Vector2Int _max, std::string _name);

private:

};

ImageDef::ImageDef()
{
	min = BLITVars::Vector2Int();
	max = BLITVars::Vector2Int();
	imageName = "";
}
ImageDef::ImageDef(BLITVars::Vector2Int _min, BLITVars::Vector2Int _max, std::string _name) {
	min = _min;
	max = _max;
	imageName = _name;
}
class AnimationDef : ImageDef
{
public:
	BLITVars::ScreenBounds frameSize;
	BLITVars::ScreenBounds srcSize;
	const unsigned int* src = nullptr;
	int itteration = 0;
	unsigned int NumOfFrames = 0;
	float frameRate;

	BLITVars::Vector2Int GetFramePosition(unsigned int frameNum)
	{
		if (frameNum > NumOfFrames) {
			std::cout << "out of frame bounds";

			return BLITVars::Vector2Int::Zero();
		}
		int framesWidth = floor(srcSize.Width / frameSize.Width);
		BLITVars::Vector2Int pos = BLITVars::IndexToPos(frameNum, framesWidth);
		if (pos.y > floor(srcSize.Height / frameSize.Height))
		{
			return BLITVars::Vector2Int::Zero();
		}
		return BLITVars::Vector2Int(frameSize.Width * pos.x, frameSize.Height * pos.y);

	}
	AnimationDef(const unsigned int* _src, BLITVars::ScreenBounds _srcBound, BLITVars::ScreenBounds _frameBounds, float _frameRate, BLITVars::Vector2Int _min, BLITVars::Vector2Int _max, std::string _name);
private:

};

AnimationDef::AnimationDef(const unsigned int* _src, BLITVars::ScreenBounds _srcBound, BLITVars::ScreenBounds _frameBounds, float _frameRate, BLITVars::Vector2Int _min, BLITVars::Vector2Int _max, std::string _name)
{
	min = _min;
	max = _max;
	imageName = _name;
	src = _src;
	frameRate = _frameRate;
	srcSize = _srcBound;
	frameSize = _frameBounds;
	NumOfFrames = floor(_srcBound.Width / _frameBounds.Width) * floor(_srcBound.Height / _frameBounds.Height);
	itteration = 0;
}
