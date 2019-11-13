#pragma once

#include "object3D.hpp"

class Camera : public Object3D {
	public:
		Camera(float aspect, float near, float far, float fov);
		void updateProjectionMatrix();

		float aspect;
		float nearPlane;
		float farPlane;
		float fov;
		Matrix4 proj;
};