#pragma once
#include "object3D.hpp"
#include "geometries/geometry.hpp"
#include "materials/material.hpp"

class Mesh : public Object3D {
	public:
		Mesh(Geometry& geometry, Material& material);
		void render(glm::mat4& proj);

		Geometry& geometry;
		Material& material;
};