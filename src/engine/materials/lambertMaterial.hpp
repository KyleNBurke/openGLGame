#pragma once

#include "material.hpp"
#include "glm/vec4.hpp"

class LambertMaterial : public Material {
	public:
		LambertMaterial();
		GLuint getProgram() const;
		GLint getTransformLoc() const;
		
		glm::vec4 color;

	private:
		static bool initialized;
		static GLuint program;
		static GLint transformLoc;
};