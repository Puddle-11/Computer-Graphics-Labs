#pragma once
#include "Vector4.h"
#include "Color.h"
class DirectionalLight
{
public:
	Vector4 angle;
	float intensity; //<-- between 0 1
	Color tint;
	float tintWeight;
	float shadowIntensity;
	DirectionalLight(Vector4 _angle, float _intensity, Color _c);
	DirectionalLight();

private:

};

