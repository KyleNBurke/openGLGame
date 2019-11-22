#pragma once

#include "object3D.hpp"

class Camera : public Object3D {
	public:
		Camera(float aspect, float fov, float near, float far);
		void updateProjectionMatrix();

		float aspect;
		float fov;
		float nearDist;
		float farDist;
		Matrix4 proj;
};