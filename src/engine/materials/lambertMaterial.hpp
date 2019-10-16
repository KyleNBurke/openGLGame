#pragma once

#include "material.hpp"
#include "glm/vec4.hpp"
#include <glm/gtc/type_ptr.hpp>

class LambertMaterial : public Material {
	public:
		LambertMaterial(glm::vec3 color = glm::vec3());
		void lambertInit();
		void sendData(const glm::mat4& trans, const glm::vec3& ambientLight);
		GLuint getProgram() const;
		
		glm::vec3 color;

	private:
		static bool initialized;
		static GLuint program;
		static GLint transformLoc;
		static GLint materialColorLoc;
		static GLint ambientLightLoc;
};