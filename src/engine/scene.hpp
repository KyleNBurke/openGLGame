#pragma once

#include <vector>
#include <memory>
#include "object3D.hpp"
#include "mesh.hpp"
#include "lights/pointLight.hpp"

class Scene {
	public:
		Scene(glm::vec3 ambientLight = glm::vec3());
		const std::vector<std::unique_ptr<PointLight>>& getPointLights() const;
		void addPointLight(std::unique_ptr<PointLight> pointLight);
		
		std::vector<std::unique_ptr<Mesh>> meshes;
		glm::vec3 ambientLight;

	private:
		std::vector<std::unique_ptr<PointLight>> pointLights;
};