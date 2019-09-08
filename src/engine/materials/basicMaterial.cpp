#include "basicMaterial.hpp"

bool BasicMaterial::initialized = false;
GLuint BasicMaterial::program = 0;
GLint BasicMaterial::transformLoc = 0;

BasicMaterial::BasicMaterial() :
	color(glm::vec4())
{
	if (!initialized) {
		init("basic", program, transformLoc);
		initialized = true;
	}
}

GLuint BasicMaterial::getProgram() const {
	return BasicMaterial::program;
}

GLint BasicMaterial::getTransformLoc() const {
	return BasicMaterial::transformLoc;
}