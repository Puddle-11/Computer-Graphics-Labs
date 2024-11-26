#include "Color.h"

Color::Color()
{
	SetARGB(0xFFFF00FF);
}
Color::Color(unsigned int _color)
{
	SetARGB(_color);
}
Color::Color(unsigned int _R, unsigned int _G, unsigned  int _B, unsigned int _A)
{
	SetRed(_R);
	SetBlue(_B);
	SetGreen(_G);
}






Color Color::operator+(Color& _ref)
{
	Color res;
	int red = this->GetRed() + _ref.GetRed();
	int green = this->GetGreen() + _ref.GetGreen();
	int blue = this->GetBlue() + _ref.GetBlue();


	res.SetRed(red);
	res.SetGreen(green);
	res.SetBlue(blue);


	return res;


}
Color Color::operator*(Color& _ref)
{
	Color res;
	int red =   ((this->GetRed()   / (float)255) * (_ref.GetRed()   / (float)255)) * 255;
	int green = ((this->GetGreen() / (float)255) * (_ref.GetGreen() / (float)255)) * 255;
	int blue =  ((this->GetBlue()  / (float)255) * (_ref.GetBlue()  / (float)255)) * 255;

	res.SetRed(red);
	res.SetGreen(green);
	res.SetBlue(blue);


	return res;


}
Color Color::operator*(float _scale)
{
	Color res;
	int red = (this->GetRed() * _scale);
	int green = (this->GetGreen() * _scale);
	int blue = (this->GetBlue() * _scale);


	res.SetRed(red);
	res.SetGreen(green);
	res.SetBlue(blue);


	return res;


}
unsigned int Color::ABGRtoARGB(unsigned int _original)
{
	unsigned int A = _original & 0xFF000000;
	unsigned int B = _original & 0x00FF0000;
	unsigned int G = _original & 0x0000FF00;
	unsigned int R = _original & 0x000000FF;
	B = B >> 16;
	R = R << 16;
	return  R | G | B | A;
}
unsigned int Color::ARGBtoABGR(unsigned int _original)
{
	unsigned int A = _original & 0xFF000000;
	unsigned int R = _original & 0x00FF0000;
	unsigned int G = _original & 0x0000FF00;
	unsigned int B = _original & 0x000000FF;
	B = B << 16;
	R = R >> 16;
	return  R | G | B | A;
}
unsigned int Color::ARGBtoBGRA(unsigned int _original)
{
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
unsigned int Color::BGRAtoARGB(unsigned int _original)
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

unsigned int Color::GetRed() { return (ARGBcolor & 0x00FF0000) >> 16; }
unsigned int Color::GetGreen() { return (ARGBcolor & 0x0000FF00) >> 8; }
unsigned int Color::GetBlue() { return (ARGBcolor & 0x000000FF); }
unsigned int Color::GetAlpha() { return (ARGBcolor & 0xFF000000) >> 24; }

unsigned int Color::GetRawRed() { return ARGBcolor & 0x00FF0000; }
unsigned int Color::GetRawGreen() { return ARGBcolor & 0x0000FF00; }
unsigned int Color::GetRawBlue() { return ARGBcolor & 0x000000FF; }
unsigned int Color::GetRawAlpha() { return ARGBcolor & 0xFF000000; }

unsigned int Color::GetABGR() { return ABGRcolor; }
unsigned int Color::GetARGB() { return ARGBcolor; }
unsigned int Color::GetBGRA() { return ARGBtoBGRA(ARGBcolor); }

void Color::SetAlpha(unsigned int _alpha)
{

	if (_alpha > 255) _alpha = 255; //Clamp incoming values
	ARGBcolor = ARGBcolor & 0x00FFFFFF; //remove the blue from the current color
	ABGRcolor = ABGRcolor & 0x00FFFFFF; //remove the blue from the current color
	_alpha = _alpha << 24;
	ARGBcolor = ARGBcolor | _alpha;
	ABGRcolor = ABGRcolor | _alpha;
}
void Color::SetBlue(unsigned int _blue)
{
	//Incoming colors will always be in the 0x000000FF format
	if (_blue > 255) _blue = 255; //Clamp incoming values
	ARGBcolor = ARGBcolor & 0xFFFFFF00; //remove the blue from the current color
	ARGBcolor = ARGBcolor | _blue;
	_blue = _blue << 16;
	ABGRcolor = ABGRcolor & 0xFF00FFFF; //Remove the blue from the current color
	ABGRcolor = ABGRcolor | _blue;
}
void Color::SetGreen(unsigned int _green)
{
	//Incoming colors will always be in the 0x000000FF format
	if (_green > 255) _green = 255; //Clamp incoming values
	_green = _green << 8;
	ARGBcolor = ARGBcolor & 0xFFFF00FF; //remove the blue from the current color
	ARGBcolor = ARGBcolor | _green;
	ABGRcolor = ABGRcolor & 0xFFFF00FF; //Remove the blue from the current color
	ABGRcolor = ABGRcolor | _green;
}
void Color::SetRed(unsigned int _red)
{
	//Incoming colors will always be in the 0x000000FF format
	if (_red > 255) _red = 255; //Clamp incoming values
	ABGRcolor = ABGRcolor & 0xFFFFFF00; //Remove the blue from the current color
	ABGRcolor = ABGRcolor | _red;
	_red = _red << 16;
	ARGBcolor = ARGBcolor & 0xFF00FFFF; //remove the blue from the current color
	ARGBcolor = ARGBcolor | _red;
}

void Color::SetRawRedABGR(unsigned int _red) { SetRawBlueARGB(_red); }
void Color::SetRawGreenABGR(unsigned int _green) { SetRawGreenARGB(_green); }
void Color::SetRawBlueABGR(unsigned int _blue) { SetRawRedARGB(_blue); }
void Color::SetRawAlphaABGR(unsigned int _alpha) { SetRawAlphaARGB(_alpha); }

void Color::SetRawRedARGB(unsigned int _red)
{
	_red = _red & 0x00FF0000;
	ARGBcolor = ARGBcolor & _red;
	_red = _red >> 16;
	ABGRcolor = ABGRcolor & _red;
}
void Color::SetRawGreenARGB(unsigned int _blue)
{
	_blue = _blue & 0x0000FF00;
	ARGBcolor = ARGBcolor & _blue;
	ABGRcolor = ABGRcolor & _blue;
}
void Color::SetRawBlueARGB(unsigned int _blue)
{
	_blue = _blue & 0x000000FF;
	ARGBcolor = ARGBcolor & _blue;
	_blue = _blue << 16;
	ABGRcolor = ABGRcolor & _blue;
}
void Color::SetRawAlphaARGB(unsigned int _blue)
{
	_blue = _blue & 0xFF000000;
	ARGBcolor = ARGBcolor & _blue;
	ABGRcolor = ABGRcolor & _blue;
}
void Color::SetARGB(unsigned int _color)
{
	ARGBcolor = _color;
	ABGRcolor = ARGBtoABGR(_color);
}
void Color::SetABGR(unsigned int _color)
{
	ABGRcolor = _color;
	ARGBcolor = ABGRtoARGB(_color);
}
void Color::SetBGRA(unsigned int _color)
{
	ARGBcolor = BGRAtoARGB(_color);
	ABGRcolor = ARGBtoABGR(ARGBcolor);
}

Color Color::CLerp(Color C1, Color C2, int _step)
{
	Color Res;
	float a = _step / (float)255;
	Res.SetGreen((int)(a * C1.GetGreen() + (1 - a) * C2.GetGreen()));
	Res.SetRed((int)(a * C1.GetRed() + (1 - a) * C2.GetRed()));
	Res.SetBlue((int)(a * C1.GetBlue() + (1 - a) * C2.GetBlue()));
	Res.SetAlpha((int)(a * C1.GetAlpha() + (1 - a) * C2.GetAlpha()));
	return Res;
}
unsigned int Color::GetAlphaARGB(unsigned int _col) { return (_col & 0xFF000000) >> 16; }

Color Color::Red() { return Color(0xFFFF0000); }
Color Color::Blue() { return Color(0xFF0000FF); }
Color Color::Green() { return Color(0xFF00FF00); }
Color Color::Magenta() { return Color(0xFFFF00FF); }
Color Color::Yellow() { return Color(0xFFFFFF00); }
Color Color::Cyan() { return Color(0xFF00FFFF); }
Color Color::Orange() { return Color(0xFFFF7f00); }
Color Color::Lime() { return Color(0xFF7fFF00); }
Color Color::Violet() { return Color(0xFF7f00FF); }
Color Color::Pink() { return Color(0xFFFF007F); }
Color Color::Teal() { return Color(0xFF00FF7F); }
Color Color::Azure() { return Color(0xFF007FFF); }
Color Color::Black() { return Color(0xFF000000); }
Color Color::Grey() { return Color(0x77777777); }
Color Color::White() { return Color(0xFFFFFFFF); }
Color Color::Transparent() { return Color(0x00000000); }
Color Color::Zero() { return Color(0x00000000); }