// ** hardcoded barebones example of blitting an image to a window   **
// ** study & break it down to understand how the BLIT process works **


// info about this application
#include "BLITVars.h"
#include "tiles_12.h"
#include "fire_01.h"
#include "XTime.h"
#include <vector>
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

	std::cout << Flame.GetFramePosition(63).ToString();
	ClearBuffer();

	BLITVars::Vector2Int currPos;
	BLITVars::Vector2Int checkOffset;
	checkOffset = (path.max - path.min);
	checkOffset = checkOffset / 2;
	BLITVars::Vector2Int origin = Flame.GetFramePosition(0);
	BLITVars::Vector2Int corner = origin;
	corner.x = corner.x + Flame.frameSize.Width;
	corner.y = corner.y + Flame.frameSize.Height;










	for (int x = 0; x < mainBounds.Width; x++)
	{
		for (int y = 0; y < mainBounds.Height; y++)
		{
			currPos = BLITVars::Vector2Int(x, y);

			if (x % 32 == 0 && y % 32 == 0)
			{
				Copy(bgImage.min, bgImage.max, BLITVars::Vector2Int(x, y), false, tiles_12_pixels, BLITVars::ScreenBounds(tiles_12_width, tiles_12_height), 1);
			}


			if (BLITVars::Vector2Int::Distance(currPos + checkOffset, center) < 100) {
				if (x % 16 == 0 && y % 16 == 0)
				{
					Copy(path.min, path.max, BLITVars::Vector2Int(x, y), false, tiles_12_pixels, BLITVars::ScreenBounds(tiles_12_width, tiles_12_height), 1);
				}
			}
		}
	}

	float DistFromCenter;

	for (int y = 0; y < mainBounds.Height; y++)
	{
		for (int x = 0; x < mainBounds.Width; x++)
		{
			currPos = BLITVars::Vector2Int(x, y);
			if (BLITVars::Vector2Int::Distance(currPos, center) > 150)
			{
				int ran = rand();
				if (ran % 5000 == 10) {
					Copy(tree.min, tree.max, currPos, true, tiles_12_pixels, BLITVars::ScreenBounds(tiles_12_width, tiles_12_height), 1);
				}
			}
		}
	}
	Copy(house.min, house.max, center, true, tiles_12_pixels, BLITVars::ScreenBounds(tiles_12_width, tiles_12_height), 1);



	/*DrawRect(BLITVars::Vector2Int(60, 60), BLITVars::Vector2Int(200, 100), Color::Yellow(), true);
	DrawRect(BLITVars::Vector2Int(50, 50), BLITVars::Vector2Int(210, 110), Color::White());*/

	BLITVars::Vector2Int _currPos;
	Color currColor;
	int currentFrame = 0;
	BLITVars::Vector2Int FrameStartingPos;
	BLITVars::Vector2Int _filteredPos;
	float time = 0;
	RasterizeLayers();
	RS_Initialize("Rowan Byington Lab 1", mainBounds.Width, mainBounds.Height);
	do {
		timer.Signal();
		time += timer.Delta();
		FrameStartingPos = Flame.GetFramePosition(currentFrame);
		if (time >= 1 / (float)Flame.frameRate) {
			time = 0;
			ClearLayers(2);


			BLITVars::Vector2Int min = Flame.GetFramePosition(currentFrame);

			BLITVars::Vector2Int max = BLITVars::Vector2Int(Flame.frameSize.Width, Flame.frameSize.Height) + Flame.GetFramePosition(currentFrame);

			BLITVars::Vector2Int startingPos = BLITVars::Vector2Int(290,100);
			BLITVars::Vector2Int animMax = startingPos + max;
			animMax = animMax - min;

			Copy(min, max, startingPos, false, fire_01_pixels, Flame.srcSize, 2);
			RasterizeRange(startingPos, animMax);


			currentFrame = (currentFrame + 1) % Flame.NumOfFrames;
		}
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
	if(_layerIndex == 0){
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


