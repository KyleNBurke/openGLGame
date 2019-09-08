#include "lambertMaterial.hpp"

bool LambertMaterial::initialized = false;
GLuint LambertMaterial::program = 0;
GLint LambertMaterial::transformLoc = 0;

LambertMaterial::LambertMaterial() :
	color(glm::vec4())
{
	if (!initialized) {
		init("lambert", program, transformLoc);
		initialized = true;
	}
}

GLuint LambertMaterial::getProgram() const {
	return LambertMaterial::program;
}

GLint LambertMaterial::getTransformLoc() const {
	return LambertMaterial::transformLoc;
}