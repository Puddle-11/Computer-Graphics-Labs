#pragma once
#include "GlobalDefines.h"
void (*VertexShader)(Vertex4D&) = 0;

void (*PixelShader)(VertexScreen&) = 0;

Matrix SV_WorldMatrix;
Matrix SV_View;
Matrix SV_Proj;
void ToWorld(Vertex4D&_vert)
{


	_vert.point = _vert.point * SV_WorldMatrix;
	_vert.point = _vert.point * SV_View;

	_vert.point = _vert.point * SV_Proj;

	_vert.point.x /= _vert.point.w;
    _vert.point.y /= _vert.point.w;
	_vert.point.z /= _vert.point.w;


}
void White(VertexScreen& _pixel)
{
	_pixel.vertColor = Color::White();
}
void Depth(VertexScreen& _pixel)
{
	float z = ((_pixel.GetZ()) / 10);
	if (z > 1) z = 1;
	if (z < 0) z = 0;
	_pixel.vertColor = Color::CLerp(Color::Black(), Color::White(), z * 255);
}

//TODO: NDCtoScreen

//TODO: Vertex Shader

//TODO: Pixel shader

//TODO: 3D line drawer

