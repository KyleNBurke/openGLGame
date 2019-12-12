#pragma once

#include "geometry.hpp"

class BoxGeometry : public Geometry {
	public:
		BoxGeometry();

	private:
		const static float vertices[];
};