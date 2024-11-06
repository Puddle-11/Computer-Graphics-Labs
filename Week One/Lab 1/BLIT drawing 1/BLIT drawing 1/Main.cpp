// ** hardcoded barebones example of blitting an image to a window   **
// ** study & break it down to understand how the BLIT process works **


// info about this application
#define _USE_MATH_DEFINES
#include "BLITVars.h"
#include "tiles_12.h"
#include "fire_01.h"
#include "XTime.h"
#include <iostream>
#include <cmath>
#include "Color.h"
#include "ScreenBounds.h"
#include "RasterSurface.h"
#include "ImageDef.h"
#include "AnimationDef.h"
#include "VertexScreen.h"
#include "Canvas.h"

Vector2Int center;
XTime timer;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1); // set block of memory to find memory leak
	_CrtDumpMemoryLeaks();

	timer = XTime();
	srand((unsigned int)time(NULL));
	image_pixels = new unsigned int[imagePixelCount];

	mainBounds.Width = ImageWidth;
	mainBounds.Height = ImageHeight;

	center = Vector2Int(mainBounds.Width / 2, mainBounds.Height / 2);
	Vector2Int temp = Vector2Int(0, 1);
	temp = temp * 2 + Vector2Int(5, 0) - Vector2Int(3, 0);
	std::cout << temp.ToString();


	ClearBuffer();
	DrawRegularPolygon(100, 13, Color::Yellow(), Color::Magenta(), true, center);
	RasterizeLayers();
	RS_Initialize("Rowan Byington Lab 2", mainBounds.Width, mainBounds.Height);
	do
	{

	} while (RS_Update(image_pixels, imagePixelCount));
	RS_Shutdown();
	delete[] image_pixels;
	return 0;
}


