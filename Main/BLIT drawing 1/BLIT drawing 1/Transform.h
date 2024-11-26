#pragma once
#include "Matrix.h"
#include "Vector3.h"
class Transform
{
private:

	Matrix RotationMatrix;


public:
	Vector3 Position;
	Vector3 eulerAngles; //in degrees
	Transform();
	~Transform();

private:

};