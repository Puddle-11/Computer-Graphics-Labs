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


	SV_Proj = Matrix::ProjectionMatrix(0.1, 10, 90, AspectRatio);



	float time = 0;
	bufferColorb.SetRed(10);
	bufferColorb.SetGreen(18);
	bufferColorb.SetBlue(41);
	bufferColort = Color::Black();
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

	worldLight2.angle = Vector4(1, 0.1, 0, 1);
	worldLight2.shadowIntensity = 0.85;
	worldLight2.intensity = 0.7;
	ShadowColor = Color::Black();
	worldLight2.tint = Color::Orange();
	worldLight2.tintWeight = 0.7;

	pl.intensity = 1;
	pl.tint = Color::Orange();
	pl.tintWeight = 1;
	pl.position = Vector3(0, 5, 0);
	pl.shadowIntensity = 1;
	float flickerTimer = 0;

	Particle particles[50]{
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 3),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 1, 2),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 4),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 3.5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 2, 5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 3),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 2),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 4),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 3, 3.5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 4, 5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 3),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 1, 2),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 4),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 3.5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 2, 5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 3),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 2),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 4),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 3, 3.5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 4, 5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 3),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 1, 2),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 4),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 3.5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 2, 5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 3),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 2),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 4),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 3, 3.5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 4, 5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 3),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 1, 2),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 4),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 3.5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 2, 5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 3),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 2),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 4),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 3, 3.5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 4, 5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 3),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 1, 2),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 4),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 3.5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 2, 5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 3),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 5, 2),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 5, 4),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 1, Color::Red(), Color::Yellow(), 3, 3.5),
	Particle(Vector3(0,0,0), Vector4(0,0,0,1), 2, Color::Red(), Color::Yellow(), 4, 5),
	};


	Vertex4D* stars = new Vertex4D[3000];

	for (int i = 0; i < 3000; i++)
	{
		//stars[i].point = Vector4(rand()%100/(float)100, rand() % 100 / (float)100, rand() % 100 / (float)100, 1).Normalize();
		stars[i].point = Vector4((rand() % 100 / (float)100) - 0.5, (rand() % 100 / (float)100) - 0.5, (rand() % 100 / (float)100) - 0.5, 1).Normalize();

		switch (rand() % 3)
		{
		case 0:
			stars[i].vertColor.SetRed(122);
			stars[i].vertColor.SetGreen(181);
			stars[i].vertColor.SetBlue(196);
			break;
		case 1:

			stars[i].vertColor.SetRed(255);
			stars[i].vertColor.SetGreen(212);
			stars[i].vertColor.SetBlue(143);
			break;
		case 2:

			stars[i].vertColor.SetRed(255);
			stars[i].vertColor.SetGreen(222);
			stars[i].vertColor.SetBlue(214);
			break;
		}
		stars[i].point.x *= 500;
		stars[i].point.y *= 500;
		stars[i].point.z *= 500;


	}











	for (int i = 0; i < 50; i++)
	{
		particles[i].timeStep = rand() % 500 / 100;
		particles[i].pos = Vector3((rand() % 300) / 100, 2 + (rand() % 300) / 100, (rand() % 300) / 100);
		particles[i].lifetime = rand() % 2 + 5;
	}


	int sceneNum = 0;
	RS_Initialize("Rowan Byington Lab 3", mainBounds.Width, mainBounds.Height);
	do
	{

		timer.Signal();
		POINT p;
		GetCursorPos(&p);
		time += timer.Delta();
		if (GetAsyncKeyState(0x0D) & 0x1)
		{
			sceneNum = (sceneNum + 1) % 2;
		}


		//pl.range = ((sin(time) + 1) / 2) * 50;





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

		ClearBuffer();
		PixelShader = nullptr;
		SV_WorldMatrix = Matrix::Identity();

		for (int i = 0; i < 3000; i++)
		{

			PlotShadedPoint(stars[i]);
		}
		PixelShader = Default;
		DrawMesh(m, false);

		if (sceneNum == 1)
		{

			if (flickerTimer >= 0.12)
			{
				flickerTimer = 0;
				pl.range = rand() % 10 + 30;
				pl.intensity = rand() % 100 / 200 + 1;
			}
			else
			{
				flickerTimer += timer.Delta();
			}
			PixelShader = nullptr;
			for (int i = 0; i < 50; i++)
			{
				particles[i].timeStep += timer.Delta();
				for (int j = 0; j < cube.vertCount; j++)
				{
					cube.verticies[j].vertColor = Color::CLerp(particles[i].c1, particles[i].c2, (particles[i].timeStep / particles[i].lifetime) * 255);
				}
				SV_WorldMatrix = Matrix::ScaleMatrix(Clamp(0, 5, lerp(particles[i].Scale, 0, particles[i].timeStep / particles[i].lifetime)) * particles[i].Scale) * Matrix::TranslationMatrix(particles[i].pos.x, particles[i].pos.y + particles[i].timeStep * particles[i].speed, particles[i].pos.z);
				if (particles[i].timeStep >= particles[i].lifetime)
				{
					particles[i].timeStep = 0;
					particles[i].pos = Vector3(rand() % 300 / 100, 2 + rand() % 300 / 100, rand() % 300 / 100);
					particles[i].lifetime = rand() % 2 + 5;

				}
				DrawMesh(cube, true);

			}

		}
		else
		{

			pl.range = (sin(flickerTimer) + 1) / 2 * 30;
			pl.intensity = 1;
			flickerTimer += timer.Delta();

		}

	} while (RS_Update(image_pixels, imagePixelCount));
	RS_Shutdown();
	delete[] image_pixels;
	return 0;
}


