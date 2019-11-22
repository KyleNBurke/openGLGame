#include "camera.hpp"
#include <cmath>

Camera::Camera(float aspect, float fov, float near, float far) :
	aspect(aspect),
	fov(fov),
	nearDist(near),
	farDist(far)
{
	updateProjectionMatrix();
}

void Camera::updateProjectionMatrix() {
	float top = nearDist * tan(3.1415f / 180.0f * 0.5 * fov);
	float height = 2 * top;
	float width = aspect * height;
	float left = -0.5 * width;
	proj.makePerspective(left, left + width, top, top - height, nearDist, farDist);
}