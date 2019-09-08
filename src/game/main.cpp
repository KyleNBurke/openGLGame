#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "../engine/renderer.hpp"
#include "../engine/geometries/boxGeometry.hpp"
#include "../engine/mesh.hpp"
#include "../engine/materials/basicMaterial.hpp"
#include "../engine/materials/lambertMaterial.hpp"

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

	int gladStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	if (!gladStatus) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	glClearColor(0.3921f, 0.5843f, 0.9294f, 1.0f);

	Renderer renderer;
	Scene scene;
	Camera camera(800.0f / 600.0f);
	camera.transform = glm::translate(camera.transform, glm::vec3(1.0f, 0.0f, 2.0f));
	camera.transform = glm::rotate(camera.transform, 0.5f, glm::vec3(0.0f, 1.0f, 0.0f));
	camera.transform = glm::translate(camera.transform, glm::vec3(0.4f, 0.0f, 0.0f));

	BoxGeometry geoB;
	BasicMaterial matB;
	auto cubePtrB = std::make_unique<Mesh>(geoB, matB);
	Mesh& cubeB = *cubePtrB;
	scene.objects.push_back(std::move(cubePtrB));

	BoxGeometry geoL;
	LambertMaterial matL;
	auto cubePtrL = std::make_unique<Mesh>(geoL, matL);
	Mesh& cubeL = *cubePtrL;
	scene.objects.push_back(std::move(cubePtrL));

	cubeB.transform = glm::translate(cubeB.transform, glm::vec3(0.5f, 0.0f, -3.0f));

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		cubeB.transform = glm::rotate(cubeB.transform, (float)glfwGetTime() * 0.005f, glm::vec3(0.0f, 1.0f, 1.0f));
		renderer.render(window, scene, camera);
	}

	glfwTerminate();
    return 0;
}