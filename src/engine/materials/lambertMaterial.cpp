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
	GLuint pointLightBlock;
	glGenBuffers(1, &pointLightBlock);
	glBindBuffer(GL_UNIFORM_BUFFER, pointLightBlock);
	glBufferData(GL_UNIFORM_BUFFER, 16, NULL, GL_STATIC_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, 1, pointLightBlock);

	/*glm::vec4 data[2];
	data[0] = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
	data[1] = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
	int i = sizeof(data);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, 16, glm::value_ptr(data[0]));
	glBufferSubData(GL_UNIFORM_BUFFER, 16, 32, glm::value_ptr(data[1]));*/
	glm::vec4 data(0.0f, 0.0f, 1.0f, 1.0f);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, 16, glm::value_ptr(data));
}

void LambertMaterial::sendData(const glm::mat4& trans) {
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

GLuint LambertMaterial::getProgram() const {
	return LambertMaterial::program;
}