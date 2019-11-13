#include "camera.hpp"
#include <cmath>

Camera::Camera(float aspect, float near, float far, float fov) :
	aspect(aspect),
	nearPlane(nearPlane),
	farPlane(farPlane),
	fov(fov)
{
	//updateProjectionMatrix();
}

void Camera::updateProjectionMatrix() {
	float top = nearPlane * tan(3.14 / 180 * 0.5 * fov);
	float height = 2 * top;
	float width = aspect * height;
	float left = -0.5 * width;

	proj.makePerspective(left, left + width, top, top - height, nearPlane, farPlane);
}