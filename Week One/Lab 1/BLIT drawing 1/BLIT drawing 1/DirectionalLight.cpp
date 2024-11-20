#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(Vector3 _angle, float _intensity, Color _c)
{
	angle = _angle;
	intensity = _intensity;
	tint = _c;
}

DirectionalLight::DirectionalLight()
{
	angle = Vector3::Zero();
	intensity = 1;
	tint = Color::White();
}