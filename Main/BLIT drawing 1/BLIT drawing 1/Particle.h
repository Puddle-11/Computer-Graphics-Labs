#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include "Color.h"
class Particle
{
public:
	Vector3 pos;
	Vector4 rot;
	float Scale;
	Color c1;
	Color c2;
	float lifetime;
	float timeStep;
	float speed;

	Particle();
	Particle(Vector3 _pos, Vector4 _rot, float _scale, Color _c1, Color _c2, float _lifetime, float _speed);

	~Particle();

private:

};

