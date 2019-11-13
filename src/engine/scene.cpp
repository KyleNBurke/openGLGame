#include "scene.hpp"
#include <iostream>

Scene::Scene() {}

Scene::Scene(Vector3 ambientLight) :
	ambientLight(ambientLight)
{}

const std::vector<std::unique_ptr<PointLight>>& Scene::getPointLights() const {
	return pointLights;
}

void Scene::addPointLight(std::unique_ptr<PointLight> pointLight) {
	if (pointLights.size() == PointLight::maxCount) {
		std::cout << "Cannot add point light to scene, max count is 10" << std::endl;
		return;
	}

	pointLights.push_back(std::move(pointLight));
}