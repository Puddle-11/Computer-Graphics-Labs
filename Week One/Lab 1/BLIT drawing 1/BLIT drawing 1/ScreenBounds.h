#pragma once
class ScreenBounds {
public:
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