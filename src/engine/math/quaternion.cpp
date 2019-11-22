#include "quaternion.hpp"
#include "vector3.hpp"
#include <cmath>

Quaternion::Quaternion() : Quaternion(0, 0, 0, 1) {}

Quaternion::Quaternion(float x, float y, float z, float w) :
	x(x), y(y), z(z), w(w)
{}

Quaternion::Quaternion(const Quaternion& q) : Quaternion(q.x, q.y, q.z, q.w) {}

Quaternion::Quaternion(const Vector3& axis, float angle) {
	float halfAngle = angle / 2.0f;
	float s = sin(halfAngle);

	x = axis.x * s;
	y = axis.y * s;
	z = axis.z * s;
	w = cos(halfAngle);
}

Quaternion& Quaternion::operator*=(const Quaternion& q) {
	const Quaternion a(*this);
	const Quaternion& b = q;

	x = a.x * b.w + a.w * b.x + a.y * b.z - a.z * b.y;
	y = a.y * b.w + a.w * b.y + a.z * b.x - a.x * b.z;
	z = a.z * b.w + a.w * b.z + a.x * b.y - a.y * b.x;
	w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	
	return *this;
}