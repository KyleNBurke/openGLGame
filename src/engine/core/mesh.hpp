#pragma once

#include "object3D.hpp"
#include "../geometries/geometry.hpp"
#include "../materials/material.hpp"

class Mesh : public Object3D {
	public:
		Mesh(Geometry& geometry, Material& material);
		void render(const Matrix4& view, const Matrix4& proj, const Vector3& ambientLight);

		Geometry& geometry;
		Material& material;
};