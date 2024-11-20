#pragma once
#include "GlobalDefines.h"
#include "DirectionalLight.h"
void (*VertexShader)(Vertex4D&) = 0;

void (*PixelShader)(VertexScreen&) = 0;

Matrix SV_WorldMatrix;
Matrix SV_View;
Matrix SV_Proj;
DirectionalLight worldLight;
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
	_pixel.vertColor = Color::CLerp(_pixel.vertColor, Color::Black(), worldLight.intensity * 255);
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

