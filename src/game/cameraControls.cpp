#include "cameraControls.hpp"
#include "../engine/math/euler.hpp"

#include <iostream>

CameraControls::CameraControls(double mousePosX, double mousePosY) :
    lastMousePosX(mousePosX),
    lastMousePosY(mousePosY),
	translationSpeed(0.05f),
	rotationSpeed(0.001f)
{}

void CameraControls::update(GLFWwindow* window, Camera& camera) {
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.translateZ(-translationSpeed);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.translateZ(translationSpeed);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.translateX(-translationSpeed);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.translateX(translationSpeed);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		camera.translateY(-translationSpeed);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		camera.translateY(translationSpeed);
	
	double currMousePosX;
	double currMousePosY;
	glfwGetCursorPos(window, &currMousePosX, &currMousePosY);

	//do this: https://github.com/mrdoob/three.js/blob/master/examples/js/controls/PointerLockControls.js
    //camera.rotateY((lastMousePosX - currMousePosX) * rotationSpeed);
    //camera.rotateX((lastMousePosY - currMousePosY) * rotationSpeed);
	Euler e(camera.quaternion, Euler::Order::yxz);
	e.y += (lastMousePosX - currMousePosX) * rotationSpeed;
	e.x += (lastMousePosY - currMousePosY) * rotationSpeed;
	camera.quaternion = Quaternion(e);

	lastMousePosX = currMousePosX;
	lastMousePosY = currMousePosY;
}