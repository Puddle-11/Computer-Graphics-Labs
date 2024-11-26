#pragma once
#include "Vector2Int.h"
#include <string>
class ImageDef
{
public:
	std::string imageName;

	Vector2Int min;
	Vector2Int max;
	ImageDef();
	ImageDef(Vector2Int _min, Vector2Int _max, std::string _name);

private:

};

ImageDef::ImageDef()
{
	min = Vector2Int();
	max = Vector2Int();
	imageName = "";
}
ImageDef::ImageDef(Vector2Int _min, Vector2Int _max, std::string _name) {
	min = _min;
	max = _max;
	imageName = _name;
}