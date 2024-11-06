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
private:

};
Matrix::Matrix()
{
	float arr[4][4] =
	{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0} ,
		{0, 0, 0, 0}

	};
	SetMatrix(arr);
}
