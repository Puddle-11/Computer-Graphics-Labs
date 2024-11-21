#pragma once
#include "GlobalDefines.h"
#include "DirectionalLight.h"
#include <cmath>
#include "BLITVars.h"
#include "PointLight.h"
void (*VertexShader)(Vertex4D&) = 0;

void (*PixelShader)(VertexScreen&) = 0;

Matrix SV_WorldMatrix;
Matrix SV_View;
Matrix SV_Proj;
DirectionalLight worldLight;
DirectionalLight worldLight2;

PointLight pl;
Color ShadowColor;

void ApplyLighting(VertexScreen& _pixel, Vector3 lightVec, Color _tint, float tintWeight, float intensity, float shadowIntensity);
void ToWorld(Vertex4D&_vert)
{


	_vert.point = _vert.point * SV_WorldMatrix;
	_vert.point = _vert.point * SV_View;

	_vert.point = _vert.point * SV_Proj;

	_vert.point.x /= _vert.point.w;
    _vert.point.y /= _vert.point.w;
	_vert.point.z /= _vert.point.w;
}
void Default(VertexScreen& _pixel)
{

	VertexScreen t1 = _pixel;
	VertexScreen t2 = _pixel;



	ApplyLighting(t1, Vector3(worldLight.angle.x, worldLight.angle.y, worldLight.angle.z), worldLight.tint, worldLight.tintWeight, worldLight.intensity, worldLight.shadowIntensity);
	ApplyLighting(t2, Vector3(worldLight2.angle.x, worldLight2.angle.y, worldLight2.angle.z), worldLight2.tint, worldLight2.tintWeight, worldLight2.intensity, worldLight2.shadowIntensity);
	_pixel.vertColor = Color::CLerp(t1.vertColor, t2.vertColor, 0.5*255);
		//_pixel.vertColor = t1.vertColor;

	
	//Vector4 worldLightNormal = worldLight.angle.Normalize();

	//float dot = _pixel.normal.x * worldLightNormal.x + _pixel.normal.y * worldLightNormal.y + _pixel.normal.y * worldLightNormal.y;
	//dot = Clamp(0, 1, dot);
	//float shadowR = dot * worldLight.intensity; 
	//shadowR += (worldLight.shadowIntensity - 1) * -1;
	//shadowR *= 255;

	//Color filterTint = Color::CLerp(worldLight.tint, Color::White(), worldLight.tintWeight * 255);

	//float rR = (filterTint.GetRed() / (float)255);
	//float gR = (filterTint.GetGreen() / (float)255);
	//float bR = (filterTint.GetBlue() / (float)255);
	//int red = _pixel.vertColor.GetRed();
	//int green = _pixel.vertColor.GetGreen();
	//int blue = _pixel.vertColor.GetBlue();

	//red *= rR;
	//green *= gR;
	//blue *= bR;

	//_pixel.vertColor.SetRed(red);
	//_pixel.vertColor.SetGreen(green);
	//_pixel.vertColor.SetBlue(blue);

	//_pixel.vertColor = Color::CLerp(_pixel.vertColor, ShadowColor, shadowR);
}
void ApplyLighting(VertexScreen& _pixel, Vector3 lightVec, Color _tint, float tintWeight, float intensity, float shadowIntensity)
{
	
	Vector4 worldLightNormal = Vector4(lightVec.x, lightVec.y, lightVec.z, 1).Normalize();

	float dot = _pixel.normal.x * worldLightNormal.x + _pixel.normal.y * worldLightNormal.y + _pixel.normal.y * worldLightNormal.y;
	dot = Clamp(0, 1, dot);
	float shadowR = dot * intensity;
	shadowR += (shadowIntensity - 1) * -1;
	shadowR *= 255;


	
	Color filterTint = Color::CLerp(_tint, Color::White(), tintWeight * 255);

	float rR = (filterTint.GetRed() / (float)255);
	float gR = (filterTint.GetGreen() / (float)255);
	float bR = (filterTint.GetBlue() / (float)255);
	int red = _pixel.vertColor.GetRed();
	int green = _pixel.vertColor.GetGreen();
	int blue = _pixel.vertColor.GetBlue();

	red *= rR;
	green *= gR;
	blue *= bR;

	Color temp;
	temp.SetRed(red);
	temp.SetGreen(green);
	temp.SetBlue(blue);

	_pixel.vertColor = Color::CLerp(temp, ShadowColor, shadowR);

}
void White(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::White();
}
void Green(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Green();

}
void Blue(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Blue();

}
void Red(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Red();

}
void Orange(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Orange();

}
void Lime(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Lime();

}
void Violet(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Violet();

}
void Pink(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Pink();

}
void Teal(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Teal();

}
void Azure(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Azure();

}
void Magenta(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Magenta();

}
void Yellow(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Yellow();

}
void Cyan(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Cyan();

}
void Depth(VertexScreen& _pixel)
{
	float z = ((_pixel.GetZ()) / 10);
	if (z > 1) z = 1;
	if (z < 0) z = 0;
	_pixel.vertColor = Color::CLerp(Color::Black(), Color::White(), z * 255);
}
void Rainbow(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::Black();
	_pixel.vertColor.SetRed(_pixel.point.x / (float)ImageWidth * 255);
	_pixel.vertColor.SetGreen(_pixel.point.y / (float)ImageHeight * 255);

	_pixel.vertColor.SetBlue((_pixel.GetZ()) / 10 * 255);

}
//TODO: NDCtoScreen

//TODO: Vertex Shader

//TODO: Pixel shader

//TODO: 3D line drawer

