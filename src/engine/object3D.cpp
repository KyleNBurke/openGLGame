#include "object3D.hpp"

Object3D::Object3D() :
	position(glm::vec3()),
	rotation(glm::quat()),
	scale(glm::vec3()),
	transform(glm::mat4(1.0f))
	{}