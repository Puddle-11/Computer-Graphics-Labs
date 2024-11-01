// ** hardcoded barebones example of blitting an image to a window   **
// ** study & break it down to understand how the BLIT process works **


// info about this application
#include "BLITVars.h"


BLITVars::Vector2Int pixelPos;

unsigned int* image_pixels = nullptr;

unsigned int screen_array[360000] = { 0, };

#define blue  0xff0000ff
#define green 0xff00ff00
#define red	  0xffff0000
#define white 0xffffffff
#define black 0xff000000

#define imagePixelCount ImageHeight * ImageWidth
// create a window and display the image in the center

int main() {
	image_pixels = new unsigned int[imagePixelCount];
	for (size_t i = 0; i < imagePixelCount; i++)
	{
		image_pixels[i] = black;
		if (i < ImageHeight || i > ImageWidth * (ImageHeight - 1) || (i + 1) % ImageWidth == 0 || i % ImageWidth == 0) {
			image_pixels[i] = BLITVars::BGRAtoRGBA(red);
		}
	}



	RS_Initialize("Rowan Byington", ImageWidth, ImageWidth);


	do {
	





	} while (RS_Update(image_pixels, imagePixelCount));
	RS_Shutdown();
	return 0;
}



