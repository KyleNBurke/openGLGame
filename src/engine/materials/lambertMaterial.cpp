#include "lambertMaterial.hpp"

bool LambertMaterial::initialized = false;
GLuint LambertMaterial::program = 0;
GLint LambertMaterial::transformLoc = 0;
GLint LambertMaterial::materialColorLoc = 0;
GLint LambertMaterial::ambientLightLoc = 0;

LambertMaterial::LambertMaterial(glm::vec3 color) :
	color(color)
{
	if (!initialized) {
		init("lambert", program, transformLoc);
		lambertInit();
		initialized = true;
	}
}

void LambertMaterial::lambertInit() {
	materialColorLoc = glGetUniformLocation(program, "materialColor");
	ambientLightLoc = glGetUniformLocation(program, "ambientLight");
}

void LambertMaterial::sendData(const glm::mat4& trans, const glm::vec3& ambientLight) {
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
	glUniform3fv(materialColorLoc, 1, glm::value_ptr(color));
	glUniform3fv(ambientLightLoc, 1, glm::value_ptr(ambientLight));
}

GLuint LambertMaterial::getProgram() const {
	return LambertMaterial::program;
}