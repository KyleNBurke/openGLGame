#pragma once

#include "material.hpp"
#include "glm/vec4.hpp"

class BasicMaterial : public Material {
	public:
		BasicMaterial();
		GLuint getProgram() const;
		GLint getTransformLoc() const;
		
		glm::vec4 color;

	private:
		static bool initialized;
		static GLuint program;
		static GLint transformLoc;
};