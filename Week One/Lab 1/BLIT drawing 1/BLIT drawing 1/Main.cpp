// ** hardcoded barebones example of blitting an image to a window   **
// ** study & break it down to understand how the BLIT process works **


// info about this application
#define _USE_MATH_DEFINES
#define NOMINMAX

#include <iostream>
#include <cmath>
#include "tiles_12.h"
#include "fire_01.h"
#include "treeolife.h"
#include "StoneHenge.h"
#include "XTime.h"
#include "Rasterization.h"
#include "Vector3.h"
#include "RasterSurface.h"
#include "StoneHenge_Texture.h"
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
	depth_pixels = new float[imagePixelCount];
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

	Vector3 cameraPos = Vector3(0, 10, -50);
	Vector2 cameraRot = Vector2::Zero();
	ClearBuffer();
	Mesh m;
	Mesh cube(Mesh::Cube());
	Vertex4D verts[vertCount];

	for (size_t i = 0; i < vertCount; i++)
	{
		verts[i] = Vertex4D(Vector4(StoneHenge_data[i].pos[0], StoneHenge_data[i].pos[1], StoneHenge_data[i].pos[2], 1), Color::White(), Vector2(StoneHenge_data[i].uvw[0], StoneHenge_data[i].uvw[1]), Vector3(StoneHenge_data[i].nrm[0], StoneHenge_data[i].nrm[1], StoneHenge_data[i].nrm[2]));
	}

	m.SetVerts(verts, vertCount);

	m.SetTris(StoneHenge_indicies, (int)triCount);
	m.SetTexture(StoneHenge_pixels, StoneHenge_numpixels, ScreenBounds(StoneHenge_width, StoneHenge_height));
	worldLight.angle = Vector4(-1, 0.3, 0, 1);
	worldLight.shadowIntensity = 0.85;
	worldLight.intensity = 0.2;
	ShadowColor = Color::Azure();
	worldLight.tint = Color::Blue();
	worldLight.tintWeight = 0.5;

	worldLight2.angle = Vector4(1, 0.3, 0, 1);
	worldLight2.shadowIntensity = 0.85;
	worldLight2.intensity = 0.5;
	ShadowColor = Color::Black();
	worldLight2.tint = Color::Orange();
	worldLight2.tintWeight = 0.7;

	pl.intensity = 1;
	pl.range = 5;
	pl.tint = Color::Orange();
	pl.tintWeight = 1;
	RS_Initialize("Rowan Byington Lab 3", mainBounds.Width, mainBounds.Height);
	do
	{

		timer.Signal();
		POINT p;
		GetCursorPos(&p);
		time += timer.Delta();

		if (GetAsyncKeyState(87))
		{
			cameraRot.x += timer.Delta() * cameraSpeed;
		}
		if (GetAsyncKeyState(83))
		{
			cameraRot.x -= timer.Delta() * cameraSpeed;
		}
		if (GetAsyncKeyState(65))
		{
			cameraRot.y -= timer.Delta() * cameraSpeed;
		}
		if (GetAsyncKeyState(68))
		{
			cameraRot.y += timer.Delta() * cameraSpeed;
		}

		CameraRotationMatrix = Matrix::Identity() * Matrix::XRotationMatrix(cameraRot.x) * Matrix::YRotationMatrix(cameraRot.y);
		CameraMatrix = Matrix::Identity() * Matrix::TranslationMatrix(cameraPos.x, cameraPos.y, cameraPos.z) * CameraRotationMatrix;




		SV_View = Matrix::Invert(CameraMatrix);

		PixelShader = Default;
		Color c;
		Color b;
		Color d = c + b;
		ClearBuffer();
		SV_WorldMatrix = Matrix::Identity();
		DrawMesh(m, false);







	} while (RS_Update(image_pixels, imagePixelCount));
	RS_Shutdown();
	delete[] image_pixels;
	return 0;
}


