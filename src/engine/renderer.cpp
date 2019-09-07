#include "renderer.hpp"
#include <iostream>
#include "mesh.hpp"

Renderer::Renderer() {
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	if (!status) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return;
	}

	glClearColor(0.3921f, 0.5843f, 0.9294f, 1.0f);
}

void Renderer::render(GLFWwindow* window, Scene& scene, Camera& camera) {
	glClear(GL_COLOR_BUFFER_BIT);

	std::vector<Object3D*>& objects = scene.objects;
	for (std::vector<Object3D*>::iterator it = objects.begin(); it != objects.end(); ++it) {
		Object3D* obj = *it;

		Mesh* meshObj = dynamic_cast<Mesh*>(obj);
		if (meshObj != nullptr) {
			meshObj->render(camera.proj);
		}
	}

	glfwSwapBuffers(window);
}