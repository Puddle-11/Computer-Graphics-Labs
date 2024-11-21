#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(Vector4 _angle, float _intensity, Color _c)
{
	angle = _angle;
	intensity = _intensity;
	tint = _c;
}

DirectionalLight::DirectionalLight()
{
	angle = Vector4::Zero();
	intensity = 1;
	tint = Color::White();
}