#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "../engine/renderer.hpp"
#include "../engine/geometries/boxGeometry.hpp"
#include "../engine/mesh.hpp"
#include "../engine/materials/basicMaterial.hpp"
#include "../engine/materials/lambertMaterial.hpp"
#include "../engine/lights/pointLight.hpp"
#include "../engine/helpers/pointLightHelper.hpp"
#include "cameraControls.hpp"

#include <iostream>

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
	Camera camera(800.0f / 600.0f);

	double mousePosX;
	double mousePosY;
	glfwGetCursorPos(window, &mousePosX, &mousePosY);
	CameraControls cameraControls(mousePosX, mousePosY);

	BoxGeometry geoB;
	BasicMaterial matB(glm::vec3(1.0f, 0.0f, 0.0f));
	auto cubePtrB = std::make_unique<Mesh>(geoB, matB);
	Mesh& cubeB = *cubePtrB;
	scene.objects.push_back(std::move(cubePtrB));

	BoxGeometry geoL;
	LambertMaterial matL;
	auto cubePtrL = std::make_unique<Mesh>(geoL, matL);
	Mesh& cubeL = *cubePtrL;
	scene.objects.push_back(std::move(cubePtrL));

	PointLight pointLight;
	pointLight.transform = glm::translate(pointLight.transform, glm::vec3(1.0f, 1.0f, -2.0f));

	auto pointLightHelper = std::make_unique<PointLightHelper>(pointLight);
	scene.objects.push_back(std::move(pointLightHelper));

	cubeB.transform = glm::translate(cubeB.transform, glm::vec3(0.5f, 0.0f, -3.0f));

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, 1);

		cameraControls.update(window, camera);

		cubeB.transform = glm::rotate(cubeB.transform, 0.01f, glm::vec3(0.0f, 1.0f, 1.0f));
		cubeL.transform = glm::rotate(cubeL.transform, 0.005f, glm::vec3(0.0, 1.0f, 0.0f));

		renderer.render(window, scene, camera);
	}

	glfwTerminate();
	return 0;
}