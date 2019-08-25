#include "camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float aspectRatio) :
	proj(glm::perspective(glm::pi<float>() / 4.0f, aspectRatio, 0.1f, 100.0f)) {}