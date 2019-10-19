#pragma once

#include <glfw/glfw3.h>
#include "../engine/camera.hpp"

class CameraControls {
	public:
		CameraControls(double mousePosX, double mousePosY);
		void update(GLFWwindow* window, Camera& camera);

		float movementSpeed;
		float mouseSensitivity;

	private:
		glm::vec3 up;
		glm::vec3 forward;
		float yaw;
		float pitch;
		double lastMousePosX;
		double lastMousePosY;
};