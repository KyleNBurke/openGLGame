#pragma once

class Quaternion;

class Vector3 {
	public:
		Vector3();
		Vector3(float x, float y, float z);
		Vector3(const Vector3& v);

		Vector3& applyQuaternion(const Quaternion& q);

		Vector3 operator+(const Vector3& v) const;
		Vector3 operator-(const Vector3& v) const;
		Vector3 operator*(float s) const;
		Vector3& operator+=(const Vector3& v);
		Vector3& operator-=(const Vector3& v);
		Vector3& operator+=(float s);
		Vector3& operator-=(float s);

		float x;
		float y;
		float z;
};