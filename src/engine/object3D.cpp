#include "object3D.hpp"

Object3D::Object3D() :
	autoUpdateMatrix(true),
	position(glm::vec3()),
	rotation(glm::quat()),
	scale(glm::vec3()),
	matrix(glm::mat4(1.0f))
{}

void Object3D::updateMatrix() {
	//matrix = a matrix composed of pos, rot & scale
}

void Object3D::setMatrix(glm::mat4 matrix) {
	this->matrix = matrix;
}

const glm::mat4& Object3D::getMatrix() const {
	return matrix;
}