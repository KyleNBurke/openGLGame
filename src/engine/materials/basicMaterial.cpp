#include "basicMaterial.hpp"

bool BasicMaterial::initialized = false;
GLuint BasicMaterial::program = 0;
GLint BasicMaterial::transformLoc = 0;
GLint BasicMaterial::colorLoc = 0;

BasicMaterial::BasicMaterial(glm::vec3 color) : color(color) {
	if (!initialized) {
		init("basic", program, transformLoc);
		basicInit();
		initialized = true;
	}
}

void BasicMaterial::basicInit() {
	colorLoc = glGetUniformLocation(program, "color");
}

void BasicMaterial::sendData(const glm::mat4& trans) {
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
	glUniform3fv(colorLoc, 1, glm::value_ptr(color));
}

GLuint BasicMaterial::getProgram() const {
	return BasicMaterial::program;
}