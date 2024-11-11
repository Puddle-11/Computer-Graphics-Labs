// ** hardcoded barebones example of blitting an image to a window   **
// ** study & break it down to understand how the BLIT process works **


// info about this application
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "tiles_12.h"
#include "fire_01.h"
#include "XTime.h"
#include "Rasterization.h"
#include "Vector3.h"
#include "RasterSurface.h"

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

	float cameraSpeed = 2;
	mainBounds.Width = ImageWidth;
	mainBounds.Height = ImageHeight;

	center = Vector2Int(mainBounds.Width / 2, mainBounds.Height / 2);

	Mesh Cube;

	Vertex4D line[8]{

		Vertex4D(Vector4(-0.5, -0.5, 0.5, 1), Color::Red()),
		Vertex4D(Vector4(-0.5, 0.5, 0.5, 1), Color::Green()),
		Vertex4D(Vector4(0.5, 0.5, 0.5, 1), Color::Blue()),
		Vertex4D(Vector4(0.5, -0.5, 0.5, 1), Color::Magenta()),

		Vertex4D(Vector4(-0.5, -0.5, -0.5, 1), Color::Cyan()),
		Vertex4D(Vector4(-0.5, 0.5,  -0.5, 1), Color::Yellow()),
		Vertex4D(Vector4(0.5, 0.5,  -0.5, 1), Color::White()),
		Vertex4D(Vector4(0.5, -0.5, -0.5, 1), Color::Grey()),
	};
	int tris[36]{

		0,1,2,
		3,2,0,

		4,5,6,
		7,6,4,

		0,4,5,
		5,1,0,

		3,7,6,
		6,2,3,

		1,5,2,
		5,6,2,

		0,4,3,
		4,7,3,
	};
	Cube.SetVerts(line, 8);
	Cube.SetTris(tris, 36);

	VertexShader = ToWorld;
	PixelShader = nullptr;


	Matrix CameraMatrix;
	Matrix CameraRotationMatrix;
	CameraMatrix = Matrix::Identity();
	SV_View = Matrix::Identity();
	SV_WorldMatrix = Matrix::Identity();
	SV_Proj = Matrix::Identity();



	SV_Proj = Matrix::ProjectionMatrix(0.1, 10, 90, 1);
	



	float time = 0;
	
	Vector3 cameraPos = Vector3(0,3,-3);
	RS_Initialize("Rowan Byington Lab 2", mainBounds.Width, mainBounds.Height);
	do
	{
		timer.Signal();
		POINT p;
		GetCursorPos(&p);
		time += timer.Delta();
		if (GetAsyncKeyState(87))
		{
			cameraPos.z += timer.Delta() * cameraSpeed;
		}
		if (GetAsyncKeyState(83))
		{
			cameraPos.z -= timer.Delta() * cameraSpeed;
		}
		if (GetAsyncKeyState(65))
		{
			cameraPos.x -= timer.Delta() * cameraSpeed;
		}
		if (GetAsyncKeyState(68))
		{
			cameraPos.x += timer.Delta() * cameraSpeed;
		}
		if (GetAsyncKeyState(32))
		{
			cameraPos.y += timer.Delta() * cameraSpeed;
		}
		if (GetAsyncKeyState(90))
		{
			cameraPos.y -= timer.Delta() * cameraSpeed;
		}

		SV_WorldMatrix = Matrix::Identity() * Matrix::YRotationMatrix(time) * Matrix::TranslationMatrix(0, 2, 0);
		CameraRotationMatrix = Matrix::Identity() * Matrix::XRotationMatrix(-(p.y - 500 )/ (float)400) * Matrix::YRotationMatrix(-(p.x - 1000) / (float)400);
		CameraMatrix = Matrix::Identity() * CameraRotationMatrix * Matrix::TranslationMatrix(cameraPos.x, cameraPos.y, cameraPos.z);

		SV_View = Matrix::Invert(CameraMatrix);


		PixelShader = nullptr;

		ClearBuffer();
		DrawMesh(Cube);

		SV_WorldMatrix = Matrix::Identity();
		PixelShader = nullptr;

		DrawPlane(Vector2(5, 5), 5, Color::Green());

	} while (RS_Update(image_pixels, imagePixelCount));
	RS_Shutdown();
	delete[] image_pixels;
	return 0;
}


