#include "renderer.hpp"
#include <iostream>
#include "mesh.hpp"

Renderer::Renderer() {}

void Renderer::render(GLFWwindow* window, Scene& scene, Camera& camera) {
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto& it : scene.objects) {
		Mesh* meshObj = dynamic_cast<Mesh*>(it.get());
		if (meshObj != nullptr) {
			meshObj->render(camera.transform, camera.proj);
		}
	}

	glfwSwapBuffers(window);
}