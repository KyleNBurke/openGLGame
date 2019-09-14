#pragma once

#include "material.hpp"
#include "glm/vec4.hpp"
#include <glm/gtc/type_ptr.hpp>

class LambertMaterial : public Material {
	public:
		LambertMaterial();
		void lambertInit();
		void sendData(const glm::mat4& trans);
		GLuint getProgram() const;
		
		glm::vec4 color;

	private:
		static bool initialized;
		static GLuint program;
		static GLint transformLoc;
};