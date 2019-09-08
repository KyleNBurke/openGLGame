#pragma once

#include "light.hpp"

class AmbientLight : public Light {
	public:
		AmbientLight(glm::vec3 color, float intensity);
};