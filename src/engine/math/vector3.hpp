#pragma once

class Vector3 {
	public:
		Vector3();
		Vector3(float x, float y, float z);
		Vector3(const Vector3& v);

		Vector3 operator+(const Vector3& v);
		Vector3& operator+=(const Vector3& v);
		Vector3& operator+=(float s);

		float x;
		float y;
		float z;
};