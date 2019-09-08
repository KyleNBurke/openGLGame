#pragma once

#include <glm/glm.hpp>
#include "object3D.hpp"

class Camera : public Object3D {
	public:
		Camera(float aspectRatio);
		glm::mat4 proj;
};