#pragma once

#include <glm/glm.hpp>

class Light {
	public:
		Light(glm::vec3 color, float intensity);
		glm::vec3 color;
		float intensity;
};