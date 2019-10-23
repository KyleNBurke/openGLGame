#include "cameraControls.hpp"

CameraControls::CameraControls(double mousePosX, double mousePosY) :
	up(glm::vec3(0.0f, 1.0f, 0.0f)),
	//front should probably be initialized by multipying the below vector by the camera's transformation/model matrix
	forward(glm::vec3(0.0f, 0.0f, -1.0f)),
	movementSpeed(0.05f),
	mouseSensitivity(0.1f),
	yaw(-90.0f),
	pitch(0.0f),
	lastMousePosX(mousePosX),
	lastMousePosY(mousePosY)
{}

void CameraControls::update(GLFWwindow* window, Camera& camera) {
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.position += forward * movementSpeed;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.position -= forward * movementSpeed;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.position -= glm::normalize(glm::cross(forward, up)) * movementSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.position += glm::normalize(glm::cross(forward, up)) * movementSpeed;
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		camera.position -= up * movementSpeed;
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		camera.position += up * movementSpeed;
	
	//this rotation code can be more elegant when I start constructing the transform matrix from
	//the pos, rot & scale because then I can actually utalize camera.rotation
	double currMousePosX;
	double currMousePosY;
	glfwGetCursorPos(window, &currMousePosX, &currMousePosY);

	yaw += (currMousePosX - lastMousePosX) * mouseSensitivity;
	pitch += -(currMousePosY - lastMousePosY) * mouseSensitivity;

	lastMousePosX = currMousePosX;
	lastMousePosY = currMousePosY;

	if (pitch > 90.0f)
		pitch = 90.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;
	
	forward.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	forward.y = sin(glm::radians(pitch));
	forward.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	forward = glm::normalize(forward);
	glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));
	up = glm::normalize(glm::cross(right, forward));
	
	camera.setMatrix(glm::lookAt(camera.position, camera.position + forward, up));
}