#pragma once

#include <glfw/glfw3.h>
#include "../engine/core/camera.hpp"

class CameraControls {
	public:
		CameraControls(double mousePosX, double mousePosY);
		void update(GLFWwindow* window, Camera& camera);

		float translationSpeed;
		float rotationSpeed;

	private:
		double lastMousePosX;
		double lastMousePosY;
};