#pragma once

#include "../core/mesh.hpp"
#include "../lights/pointLight.hpp"
#include "../geometries/boxGeometry.hpp"
#include "../materials/basicMaterial.hpp"

class PointLightHelper : public Mesh {
	public:
		PointLightHelper(const PointLight& pointLight);
		void updateMatrix() override;

		BoxGeometry boxGeometry;
		BasicMaterial basicMaterial;
		const PointLight& pointLight;
};