#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

#include "../engine/renderer.hpp"
#include "../engine/scene.hpp"
#include "../engine/camera.hpp"
#include "../engine/geometries/boxGeometry.hpp"
#include "../engine/materials/basicMaterial.hpp"

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
	Camera camera(800 / 600, 0.1, 100, 50);

	BoxGeometry geoB;
	BasicMaterial matB;
	auto cubePtrB = std::make_unique<Mesh>(geoB, matB);
	Mesh& cubeB = *cubePtrB;
	scene.meshes.push_back(std::move(cubePtrB));

	Matrix4 m;
	m.set(1, 0, 0, 0,
		  0, 1, 0, 0,
		  0, 0, 1, 0,
		  0, 0, 0, 1);
	cubeB.setMatrix(m);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, 1);

		renderer.render(window, scene, camera);
	}

	glfwTerminate();
	return 0;
}