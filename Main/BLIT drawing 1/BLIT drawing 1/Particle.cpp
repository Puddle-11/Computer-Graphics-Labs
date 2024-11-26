#include "Particle.h"
Particle::Particle()
{
	timeStep = 0;
}
Particle::~Particle()
{

}
Particle::Particle(Vector3 _pos, Vector4 _rot, float _scale, Color _c1, Color _c2, float _lifetime, float _speed)
{
	pos = _pos;
	rot = _rot;
	Scale = _scale;
	c1 = _c1;
	c2 = _c2;
	lifetime = _lifetime;
	timeStep = 0;
	speed = _speed;

}