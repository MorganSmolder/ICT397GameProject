#include "vec3.h"

void vec3::operator = (const vec3 & rhs) {
	vector = rhs.vector;
}

float vec3::x() const
{
	return vector.x;
}

float vec3::y() const
{
	return vector.y;
}

float vec3::z() const
{
	return vector.z;
}

float vec3::sx(float nx)
{
	vector.x = nx;
	return vector.x;
}

float vec3::sy(float ny)
{
	vector.y = ny;
	return vector.y;
}

float vec3::sz(float nz)
{
	vector.z = nz;
	return vector.z;
}

vec3 vec3::cross(const vec3 & rhs) {
	return glm::cross(vector, rhs.vector);
}

vec3 vec3::normalise() {
	return glm::normalize(vector);
}

void vec3::normailse() {
	vector = glm::normalize(vector);
}

float vec3::dot(const vec3 & rhs) {
	return glm::dot(vector, rhs.vector);
}

float vec3::angle(const vec3 & rhs) {
	return glm::angle(vector, rhs.vector);
}

float& vec3::operator [] (int index) {
	return vector[index];
}

vec3 vec3::operator += (const vec3 & rhs) {
	vector += rhs.vector;
	return *this;
}

vec3 vec3::operator *= (const vec3 & rhs) {
	vector *= rhs.vector;
	return *this;
}

vec3 vec3::operator /= (const vec3 & rhs) {
	vector /= rhs.vector;
	return *this;
}

vec3 vec3::operator -= (const vec3 & rhs) {
	vector -= rhs.vector;
	return *this;
}

vec3 vec3::operator + (const vec3 & rhs) {
	return vec3(vector + rhs.vector);
}

vec3 vec3::operator * (const vec3 & rhs) {
	return vec3(vector * rhs.vector);
}

vec3 vec3::operator / (const vec3 & rhs) {
	return vec3(vector / rhs.vector);
}

vec3 vec3::operator - (const vec3 & rhs) {
	return vec3(vector - rhs.vector);
}

vec3 vec3::operator + (const float rhs) {
	return vec3(vector + rhs);
}

vec3 vec3::operator * (const float rhs) {
	return vec3(vector * rhs);
}

vec3 vec3::operator / (const float rhs) {
	return vec3(vector / rhs);
}

vec3 vec3::operator - (const float rhs) {
	return vec3(vector - rhs);
}

vec3 vec3::operator += (const float rhs) {
	vector += rhs;
	return *this;
}

vec3 vec3::operator *= (const float rhs) {
	vector *= rhs;
	return *this;
}

vec3 vec3::operator /= (const float rhs) {
	vector /= rhs;
	return *this;
}

vec3 vec3::operator -= (const float rhs) {
	vector -= rhs;
	return *this;
}