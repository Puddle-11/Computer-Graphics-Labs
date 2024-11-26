#pragma once
#include "Vector2Int.h"
#include "Vector3.h"
#include <cmath>
float ILE(Vector2Int l1, Vector2Int l2, Vector2Int p1)
{
	float A = (l1.y-l2.y) * p1.x;
	float B = (l2.x-l1.x) * p1.y;
	float C = (l1.x * l2.y) - (l2.x * l1.y);
	
	float xPow = (l2.x - l1.x) * (l2.x - l1.x);
	float yPow = (l2.y - l1.y) * (l2.y - l1.y);
	float mag = abs(sqrt(xPow + yPow));

	float result = (A+B+C);
	result /= mag;

	return  result;
}
float Distance(Vector3 _p1, Vector3 _p2)
{
	float xPow = (_p2.x - _p1.x) * (_p2.x - _p1.x);
	float yPow = (_p2.y - _p1.y) * (_p2.y - _p1.y);
	float zPow = (_p2.z - _p1.z) * (_p2.z - _p1.z);

	float mag = abs(sqrt(xPow + yPow + zPow));
	return mag;
}
float Clamp(float min, float max, float _val)
{
	if (_val > max) _val = max;
	else if (_val < min) _val = min;
	return _val;
}
Vector3 Cross(Vector3 v1, Vector3 v2)
{
	Vector3 res;
	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return res;


}
Vector3 Cross(Vector4 v1, Vector4 v2)
{
	Vector3 res;
	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return res;


}
float Dot(Vector3 v1, Vector3 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.y * v2.y;
}