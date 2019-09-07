#pragma once

#include "material.hpp"
#include "glm/vec4.hpp"
#include "../shaders/shader.hpp"

class BasicMaterial : public Material {
	public:
		BasicMaterial();
		Shader& getShader();
		static Shader shader;
		glm::vec4 color;
		GLint transformLoc; //should not be able to be set outside this class
};