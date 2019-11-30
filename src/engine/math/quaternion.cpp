#include "quaternion.hpp"
#include "vector3.hpp"
#include "euler.hpp"
#include <cmath>

Quaternion::Quaternion() : Quaternion(0, 0, 0, 1) {}

Quaternion::Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Quaternion::Quaternion(const Quaternion& q) : Quaternion(q.x, q.y, q.z, q.w) {}

Quaternion::Quaternion(const Vector3& axis, float angle) {
	float halfAngle = angle / 2.0f;
	float s = sin(halfAngle);

	x = axis.x * s;
	y = axis.y * s;
	z = axis.z * s;
	w = cos(halfAngle);
}

Quaternion::Quaternion(const Euler& e) {
	float c1 = cosf(e.x / 2.0f);
	float c2 = cosf(e.y / 2.0f);
	float c3 = cosf(e.z / 2.0f);

	float s1 = sinf(e.x / 2.0f);
	float s2 = sinf(e.y / 2.0f);
	float s3 = sinf(e.z / 2.0f);

	switch (e.order) {
		case Euler::Order::xyz:
			x = s1 * c2 * c3 + c1 * s2 * s3;
			y = c1 * s2 * c3 - s1 * c2 * s3;
			z = c1 * c2 * s3 + s1 * s2 * c3;
			w = c1 * c2 * c3 - s1 * s2 * s3;
			break;
		case Euler::Order::xzy:
			x = s1 * c2 * c3 - c1 * s2 * s3;
			y = c1 * s2 * c3 - s1 * c2 * s3;
			z = c1 * c2 * s3 + s1 * s2 * c3;
			w = c1 * c2 * c3 + s1 * s2 * s3;
			break;
		case Euler::Order::yxz:
			x = s1 * c2 * c3 + c1 * s2 * s3;
			y = c1 * s2 * c3 - s1 * c2 * s3;
			z = c1 * c2 * s3 - s1 * s2 * c3;
			w = c1 * c2 * c3 + s1 * s2 * s3;
			break;
		case Euler::Order::yzx:
			x = s1 * c2 * c3 + c1 * s2 * s3;
			y = c1 * s2 * c3 + s1 * c2 * s3;
			z = c1 * c2 * s3 - s1 * s2 * c3;
			w = c1 * c2 * c3 - s1 * s2 * s3;
			break;
		case Euler::Order::zxy:
			x = s1 * c2 * c3 - c1 * s2 * s3;
			y = c1 * s2 * c3 + s1 * c2 * s3;
			z = c1 * c2 * s3 + s1 * s2 * c3;
			w = c1 * c2 * c3 - s1 * s2 * s3;
			break;
		case Euler::Order::zyx:
			x = s1 * c2 * c3 - c1 * s2 * s3;
			y = c1 * s2 * c3 + s1 * c2 * s3;
			z = c1 * c2 * s3 - s1 * s2 * c3;
			w = c1 * c2 * c3 + s1 * s2 * s3;
			break;
	}
}

Quaternion& Quaternion::operator*=(const Quaternion& q) {
	const Quaternion& a(*this);
	const Quaternion& b = q;

	x = a.x * b.w + a.w * b.x + a.y * b.z - a.z * b.y;
	y = a.y * b.w + a.w * b.y + a.z * b.x - a.x * b.z;
	z = a.z * b.w + a.w * b.z + a.x * b.y - a.y * b.x;
	w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	
	return *this;
}