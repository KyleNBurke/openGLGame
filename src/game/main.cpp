#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "../engine/renderer.hpp"
#include "../engine/geometries/boxGeometry.hpp"
#include "../engine/materials/basicMaterial.hpp"
#include "../engine/mesh.hpp"

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

	BoxGeometry geo;
	BasicMaterial mat;
	Mesh cube(geo, mat);
	scene.objects.push_back(&cube);

	cube.transform = glm::translate(cube.transform, glm::vec3(0.5f, 0.0f, -3.0f));

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		cube.transform = glm::rotate(cube.transform, (float)glfwGetTime() * 0.005f, glm::vec3(0.0f, 1.0f, 1.0f));
		renderer.render(window, scene, camera);
	}

	glfwTerminate();
    return 0;
}