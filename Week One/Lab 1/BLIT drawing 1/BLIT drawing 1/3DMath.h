#pragma once
#include "Vector2Int.h"
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
