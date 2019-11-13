#pragma once

#include "math/vector3.hpp"
#include "math/quaternion.hpp"
#include "math/matrix4.hpp"

class Object3D {
	public:
		Object3D();
		virtual ~Object3D() {};

		virtual void updateMatrix();
		void setMatrix(Matrix4 matrix);
		const Matrix4& getMatrix() const;
		void translateOnAxis(const Vector3& axis, float distance);
		void translateX(float distance);
		void translateY(float distance);
		void translateZ(float distance);

		bool autoUpdateMatrix;
		Vector3 position;
		Quaternion quaternion;
		Vector3 scale;
	
	protected:
		Matrix4 matrix;
};