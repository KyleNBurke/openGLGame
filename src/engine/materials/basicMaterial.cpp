#include "basicMaterial.hpp"

Shader BasicMaterial::shader = Shader();

BasicMaterial::BasicMaterial() :
	color(glm::vec4())
{
	if(!shaderInitialized) {
		shaderInitialized = true;
		shader.init("basic");
	}
}

Shader& BasicMaterial::getShader() {
	return BasicMaterial::shader;
}