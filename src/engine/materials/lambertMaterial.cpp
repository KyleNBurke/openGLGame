#include "lambertMaterial.hpp"

bool LambertMaterial::initialized = false;
GLuint LambertMaterial::program = 0;
GLint LambertMaterial::transformLoc = 0;

LambertMaterial::LambertMaterial() :
	color(glm::vec4())
{
	if (!initialized) {
		init("lambert", program, transformLoc);
		lambertInit();
		initialized = true;
	}
}

void LambertMaterial::lambertInit() {

}

void LambertMaterial::sendData(const glm::mat4& trans) {
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

GLuint LambertMaterial::getProgram() const {
	return LambertMaterial::program;
}