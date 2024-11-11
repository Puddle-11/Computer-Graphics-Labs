#define _USE_MATH_DEFINES

#include "Matrix.h"
#include <iostream>
#include <cmath>

#include "Vector3.h"
//TODO: Matrix * Matrix

//TODO: Vector4 * Matrix

Matrix::Matrix()
{
	float arr[4][4] =
	{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	SetMatrix(arr);
}
Matrix::Matrix(float matrixValue[4][4])
{
	SetMatrix(matrixValue);

}
Matrix Matrix::Identity()
{
	Matrix m;
	float mVals[4][4]{
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
	};
	m.SetMatrix(mVals);
	return m;

}

Matrix Matrix::ProjectionMatrix(float near, float far, float FOV, float aspectRatio)
{
	Matrix m;
	FOV = (FOV * M_PI) / 180;
	float YScale = cos(FOV/2) / sin(FOV/2);
	

	float XScale = YScale * aspectRatio;

	float mVals[4][4]{
		{XScale,     0,         0,                  0},
		{0,       YScale,       0,                  0},
		{0,          0,   far/(far-near),           1},
		{0,          0,   -(far*near)/(far-near),   0},
	};
	m.SetMatrix(mVals);
	return m;
}

Matrix Matrix::Invert(Matrix m)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (x > y)
			{

				float temp = m.matrixValues[x][y];
				m.matrixValues[x][y] = m.matrixValues[y][x];
				m.matrixValues[y][x] = temp;
			}
		}
	}
	Vector3 pos = Vector3(m.matrixValues[3][0], m.matrixValues[3][1], m.matrixValues[3][2]);
	pos = pos * m;
	pos = pos * -1;
	m.matrixValues[3][0] = pos.x;
	m.matrixValues[3][1] = pos.y;
	m.matrixValues[3][2] = pos.z;

	return m;

}
Matrix Matrix::TranslationMatrix(float x, float y, float z)
{
	Matrix m;
	float mVals[4][4]{
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{x,y,z,1}
	};
	m.SetMatrix(mVals);
	return m;
}

Matrix Matrix::ScaleMatrix(float _val)
{
	Matrix m;
	float mVals[4][4]{
		{_val,0,0,0},
		{0,_val,0,0},
		{0,0,_val,0},
		{0,0,0,1}
	};
	m.SetMatrix(mVals);
	return m;
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

Matrix Matrix::XRotationMatrix(float rad)
{
	float sinV = sin(rad);
	float cosV = cos(rad);

	float mVals[4][4]{
		{1,0,0,0},
		{0, cosV, -sinV, 0},
		{ 0, sinV, cosV, 0 },
		{0,0,0,1}
	};
	Matrix res;
	res.SetMatrix(mVals);
	return res;
}
Matrix Matrix::YRotationMatrix(float rad)
{

	float mVals[4][4]{
	{cos(rad), 0, sin(rad), 0},
	{0, 1, 0, 0},
	{-sin(rad), 0, cos(rad), 0},
	{0, 0, 0, 1}
	};
	Matrix res;
	res.SetMatrix(mVals);
	return res;
}
Matrix Matrix::ZRotationMatrix(float rad)
{
	float mVals[4][4]{
	{cos(rad), -sin(rad),0, 0},
	{sin(rad), cos(rad), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
	};
	Matrix res;
	res.SetMatrix(mVals);
	return res;
}
void Matrix::SetMatrix(Matrix m)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			matrixValues[x][y] = m.matrixValues[x][y];
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
			res += std::to_string(matrixValues[x][y]) + ", ";
		}
		res += "\n";
	}
	return res;
}
Matrix Matrix::operator*(Matrix _ref)
{
	Matrix res = *this;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float sum = 0;
			for (int k = 0; k < 4; k++)
			{
				sum += matrixValues[i][k] * _ref.matrixValues[k][j];
			}
			res.matrixValues[i][j] = sum;
		}
	}
	return res;
}
Matrix Matrix::operator=(Matrix const& _ref)
{

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			matrixValues[x][y] = _ref.matrixValues[x][y];
		}
	}
	return *this;
}
Matrix Matrix::operator+(Matrix const& _ref)
{
	Matrix res = *this;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			res.matrixValues[x][y] += _ref.matrixValues[x][y];
		}
	}
	return res;
}

