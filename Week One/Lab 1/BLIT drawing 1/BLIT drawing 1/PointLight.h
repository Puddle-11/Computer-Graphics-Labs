#pragma once
#include "Vector3.h"
#include "Color.h"
class PointLight
{
public:
	Vector3 position;
	float intensity;
	float range;
	Color tint;
	float tintWeight;
	PointLight(Vector3 _pos, float _intensity, float _range, Color _tint, float _tintWeight);
	PointLight();

private:

};

