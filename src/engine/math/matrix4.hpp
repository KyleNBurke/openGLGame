#pragma once

#include "vector3.hpp"
#include "quaternion.hpp"

class Matrix4 {
	public:
		Matrix4();
		Matrix4(const Matrix4& m);

		Matrix4& identity();
		Matrix4& compose(const Vector3& position, const Quaternion& quaternion, const Vector3& scale);
		Matrix4& transpose();
		Matrix4 operator*(const Matrix4& b) const;
		Matrix4& operator*=(float s);

		void set(float n11, float n12, float n13, float n14,
				 float n21, float n22, float n23, float n24,
				 float n31, float n32, float n33, float n34,
				 float n41, float n42, float n43, float n44);
		
		const float* getElements() const;

	private:
		float elements[16];
};