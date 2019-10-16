#pragma once

#include "../object3D.hpp"
#include <glm/glm.hpp>
#include <glad/glad.h>

class PointLight : public Object3D {
	public:
		PointLight(glm::vec3 color = glm::vec3(1.0f));
		void update();
		GLuint getBlock();
		glm::vec3 color;

	private:
		void init();
		static bool initialized;
		static GLuint block;
		static GLuint bindingPoint;
};