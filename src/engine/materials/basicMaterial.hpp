#pragma once

#include "material.hpp"
#include "glm/vec4.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "../math/matrix4.hpp"

class BasicMaterial : public Material {
	public:
		BasicMaterial(glm::vec3 color = glm::vec3());
		void basicInit();
		void sendData(const Matrix4& trans);
		GLuint getProgram() const;
		
	private:
		static bool initialized;
		static GLuint program;
		static GLint transformLoc;
		static GLint colorLoc;
		glm::vec3 color;
};