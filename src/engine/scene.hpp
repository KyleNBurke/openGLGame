#pragma once

#include <vector>
#include <memory>
#include "mesh.hpp"
#include "lights/pointLight.hpp"

class Scene {
	public:
		Scene();
		Scene(Vector3 ambientLight);
		const std::vector<std::unique_ptr<PointLight>>& getPointLights() const;
		void addPointLight(std::unique_ptr<PointLight> pointLight);
		
		std::vector<std::unique_ptr<Mesh>> meshes;
		Vector3 ambientLight;

	private:
		std::vector<std::unique_ptr<PointLight>> pointLights;
};