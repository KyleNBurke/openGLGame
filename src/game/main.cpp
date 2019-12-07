#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

#include "../engine/renderer.hpp"
#include "../engine/scene.hpp"
#include "../engine/camera.hpp"
#include "../engine/geometries/boxGeometry.hpp"
#include "../engine/materials/basicMaterial.hpp"
#include "../engine/materials/lambertMaterial.hpp"

#include "cameraControls.hpp"

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	int gladStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	if (!gladStatus) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	glClearColor(0.3921f, 0.5843f, 0.9294f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	Renderer renderer;
	Scene scene;
	Camera camera(800.0f / 600.0f, 75, 0.1, 1000);

	double mousePosX;
	double mousePosY;
	glfwGetCursorPos(window, &mousePosX, &mousePosY);
	CameraControls cameraControls(mousePosX, mousePosY);

	BoxGeometry geoB;
	BasicMaterial matB;
	auto cubePtrB = std::make_unique<Mesh>(geoB, matB);
	Mesh& cubeB = *cubePtrB;
	scene.meshes.push_back(std::move(cubePtrB));

	BoxGeometry geoB2;
	LambertMaterial matB2;
	auto cubePtrB2 = std::make_unique<Mesh>(geoB2, matB2);
	Mesh& cubeB2 = *cubePtrB2;
	scene.meshes.push_back(std::move(cubePtrB2));
	cubeB2.translateX(1.5);
	cubeB2.translateZ(-3.0f);

	auto pointLightPtr = std::make_unique<PointLight>();
	pointLightPtr->translateY(3.0f);
	PointLight& pointLight = *pointLightPtr;
	scene.addPointLight(std::move(pointLightPtr));

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, 1);
		
		cameraControls.update(window, camera);

		cubeB2.rotateY(0.1f);

		renderer.render(window, scene, camera);
	}

	glfwTerminate();
	return 0;
}