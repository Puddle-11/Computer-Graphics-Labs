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
float ambient = 0.1;
void ApplyLighting(VertexScreen& _pixel, Vector3 lightVec, Color _tint, float tintWeight, float intensity, float shadowIntensity);
void ToWorld(Vertex4D&_vert)
{


	_vert.point = _vert.point * SV_WorldMatrix;
	_vert.point = _vert.point * SV_View;

	_vert.point = _vert.point * SV_Proj;
	if (_vert.point.w <= NearPlane) return;
	_vert.point.x /= _vert.point.w;
    _vert.point.y /= _vert.point.w;
	_vert.point.z /= _vert.point.w;

}

void Default(VertexScreen& _pixel)
{

	VertexScreen t1 = _pixel;
	VertexScreen t2 = _pixel;
	VertexScreen t3 = _pixel;

	ApplyLighting(t2, Vector3(worldLight2.angle.x, worldLight2.angle.y, worldLight2.angle.z), worldLight2.tint, worldLight2.tintWeight, worldLight2.intensity, worldLight2.shadowIntensity);
	ApplyLighting(t1, Vector3(worldLight.angle.x, worldLight.angle.y, worldLight.angle.z), worldLight.tint, worldLight.tintWeight, worldLight.intensity, worldLight.shadowIntensity);
	
	float pointVal = lerp(1, 0, Clamp(0, 1, Distance(_pixel.worldPos, pl.position) / pl.range));
	ApplyLighting(t3,  (pl.position-_pixel.worldPos).Normalize(), pl.tint, 1, pl.intensity * (pointVal * pointVal), pl.shadowIntensity);

	_pixel.vertColor = t2.vertColor + t1.vertColor + t3.vertColor;
}


void ApplyLighting(VertexScreen& _pixel, Vector3 lightVec, Color _tint, float tintWeight, float intensity, float shadowIntensity)
{

	if (intensity <= 0.01)
	{
		_pixel.vertColor = Color::Black();
		return;
	}
	Vector4 worldLightNormal = Vector4(lightVec.x, lightVec.y, lightVec.z, 1).Normalize();

	float dot = Dot(lightVec, _pixel.normal);

	dot = Clamp(0, 1, dot + ambient);
	
	Color filterTint = Color::CLerp(_tint, Color::White(), tintWeight * 255);
	filterTint = Color::CLerp(filterTint, Color::Black(), intensity * 255);
	Color temp = _pixel.vertColor;
	_pixel.vertColor = filterTint * dot;
	_pixel.vertColor = temp * _pixel.vertColor;


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

