#pragma once

#include "../mesh.hpp"
#include "../lights/pointLight.hpp"
#include "../geometries/boxGeometry.hpp"
#include "../materials/basicMaterial.hpp"

class PointLightHelper : public Mesh {
	public:
		PointLightHelper(const PointLight& pointLight);

		BoxGeometry boxGeometry;
		BasicMaterial basicMaterial;
		const PointLight& pointLight;
};