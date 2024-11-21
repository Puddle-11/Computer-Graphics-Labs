#pragma once
class Color
{

public:
	unsigned int ARGBcolor;
	unsigned int ABGRcolor;

	Color();
	Color(unsigned int _color);
	Color(unsigned int _R, unsigned int _G, unsigned  int _B, unsigned int _A);


	//convert to different formats
	unsigned int ABGRtoARGB(unsigned int _original);
	unsigned int ARGBtoABGR(unsigned int _original);
	unsigned int ARGBtoBGRA(unsigned int _original);
	unsigned int BGRAtoARGB(unsigned int _original);

	//Gives a value between 0-255
	unsigned int GetRed();
	unsigned int GetGreen();
	unsigned int GetBlue();
	unsigned int GetAlpha();

	//Gives the full hex value for that color
	unsigned int GetRawRed();
	unsigned int GetRawGreen();
	unsigned int GetRawBlue();
	unsigned int GetRawAlpha();

	//returns the entire color value in a specific format
	unsigned int GetABGR();
	unsigned int GetARGB();
	unsigned int GetBGRA();


	void SetAlpha(unsigned int _alpha);
	void SetBlue(unsigned int _blue);
	void SetGreen(unsigned int _green);
	void SetRed(unsigned int _red);

	//Takes in a 0x hex num instead of a 0-255 value, the hex num is in the format of ABGR
	void SetRawRedABGR(unsigned int _red);
	void SetRawGreenABGR(unsigned int _green);
	void SetRawBlueABGR(unsigned int _blue);
	void SetRawAlphaABGR(unsigned int _alpha);
	//Takes in a 0x hex num instead of a 0-255 value, the hex num is in the format of ARGB
	void SetRawRedARGB(unsigned int _red);
	void SetRawGreenARGB(unsigned int _blue);
	void SetRawBlueARGB(unsigned int _blue);
	void SetRawAlphaARGB(unsigned int _blue);
	void SetARGB(unsigned int _color);
	void SetABGR(unsigned int _color);
	void SetBGRA(unsigned int _color);
	Color operator+(Color& _ref);
	Color operator*(Color& _ref);
	Color operator*(float _scale);
		static Color CLerp(Color C1, Color C2, int _step);

	//Static colors
	static unsigned int GetAlphaARGB(unsigned int _col);

	static Color Red();
	static Color Blue();
	static Color Green();
	static Color Magenta();
	static Color Yellow();
	static Color Cyan();

	static Color Orange();
	static Color Lime();
	static Color Violet();
	static Color Pink();
	static Color Teal();
	static Color Azure();

	static Color Black();
	static Color Grey();
	static Color White();
	static Color Transparent();
	static Color Zero();
};
