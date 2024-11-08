#include "Matrix.h"

//TODO: Matrix * Matrix

//TODO: Vector4 * Matrix

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
Matrix::Matrix(float matrixValue[4][4])
{
	SetMatrix(matrixValue);

}
void Matrix::SetMatrix(float _matrixValue[4][4])
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			matrixValues[x][y] = _matrixValue[x][y];
		}
	}
}
std::string Matrix::ToString()
{
	std::string res = "";
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			res += std::to_string((int)matrixValues[x][y]) + ", ";
		}
		res += "\n";
	}
	return res;
}
Matrix Matrix::operator*(Matrix _ref)
{

}
