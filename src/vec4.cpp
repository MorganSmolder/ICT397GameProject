#include "vec4.h"

void vec4::operator = (const vec4 & rhs) {
	vector = rhs.vector;
}

float vec4::x() const {
	return vector.x;
}

float vec4::y() const {
	return vector.y;
}

float vec4::z() const {
	return vector.z;
}

float vec4::w() const {
	return vector.w;
}

float vec4::sx(float nx) {
	vector.x = nx;
	return vector.x;
}

float vec4::sy(float ny) {
	vector.y = ny;
	return vector.y;
}

float vec4::sz(float nz) {
	vector.z = nz;
	return vector.z;
}

float vec4::sw(float nw) {
	vector.w = nw;
	return vector.w;
}

vec4 vec4::normalise() {
	return glm::normalize(vector);
}

void vec4::normailse() {
	vector = glm::normalize(vector);
}

float vec4::dot(const vec4 & rhs) {
	return glm::dot(vector, rhs.vector);
}

float vec4::angle(const vec4 & rhs) {
	return glm::angle(vector, rhs.vector);
}

float vec4::operator [] (int index) {
	return vector[index];
}

vec4 vec4::operator += (const vec4 & rhs) {
	vector += rhs.vector;
	return *this;
}

vec4 vec4::operator *= (const vec4 & rhs) {
	vector *= rhs.vector;
	return *this;
}

vec4 vec4::operator /= (const vec4 & rhs) {
	vector /= rhs.vector;
	return *this;
}

vec4 vec4::operator -= (const vec4 & rhs) {
	vector -= rhs.vector;
	return *this;
}

vec4 vec4::operator + (const vec4 & rhs) {
	return vec4(vector + rhs.vector);
}

vec4 vec4::operator * (const vec4 & rhs) {
	return vec4(vector * rhs.vector);
}

vec4 vec4::operator / (const vec4 & rhs) {
	return vec4(vector / rhs.vector);
}

vec4 vec4::operator - (const vec4 & rhs) {
	return vec4(vector - rhs.vector);
}

vec4 vec4::operator + (const float rhs) {
	return vec4(vector + rhs);
}

vec4 vec4::operator * (const float rhs) {
	return vec4(vector * rhs);
}

vec4 vec4::operator / (const float rhs) {
	return vec4(vector / rhs);
}

vec4 vec4::operator - (const float rhs) {
	return vec4(vector - rhs);
}

vec4 vec4::operator += (const float rhs) {
	vector += rhs;
	return *this;
}

vec4 vec4::operator *= (const float rhs) {
	vector *= rhs;
	return *this;
}

vec4 vec4::operator /= (const float rhs) {
	vector /= rhs;
	return *this;
}

vec4 vec4::operator -= (const float rhs) {
	vector -= rhs;
	return *this;
}