#include "pointLightHelper.hpp"

PointLightHelper::PointLightHelper(const PointLight& pointLight) :
	pointLight(pointLight),
	boxGeometry(), //need?
	basicMaterial(), //need?
	Mesh(boxGeometry, basicMaterial)
{}

void PointLightHelper::updateMatrix() {
	matrix = pointLight.getMatrix();
}