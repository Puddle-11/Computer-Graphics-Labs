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

	static Color CLerp(Color C1, Color C2, int _step);

	//Static colors
	static unsigned int GetAlphaARGB(unsigned int _col) { return (_col & 0xFF000000) >> 16; }

	static Color Red() { return Color(0xFFFF0000); }
	static Color Blue() { return Color(0xFF0000FF); }
	static Color Green() { return Color(0xFF00FF00); }
	static Color Magenta() { return Color(0xFFFF00FF); }
	static Color Yellow() { return Color(0xFFFFFF00); }
	static Color Cyan() { return Color(0xFF00FFFF); }



	static Color Orange() { return Color(0xFFFF7f00); }
	static Color Lime() { return Color(0xFF7fFF00); }
	static Color Violet() { return Color(0xFF7f00FF); }
	static Color Pink() { return Color(0xFFFF007F); }
	static Color Teal() { return Color(0xFF00FF7F); }
	static Color Azure() { return Color(0xFF007FFF); }



	static Color Black() { return Color(0xFF000000); }
	static Color Grey() { return Color(0x77777777); }
	static Color White() { return Color(0xFFFFFFFF); }
	static Color Transparent() { return Color(0x00000000); }
	static Color Zero() { return Color(0x00000000); }
};
