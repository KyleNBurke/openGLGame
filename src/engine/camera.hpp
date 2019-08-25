#pragma once

#include <glm/glm.hpp>

class Camera {
	public:
		Camera(float aspectRatio);
		glm::mat4 proj;
};