#include "vector3.hpp"

Vector3::Vector3() : Vector3(0, 0, 0) {}

Vector3::Vector3(float x, float y, float z) :
	x(x), y(y), z(z)
{}

Vector3::Vector3(const Vector3& v) :
	x(v.x), y(v.y), z(v.z)
{}

Vector3 Vector3::operator+(const Vector3& v) const {
	Vector3 r;
	r.x = x + v.x;
	r.y = y + v.y;
	r.z = z + v.z;
	return r;
}

Vector3 Vector3::operator-(const Vector3& v) const {
	Vector3 r;
	r.x = x - v.x;
	r.y = y - v.y;
	r.z = z - v.z;
	return r;
}

Vector3 Vector3::operator*(float s) const {
	Vector3 r;
	r.x = x * s;
	r.y = y * s;
	r.z = z * s;
	return r;
}

Vector3& Vector3::operator+=(const Vector3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector3& Vector3::operator+=(float s) {
	x += s;
	y += s;
	z += s;
	return *this;
}

Vector3& Vector3::operator-=(float s) {
	x -= s;
	y -= s;
	z -= s;
	return *this;
}