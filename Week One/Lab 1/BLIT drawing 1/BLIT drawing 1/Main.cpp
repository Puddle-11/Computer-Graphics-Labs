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
	int currentScene = 0;
	mainBounds.Width = ImageWidth;
	mainBounds.Height = ImageHeight;

	center = Vector2Int(mainBounds.Width / 2, mainBounds.Height / 2);
	Mesh Cube(Mesh::Cube());
	Mesh Pyramid(Mesh::SquarePyramid());

	VertexShader = ToWorld;
	PixelShader = nullptr;


	Matrix CameraMatrix;
	Matrix CameraRotationMatrix;
	CameraMatrix = Matrix::Identity();
	SV_View = Matrix::Identity();
	SV_WorldMatrix = Matrix::Identity();
	SV_Proj = Matrix::Identity();
	bool gDown = false;


	SV_Proj = Matrix::ProjectionMatrix(0.1, 10, 90, AspectRatio);



	float time = 0;

	Vector3 cameraPos = Vector3(0, 3, -3);
		ClearBuffer();
		VertexScreen triPoints[]{
			VertexScreen(Vector2Int(0,-50) + center, Color::Lime()),
			VertexScreen(Vector2Int(100,50) + center, Color::Cyan()),
			VertexScreen(Vector2Int(-100,50) + center, Color::Teal())

		};
		DrawLine(triPoints[0], triPoints[1]);
		DrawLine(triPoints[1], triPoints[2]);
		DrawLine(triPoints[2], triPoints[0]);

	RS_Initialize("Rowan Byington Lab 3", mainBounds.Width, mainBounds.Height);
	do
	{
	/*	timer.Signal();
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
		if (GetAsyncKeyState(71))
		{
			if (!gDown)
			{
				gDown = true;
				currentScene = (currentScene + 1) % 3;
			}
		}
		else
		{
			gDown = false;

		}


		CameraRotationMatrix = Matrix::Identity() * Matrix::XRotationMatrix(-(p.y - 500) / (float)400) * Matrix::YRotationMatrix(-(p.x - 1000) / (float)400);
		CameraMatrix = Matrix::Identity() * CameraRotationMatrix * Matrix::TranslationMatrix(cameraPos.x, cameraPos.y, cameraPos.z);

		SV_View = Matrix::Invert(CameraMatrix);


		PixelShader = White;

		ClearBuffer();


		if (currentScene == 0)
		{
			SV_WorldMatrix = Matrix::Identity() * Matrix::ScaleMatrix(-2) * Matrix::YRotationMatrix(time) * Matrix::TranslationMatrix(0, 5, 0);
			DrawMesh(Pyramid);
			SV_WorldMatrix = Matrix::Identity() * Matrix::ScaleMatrix(2) * Matrix::YRotationMatrix(-time) * Matrix::TranslationMatrix(0, 1, 0);

			DrawMesh(Pyramid);

			PixelShader = Pink;

			SV_WorldMatrix = Matrix::Identity() * Matrix::TranslationMatrix(2.5, 0.5, -2.5);
			DrawMesh(Cube);

			SV_WorldMatrix = Matrix::Identity() * Matrix::TranslationMatrix(2.5, 0.5, 2.5);
			DrawMesh(Cube);

			SV_WorldMatrix = Matrix::Identity() * Matrix::TranslationMatrix(-2.5, 0.5, -2.5);
			DrawMesh(Cube);
			SV_WorldMatrix = Matrix::Identity() * Matrix::TranslationMatrix(-2.5, 0.5, 2.5);
			DrawMesh(Cube);
			PixelShader = White;
			SV_WorldMatrix = Matrix::Identity() * Matrix::ScaleMatrix(0.25) * Matrix::TranslationMatrix(2, 5, 0) * Matrix::YRotationMatrix(time);
			DrawMesh(Cube);
			SV_WorldMatrix = Matrix::Identity() * Matrix::ScaleMatrix(0.25) * Matrix::TranslationMatrix(-2, 5, 0) * Matrix::YRotationMatrix(time);
			DrawMesh(Cube);

			SV_WorldMatrix = Matrix::Identity() * Matrix::ScaleMatrix(0.25) * Matrix::TranslationMatrix(0, 5, 2) * Matrix::YRotationMatrix(time);
			DrawMesh(Cube);
			SV_WorldMatrix = Matrix::Identity() * Matrix::ScaleMatrix(0.25) * Matrix::TranslationMatrix(0, 5, -2) * Matrix::YRotationMatrix(time);
			DrawMesh(Cube);
			PixelShader = Orange;

		}
		else if (currentScene == 1)
		{
			PixelShader = Teal;
			SV_WorldMatrix = Matrix::Identity() * Matrix::ScaleMatrix(2) * Matrix::YRotationMatrix(time) * Matrix::TranslationMatrix(0, 3, 0);
			DrawMesh(Cube);
			PixelShader = White;

		}
		else if (currentScene == 2)
		{
			SV_WorldMatrix = Matrix::Identity() * Matrix::ScaleMatrix(2) * Matrix::YRotationMatrix(time) * Matrix::TranslationMatrix(0, 3, 0);
			DrawMesh(Pyramid);
			PixelShader = Teal;
		}
		SV_WorldMatrix = Matrix::Identity();
		DrawPlane(Vector2(1, 1), 9, Color::Orange());*/





	} while (RS_Update(image_pixels, imagePixelCount));
	RS_Shutdown();
	delete[] image_pixels;
	return 0;
}


