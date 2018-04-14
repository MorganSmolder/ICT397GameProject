#include "mat4.h"

void mat4::operator = (const mat4 & rhs) {
	matrix = rhs.matrix;
}

float & mat4::operator [] (int index) {
	int internalind;
	if (index <= 3) internalind = 0;
	else if (index <= 7) internalind = 1;
	else if (index <= 11) internalind = 2;
	else internalind = 3;

	return matrix[internalind][index / internalind];
}

mat4 mat4::operator += (const mat4 & rhs) {
	matrix += rhs.matrix;
	return *this;
}

mat4 mat4::operator *= (const mat4 & rhs) {
	matrix *= rhs.matrix;
	return *this;
}

mat4 mat4::operator /= (const mat4 & rhs) {
	matrix /= rhs.matrix;
	return *this;
}

mat4 mat4::operator -= (const mat4 & rhs) {
	matrix -= rhs.matrix;
	return *this;
}

mat4 mat4::operator + (const mat4 & rhs) {
	return mat4(matrix + rhs.matrix);
}

mat4 mat4::operator * (const mat4 & rhs) {
	return mat4(matrix * rhs.matrix);
}

mat4 mat4::operator / (const mat4 & rhs) {
	return mat4(matrix / rhs.matrix);
}

mat4 mat4::operator - (const mat4 & rhs) {
	return mat4(matrix - rhs.matrix);
}

mat4 mat4::operator + (const float rhs) {
	return mat4(matrix + rhs);
}

mat4 mat4::operator * (const float rhs) {
	return mat4(matrix * rhs);
}

mat4 mat4::operator / (const float rhs) {
	return mat4(matrix / rhs);
}

mat4 mat4::operator - (const float rhs) {
	return mat4(matrix - rhs);
}

mat4 mat4::operator += (const float rhs) {
	matrix += rhs;
	return *this;
}

mat4 mat4::operator *= (const float rhs) {
	matrix *= rhs;
	return *this;
}

mat4 mat4::operator /= (const float rhs) {
	matrix /= rhs;
	return *this;
}

mat4 mat4::operator -= (const float rhs) {
	matrix -= rhs;
	return *this;
}
