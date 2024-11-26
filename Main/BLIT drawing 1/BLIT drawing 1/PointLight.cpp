#include "PointLight.h"
PointLight::PointLight()
{
	position = Vector3::Zero();
	intensity = 1;
	range = 1;
	tint = Color::White();
	tintWeight = 1;
}
PointLight::PointLight(Vector3 _pos, float _intensity, float _range, Color _tint, float _tintWeight, float _si)
{
	position = _pos;
	intensity = _intensity;
	range = _range;
	tint = _tint;
	tintWeight = _tintWeight;
	shadowIntensity = _si;
}