#include "Matrix.h"

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
