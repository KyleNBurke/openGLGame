#include "pointLight.hpp"
#include <glm/gtc/type_ptr.hpp>

bool PointLight::initialized = false;
const int PointLight::maxCount = 10;
GLuint PointLight::block = 0;
GLuint PointLight::bindingPoint = 1;

PointLight::PointLight(glm::vec3 color) :
	color(color)
{
	if (!initialized) {
		init();
		initialized = true;
	}
}

void PointLight::init() {
	glGenBuffers(1, &block);
	glBindBuffer(GL_UNIFORM_BUFFER, block);
	glBufferData(GL_UNIFORM_BUFFER, 32 * maxCount + 4, NULL, GL_STATIC_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, bindingPoint, block);
}

void PointLight::update(int offset) {
	glm::vec3 pos = offset == 0 ? glm::vec3(1.0f, 1.0f, -2.0f) : glm::vec3(-1.0f, 1.0f, 2.0f);
	glBufferSubData(GL_UNIFORM_BUFFER, offset * 32, 16, glm::value_ptr(pos)); //vec should be pos, but it's not being used right now
	glBufferSubData(GL_UNIFORM_BUFFER, offset * 32 + 16, 16, glm::value_ptr(color));
}

void PointLight::updateLightCount(int count) {
	glBufferSubData(GL_UNIFORM_BUFFER, maxCount * 32, 4, &count);
}

GLuint PointLight::getBlock() {
	return block;
}