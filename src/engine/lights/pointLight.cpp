#include "pointLight.hpp"
#include <glm/gtc/type_ptr.hpp>

bool PointLight::initialized = false;
GLuint PointLight::block = 0;
GLuint PointLight::bindingPoint = 1;

PointLight::PointLight(glm::vec3 color) :
	color(color)
{
	if (!initialized) {
		init();
		initialized = true;
	}

	update();
}

void PointLight::init() {
	glGenBuffers(1, &block);
	glBindBuffer(GL_UNIFORM_BUFFER, block);
	glBufferData(GL_UNIFORM_BUFFER, 32, NULL, GL_STATIC_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, bindingPoint, block);

	/*glm::vec4 data1(0.0f, 1.0f, 1.0f, 0.0f);
	glm::vec4 data2(0.0f, 0.0f, 1.0f, 0.0f);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, 16, glm::value_ptr(data1));
	glBufferSubData(GL_UNIFORM_BUFFER, 16, 16, glm::value_ptr(data2));*/
}

void PointLight::update() {
	glBufferSubData(GL_UNIFORM_BUFFER, 0, 16, glm::value_ptr(glm::vec3(1.0f, 1.0f, -2.0f)));
	glBufferSubData(GL_UNIFORM_BUFFER, 16, 16, glm::value_ptr(color));
}

GLuint PointLight::getBlock() {
	return block;
}