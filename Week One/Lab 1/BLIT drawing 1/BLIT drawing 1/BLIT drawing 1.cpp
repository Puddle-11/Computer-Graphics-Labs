// ** hardcoded barebones example of blitting an image to a window   **
// ** study & break it down to understand how the BLIT process works **

#include "BLITDrawer.h"
unsigned int image_width = 500;
unsigned int image_height = 500;
unsigned int* image_pixels = nullptr; 
// info about this application
BLITDrawer::Vector2 pixelPos;
const unsigned int screen_width = 800;
const unsigned int screen_height = 600;
unsigned int screen_array[480000] = { 0, }; 
#define C2C(c) (((c&65280u)<<0x8u)|((c&4278190080u)>>0x18u)|((c&255u)<<0x18u)|((c&16711680u)>>0x08u)) 

// create a window and display the image in the center
int main() {
	image_pixels = new unsigned int[image_height * image_width];
	for (size_t i = 0; i < image_height * image_width; i++)
	{
		image_pixels[i] = 0x000000ff;
		if (i % image_width == 0) {
			image_pixels[i] = 0xffffffff;
			image_pixels[i - 1] = 0x00ffffff;
		}

	}


	RS_Initialize("Rowan Byington", screen_width, screen_height);
	do {
		const unsigned int* readline = image_pixels;
		unsigned int* scanline = screen_array + screen_width * (screen_height - image_height) / 2;
		scanline += (screen_width - image_width) / 2;
		for (unsigned int y = 0; y < image_height; ++y) {
			for (unsigned int x = 0; x < image_width; ++x, ++readline) {
				*scanline++ = C2C(*readline);
			}scanline += screen_width - image_width;
		}
	} while (RS_Update(screen_array, sizeof(screen_array) >> 2));
	RS_Shutdown();
	return 0;
}

