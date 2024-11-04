// ** hardcoded barebones example of blitting an image to a window   **
// ** study & break it down to understand how the BLIT process works **


// info about this application
#define _USE_MATH_DEFINES
#include "BLITVars.h"
#include "tiles_12.h"
#include "fire_01.h"
#include "XTime.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <math.h>
#define imagePixelCount ImageHeight * ImageWidth
BLITVars::Vector2Int pixelPos;
BLITVars::ScreenBounds mainBounds;
BLITVars::ScreenBounds srcBounds;
BLITVars::ScreenBounds fireAnimBounds;
unsigned int* image_pixels = nullptr;
const unsigned int layerCount = 2;
unsigned int layers[layerCount][imagePixelCount];


BLITVars::Vector2Int center;
XTime timer;
void Plot(int x, int y, unsigned int _color, int _layerIndex);
void Plot(int x, int y, Color _color, int _layerIndex);
void Plot(BLITVars::Vector2Int _pos, Color _color, int _layerIndex);
void Plot(BLITVars::Vector2Int _pos, unsigned int _color, int _layerIndex);

void Plot(int _index, Color _color, int _layerIndex);
void Plot(int _index, unsigned int _color, int _layerIndex);


Color Access(int x, int y, BLITVars::ScreenBounds _bounds, const unsigned int* _array);
Color Access(BLITVars::Vector2Int _pos, BLITVars::ScreenBounds _bounds, const unsigned int* _array);

Color AccessARGB(int _index, const unsigned int* _array);
Color AccessARGB(int x, int y, BLITVars::ScreenBounds _bounds, const unsigned int* _array);
Color AccessARGB(BLITVars::Vector2Int _pos, BLITVars::ScreenBounds _bounds, const unsigned int* _array);

void ClearBuffer();
void Copy(BLITVars::Vector2Int _scrMin, BLITVars::Vector2Int _scrMax, BLITVars::Vector2Int _cpyPos, bool _center = false, const unsigned int* _src = tiles_12_pixels, BLITVars::ScreenBounds _srcBounds = srcBounds, int _layerIndex = 0);
void Copy(BLITVars::Vector2Int _scrMin, BLITVars::Vector2Int _scrMax, BLITVars::Vector2Int _cpyPos, BLITVars::Vector2Int _offset, bool _center = false, const unsigned int* _src = tiles_12_pixels, BLITVars::ScreenBounds _srcBounds = srcBounds, int _layerIndex = 0);
void RasterizeLayers();
Color Access(int _index, const unsigned int* _array);
void ClearLayers(int _index);
void ClearLayers();
void ResetPixel(int _index, int _layerIndex);
void DrawRect(BLITVars::Vector2Int _min, BLITVars::Vector2Int _max, Color _color, bool _fill = false, int _layerIndex = 0);
void RasterizeRange(BLITVars::Vector2Int _min, BLITVars::Vector2Int _max);
void DrawLine(BLITVars::Vector2Int _p1, BLITVars::Vector2Int _p2, Color c);
void DrawLineSet(const BLITVars::Vector2Int* _points, int _pointCount, Color c);
void DrawPolygon(const BLITVars::Vector2Int* _points, int _pointCount, Color c);
void DrawRegularPolygon(int _size, int _vertCount, Color c, bool _wire = true);
int main()
{
	timer = XTime();
	srand(time(NULL));
	image_pixels = new unsigned int[imagePixelCount];


	mainBounds.Width = ImageWidth;
	mainBounds.Height = ImageHeight;

	srcBounds.Width = tiles_12_width;
	srcBounds.Height = tiles_12_height;

	fireAnimBounds.Width = fire_01_width;
	fireAnimBounds.Height = fire_01_height;

	center = BLITVars::Vector2Int(mainBounds.Width / 2, mainBounds.Height / 2);




	ImageDef bgImage = ImageDef(BLITVars::Vector2Int(288, 128), BLITVars::Vector2Int(320, 160), "Background");
	ImageDef tree = ImageDef(BLITVars::Vector2Int(320, 16), BLITVars::Vector2Int(384, 96), "Tree");
	ImageDef house = ImageDef(BLITVars::Vector2Int(16, 16), BLITVars::Vector2Int(112, 96), "House");
	ImageDef path = ImageDef(BLITVars::Vector2Int(352, 144), BLITVars::Vector2Int(368, 160), "Path");
	AnimationDef Flame = AnimationDef(fire_01_pixels, BLITVars::ScreenBounds(fire_01_width, fire_01_height), BLITVars::ScreenBounds(128, 128), 30, BLITVars::Vector2Int(352, 144), BLITVars::Vector2Int(368, 160), "Path");

	ClearBuffer();
	/*BLITVars::Vector2Int _points[8]{
		BLITVars::Vector2Int(100,10),
		BLITVars::Vector2Int(200,10),
		BLITVars::Vector2Int(300,110),
		BLITVars::Vector2Int(300,210),
		BLITVars::Vector2Int(200,310),
		BLITVars::Vector2Int(100,310),
		BLITVars::Vector2Int(0,210),
		BLITVars::Vector2Int(0,110),
	};*/



	//DrawPolygon(_points, 8, Color::Red());
	DrawRegularPolygon(100, 6, Color::Magenta(), true);
	RasterizeLayers();


	RS_Initialize("Rowan Byington Lab 1", mainBounds.Width, mainBounds.Height);
	do {

	} while (RS_Update(image_pixels, imagePixelCount));
	RS_Shutdown();
	return 0;
}



void RasterizeRange(BLITVars::Vector2Int _min, BLITVars::Vector2Int _max)
{
	Color l1;
	Color l2;
	int index = 0;
	BLITVars::Vector2Int currPos;

	for (int x = _min.x; x < _max.x; x++)
	{
		for (int y = _min.y; y < _max.y; y++)
		{
			currPos = BLITVars::Vector2Int(x, y);
			index = currPos.ToIndex();



			l2 = AccessARGB(index, layers[0]);
			l1 = l2;


			for (int j = 1; j < layerCount; j++)
			{
				l2 = AccessARGB(index, layers[j]);
				if (l2.GetAlpha() == 255) l1 = l2;
				else l1 = Color::CLerp(l2, l1, l2.GetAlpha());
			}
			Plot(index, l1.GetARGB(), 0);
		}
	}
}



void RasterizeLayers()
{
	Color l1;
	Color l2;
	for (int i = 0; i < imagePixelCount; i++)
	{


		l2 = AccessARGB(i, layers[0]);
		l1 = l2;


		for (int j = 1; j < layerCount; j++)
		{
			l2 = AccessARGB(i, layers[j]);
			if (l2.GetAlpha() == 255) l1 = l2;
			else l1 = Color::CLerp(l2, l1, l2.GetAlpha());
		}
		Plot(i, l1.GetARGB(), 0);
	}
}


void Copy(BLITVars::Vector2Int _srcMin, BLITVars::Vector2Int _srcMax, BLITVars::Vector2Int _cpyPos, BLITVars::Vector2Int _offset, bool _center, const unsigned int* _src, BLITVars::ScreenBounds _srcBounds, int _layerIndex)
{
	Color pixelColor;
	BLITVars::Vector2Int filteredPos;
	for (int x = _srcMin.x; x < _srcMax.x; x++)
	{
		for (int y = _srcMin.y; y < _srcMax.y; y++)
		{

			pixelColor = Access(x, y, _srcBounds, _src);
			filteredPos = _cpyPos + BLITVars::Vector2Int(x, y) - _srcMin;
			if (_center) {
				filteredPos = filteredPos - BLITVars::Vector2Int((_srcMax.x - _srcMin.x) / 2, (_srcMax.y - _srcMin.y) / 2);
			}

			filteredPos = filteredPos + _offset;
			Plot(filteredPos, pixelColor, _layerIndex);
		}
	}
}

void Copy(BLITVars::Vector2Int _scrMin, BLITVars::Vector2Int _scrMax, BLITVars::Vector2Int _cpyPos, bool _center, const unsigned int* _src, BLITVars::ScreenBounds _srcBounds, int _layerIndex)
{
	Copy(_scrMin, _scrMax, _cpyPos, BLITVars::Vector2Int(0, 0), _center, _src, _srcBounds, _layerIndex);
}

void ClearBuffer()
{
	ClearLayers(0);
}
void ClearLayers(int _index)
{
	for (int x = 0; x < imagePixelCount; x++)
	{
		ResetPixel(x, _index);

	}
}
void ClearLayers()
{
	for (int x = 0; x < imagePixelCount; x++)
	{
		for (int i = 1; i < layerCount + 1; i++)
		{
			ResetPixel(x, i);
		}
	}
}
Color Access(int x, int y, BLITVars::ScreenBounds _bounds, const unsigned int* _array) {
	return Access(BLITVars::Vector2Int(x, y), _bounds, _array);
}
Color Access(int _index, const unsigned int* _array)
{
	Color res;
	res.SetBGRA(_array[_index]);
	return res;
}
Color AccessARGB(int _index, const unsigned int* _array)
{
	Color res;
	res.SetARGB(_array[_index]);
	return res;
}
Color AccessARGB(int x, int y, BLITVars::ScreenBounds _bounds, const unsigned int* _array)
{
	return AccessARGB(BLITVars::Vector2Int(x, y), _bounds, _array);

}
Color AccessARGB(BLITVars::Vector2Int _pos, BLITVars::ScreenBounds _bounds, const unsigned int* _array)
{
	if (_pos.x >= _bounds.Width || _pos.x < 0 || _pos.y >= _bounds.Height || _pos.y < 0) return Color::Zero();
	Color res;
	res.SetARGB(_array[_pos.ToIndex(_bounds.Width)]);
	return res;
}
Color Access(BLITVars::Vector2Int _pos, BLITVars::ScreenBounds _bounds, const unsigned int* _array)
{
	if (_pos.x >= _bounds.Width || _pos.x < 0 || _pos.y >= _bounds.Height || _pos.y < 0) return Color::Zero();
	Color res;
	res.SetBGRA(_array[_pos.ToIndex(_bounds.Width)]);
	return res;
}

void Plot(int x, int y, unsigned int _color, int _layerIndex) { Plot(BLITVars::Vector2Int(x, y), _color, _layerIndex); }
void Plot(int x, int y, Color _color, int _layerIndex) { Plot(BLITVars::Vector2Int(x, y), _color.GetARGB(), _layerIndex); }


void Plot(BLITVars::Vector2Int _pos, Color _color, int _layerIndex) { Plot(_pos, _color.GetARGB(), _layerIndex); }
void Plot(BLITVars::Vector2Int _pos, unsigned int _color, int _layerIndex) {
	if (BLITVars::InScreenBounds(_pos)) {

		Plot(_pos.ToIndex(), _color, _layerIndex);
	}
}
void Plot(int _index, Color _color, int _layerIndex) { Plot(_index, _color.GetARGB(), _layerIndex); }
//color has to be in ARGB format
void Plot(int _index, unsigned int _color, int _layerIndex)
{
	if (_index > imagePixelCount) return;

	if (_layerIndex > layerCount) return;
	if ((_color & 0xFF000000) >> 24 == 0) {
		return;
	}
	if (_layerIndex == 0) {
		image_pixels[_index] = _color;
	}
	else {
		layers[_layerIndex - 1][_index] = _color;
	}
}
void ResetPixel(int _index, int _layerIndex) {

	if (_layerIndex == 0) {
		image_pixels[_index] = Color::Transparent().GetARGB();
	}
	else {
		layers[_layerIndex - 1][_index] = Color::Transparent().GetARGB();
	}
}

void DrawRect(BLITVars::Vector2Int _min, BLITVars::Vector2Int _max, Color _color, bool _fill, int _layerIndex)
{
	for (int x = _min.x; x <= _max.x; x++)
	{
		for (int y = _min.y; y <= _max.y; y++)
		{
			if (_fill)
			{
				Plot(x, y, _color, _layerIndex);
			}
			else
			{
				if (x == _min.x || x == _max.x || y == _min.y || y == _max.y) {
					Plot(x, y, _color, _layerIndex);
				}
			}
		}
	}
}
float lerp(float p1, float p2, float ratio)
{
	return p1 + (p2 - p1) * ratio;
}
void DrawLineSet(const BLITVars::Vector2Int* _points, int _pointCount, Color c)
{
	
	if (_pointCount <= 1)return;
	for (int i = 1; i < _pointCount; i++)
	{
		DrawLine(_points[i-1], _points[i],c);
	}
}
void DrawPolygon(const BLITVars::Vector2Int* _points, int _pointCount, Color c)
{
	BLITVars::Vector2Int* newPoints = new BLITVars::Vector2Int[_pointCount + 1];
	for (size_t i = 0; i < _pointCount; i++)
	{
		newPoints[i] = _points[i];


	}
	newPoints[_pointCount] = _points[0];
	DrawLineSet(newPoints, _pointCount + 1, c);
	delete newPoints;


}

void DrawLine(BLITVars::Vector2Int _p1, BLITVars::Vector2Int _p2, Color c)
{
	float r = 0;
	int maxChange = abs(_p2.x - _p1.x) > abs(_p2.y - _p1.y) ? abs(_p2.x - _p1.x) : abs(_p2.y - _p1.y);
	BLITVars::Vector2Int currPos = _p1;
	for (int i = 0; i <= maxChange; i++)
	{
		r = (float)i / (float)abs(maxChange);
		currPos = BLITVars::Vector2Int(floor( lerp(_p1.x, _p2.x, r) + 0.5), floor( lerp(_p1.y, _p2.y, r)+0.5));
		Plot(currPos, c, 1);
	}
}

void DrawRegularPolygon(int _size, int _vertCount, Color c, bool _wire)
{
	/*for (i = 0; i < n; i++) {
		printf("%f %f\n", r * Math.cos(2 * Math.PI * i / n), r * Math.sin(2 * Math.PI * i / n));
	}*/
	BLITVars::Vector2Int* temp = new BLITVars::Vector2Int[_vertCount];
	for (int i = 0; i < _vertCount; i++)
	{
	
		float x = _size * cos(2 * M_PI * i / _vertCount);
		float y =  _size * sin(2 * M_PI * i / _vertCount);
		x = floor(x + 0.5) + _size;
		y = floor(y + 0.5) + _size;
		temp[i] = BLITVars::Vector2Int(x,y);
		Plot(x, y, Color::White(), 1);
	}
	DrawPolygon(temp, _vertCount,c);
	delete[] temp;
}


