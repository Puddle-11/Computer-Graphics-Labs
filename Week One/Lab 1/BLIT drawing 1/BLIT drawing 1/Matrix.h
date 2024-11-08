#pragma once
#include <string>
class Matrix
{
public:
	float matrixValues[4][4];
	Matrix();
	Matrix(float matrixValue[4][4]);
	void SetMatrix(float matrixValue[4][4]);
	std::string ToString();
	Matrix operator*(Matrix _ref);

};

