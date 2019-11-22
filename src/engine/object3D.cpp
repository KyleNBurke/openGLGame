#include "object3D.hpp"

#include <iostream>

Object3D::Object3D() :
	autoUpdateMatrix(true),
	scale(1, 1, 1)
	//position(glm::vec3()),
	//rotation(glm::quat()),
	//scale(glm::vec3()),
	//matrix(glm::mat4(1.0f))
{}

void Object3D::updateMatrix() {
	matrix.compose(position, quaternion, scale);
}

void Object3D::setMatrix(Matrix4 matrix) {
	this->matrix = matrix;
}

const Matrix4& Object3D::getMatrix() const {
	return matrix;
}

void Object3D::translateOnAxis(const Vector3& axis, float distance) {
	Vector3 axisObjectSpace = Vector3(axis).applyQuaternion(quaternion);
	position += axisObjectSpace * distance;
}

void Object3D::translateX(float distance) {
	translateOnAxis(Vector3(1, 0, 0), distance);
}

void Object3D::translateY(float distance) {
	translateOnAxis(Vector3(0, 1, 0), distance);
}

void Object3D::translateZ(float distance) {
	translateOnAxis(Vector3(0, 0, 1), distance);
}

void Object3D::rotateOnAxis(const Vector3& axis, float angle) {
	Quaternion axisObjectSpace(axis, angle);
	quaternion *= axisObjectSpace;
}

void Object3D::rotateX(float angle) {
	rotateOnAxis(Vector3(1, 0, 0), angle);
}

void Object3D::rotateY(float angle) {
	rotateOnAxis(Vector3(0, 1, 0), angle);
}

void Object3D::rotateZ(float angle) {
	rotateOnAxis(Vector3(0, 0, 1), angle);
}
