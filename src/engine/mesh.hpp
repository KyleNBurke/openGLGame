#pragma once

#include "object3D.hpp"
#include "geometries/geometry.hpp"
#include "materials/material.hpp"

class Mesh : public Object3D {
	public:
		Mesh(Geometry& geometry, Material& material);
		void render(const glm::mat4& view, const glm::mat4& proj, const glm::vec3& ambientLight);

		Geometry& geometry;
		Material& material;
};