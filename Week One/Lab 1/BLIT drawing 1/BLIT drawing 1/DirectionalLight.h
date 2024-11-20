#pragma once
#include "Vector3.h"
#include "Color.h"
class DirectionalLight
{
public:
	Vector3 angle;
	float intensity; //<-- between 0 1
	Color tint;

	DirectionalLight(Vector3 _angle, float _intensity, Color _c);
	DirectionalLight();

private:

};

