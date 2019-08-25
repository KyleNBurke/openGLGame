#pragma once
#include <vector>
#include "object3D.hpp"

class Scene {
	public:
		Scene();
		std::vector<Object3D*> objects;
};