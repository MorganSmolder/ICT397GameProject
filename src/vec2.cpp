#include "vec2.h"

void vec2::operator = (const vec2 & rhs) {
	vector = rhs.vector;
}

float vec2::x()
{
	return vector.x;
}

float vec2::y()
{
	return vector.y;
}

vec2 vec2::normalise() {
	return glm::normalize(vector);
}

void vec2::normailse() {
	vector = glm::normalize(vector);
}

float vec2::dot(const vec2 & rhs) {
	return glm::dot(vector, rhs.vector);
}

float vec2::angle(const vec2 & rhs) {
	return glm::angle(vector, rhs.vector);
}

float& vec2::operator [] (int index) {
	return vector[index];
}

float vec2::sx(float nx) {
	vector.x = nx;
	return vector.x;
}
float vec2::sy(float ny) {
	vector.y = ny;
	return vector.y;
}

vec2 vec2::operator += (const vec2 & rhs) {
	vector += rhs.vector;
	return *this;
}

vec2 vec2::operator /= (const vec2 & rhs) {
	vector /= rhs.vector;
	return *this;
}

vec2 vec2::operator *= (const vec2 & rhs) {
	vector *= rhs.vector;
	return *this;
}

vec2 vec2::operator -= (const vec2 & rhs) {
	vector -= rhs.vector;
	return *this;
}

vec2 vec2::operator + (const vec2 & rhs) {
	return vec2(vector + rhs.vector);
}

vec2 vec2::operator * (const vec2 & rhs) {
	return vec2(vector * rhs.vector);
}

vec2 vec2::operator / (const vec2 & rhs) {
	return vec2(vector / rhs.vector);
}

vec2 vec2::operator - (const vec2 & rhs) {
	return vec2(vector - rhs.vector);
}

vec2 vec2::operator + (const float rhs) {
	return vec2(vector + rhs);
}

vec2 vec2::operator * (const float rhs) {
	return vec2(vector * rhs);
}

vec2 vec2::operator / (const float rhs) {
	return vec2(vector / rhs);
}

vec2 vec2::operator - (const float rhs) {
	return vec2(vector - rhs);
}

vec2 vec2::operator += (const float rhs) {
	vector += rhs;
	return *this;
}

vec2 vec2::operator *= (const float rhs) {
	vector *= rhs;
	return *this;
}

vec2 vec2::operator /= (const float rhs) {
	vector /= rhs;
	return *this;
}

vec2 vec2::operator -= (const float rhs) {
	vector -= rhs;
	return *this;
}