#include "mat4.h"
#include "vec3.h"

mat4::mat4()
{

}

mat4::mat4(const mat4 & m)
{
	matrix = m.getMat();
}

glm::mat4 mat4::getMat() const
{
	return matrix;
}

void mat4::setMat(glm::mat4 mat)
{
	matrix = mat;
}

vec4 mat4::operator* (const vec4 & v)
{
	glm::vec4 tmpglm;
	tmpglm = matrix * v.getVec();

	vec4 tmp;
	tmp.setVec(tmpglm);

	return tmp;
}

void mat4::operator = (const mat4 & m)
{
	matrix = m.getMat();
}

float & mat4::operator[] (int index)
{
	int i;

	if (index <= 3)
	{
		i = 0;
	}
	else if (index <= 7)
	{
		i = 1;
	}
	else if (i <= 11)
	{
		i = 2;
	}
	else
	{
		i = 3;
	}

	return matrix[i][index / i];
}

mat4 mat4::operator += (const mat4 & m)
{
	matrix += m.getMat();
	return *this;
}

mat4 mat4::operator *= (const mat4 & m)
{
	matrix *= m.getMat();
	return *this;
}

mat4 mat4::operator /= (const mat4 & m)
{
	matrix /= m.getMat();
	return *this;
}

mat4 mat4::operator -= (const mat4 & m)
{
	matrix -= m.getMat();
	return *this;
}

mat4 mat4::operator + (const mat4 & m)
{
	mat4 tmp;
	tmp.setMat(matrix + m.getMat());
	return tmp;
}

mat4 mat4::operator - (const mat4 & m)
{
	mat4 tmp;
	tmp.setMat(matrix - m.getMat());
	return tmp;
}

mat4 mat4::operator * (const mat4 & m)
{
	mat4 tmp;
	tmp.setMat(matrix * m.getMat());
	return tmp;
}

mat4 mat4::operator / (const mat4 & m)
{
	mat4 tmp;
	tmp.setMat(matrix / m.getMat());
	return tmp;
}

mat4 mat4::operator += (const float f)
{
	matrix += f;
	return *this;
}

mat4 mat4::operator *= (const float f)
{
	matrix *= f;
	return *this;
}

mat4 mat4::operator /= (const float f)
{
	matrix /= f;
	return *this;
}

mat4 mat4::operator -= (const float f)
{
	matrix -= f;
	return *this;
}

mat4 mat4::operator + (const float f)
{
	mat4 tmp;
	tmp.setMat(matrix + f);
	return tmp;
}

mat4 mat4::operator - (const float f)
{
	mat4 tmp;
	tmp.setMat(matrix - f);
	return tmp;
}

mat4 mat4::operator * (const float f)
{
	mat4 tmp;
	tmp.setMat(matrix * f);
	return tmp;
}

mat4 mat4::operator / (const float f)
{
	mat4 tmp;
	tmp.setMat(matrix / f);
	return tmp;
}
