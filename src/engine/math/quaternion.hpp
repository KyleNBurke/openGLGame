#pragma once

class Vector3;
class Euler;

class Quaternion {
	public:
		Quaternion();
		Quaternion(float x, float y, float z, float w);
		Quaternion(const Quaternion& q);
		Quaternion(const Vector3& axis, float angle);
		Quaternion(const Euler& e);

		Quaternion& operator*=(const Quaternion& q);

		float x;
		float y;
		float z;
		float w;
};