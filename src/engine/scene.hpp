#pragma once

#include <vector>
#include <memory>
#include "object3D.hpp"

class Scene {
	public:
		Scene(glm::vec3 ambientLight = glm::vec3());

		std::vector<std::unique_ptr<Object3D>> objects;
		glm::vec3 ambientLight;
};