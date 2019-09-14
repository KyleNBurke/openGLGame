#pragma once

#include <vector>
#include <memory>
#include "object3D.hpp"

class Scene {
	public:
		Scene();
		std::vector<std::unique_ptr<Object3D>> objects;
};