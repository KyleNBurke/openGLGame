#include "quaternion.hpp"

Quaternion::Quaternion() :
	x(0), y(0), z(0), w(0)
{}

Quaternion::Quaternion(float x, float y, float z, float w) :
	x(x), y(y), z(z), w(w)
{}

Quaternion::Quaternion(const Quaternion& q) :
	x(q.x), y(q.y), z(q.z), w(q.w)
{}