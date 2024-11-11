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
	Matrix operator=(Matrix const& _ref);
	Matrix operator+(Matrix const& _ref);

	static Matrix Identity();
	void SetMatrix(Matrix m);
	static Matrix XRotationMatrix(float rad);
	static Matrix YRotationMatrix(float rad);
	static Matrix ZRotationMatrix(float rad);
	static Matrix TranslationMatrix(float x, float y, float z);
	static Matrix ScaleMatrix(float _val);
	static Matrix Invert(Matrix m);
	static Matrix ProjectionMatrix(float near, float far, float FOV, float aspectRatio);
};

