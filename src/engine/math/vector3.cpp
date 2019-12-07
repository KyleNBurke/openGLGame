#include "vector3.hpp"
#include "quaternion.hpp"

Vector3::Vector3() : Vector3(0, 0, 0) {}

Vector3::Vector3(float f) : Vector3(f, f, f) {}

Vector3::Vector3(float x, float y, float z) :
	x(x), y(y), z(z)
{}

Vector3::Vector3(const Vector3& v) :
	x(v.x), y(v.y), z(v.z)
{}

Vector3& Vector3::applyQuaternion(const Quaternion& q) {
	float ix = q.w * x + q.y * z - q.z * y;
	float iy = q.w * y + q.z * x - q.x * z;
	float iz = q.w * z + q.x * y - q.y * x;
	float iw = -q.x * x - q.y * y - q.z * z;

	x = ix * q.w + iw * -q.x + iy * -q.z - iz * -q.y;
	y = iy * q.w + iw * -q.y + iz * -q.x - ix * -q.z;
	z = iz * q.w + iw * -q.z + ix * -q.y - iy * -q.x;

	return *this;
}

Vector3 Vector3::operator+(const Vector3& v) const {
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v) const {
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(float s) const {
	return Vector3(x * s, y * s, z * s);
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