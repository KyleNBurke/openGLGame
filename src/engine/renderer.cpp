#include "renderer.hpp"
#include <iostream>
#include "mesh.hpp"

Renderer::Renderer() {}

void Renderer::render(GLFWwindow* window, Scene& scene, Camera& camera) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int i = 0;
	for (const std::unique_ptr<PointLight>& pointLight : scene.getPointLights()) {
		pointLight->update(i);
		i++;
	}

	PointLight::updateLightCount(i);

	for (std::unique_ptr<Mesh>& mesh : scene.meshes) {
		mesh->render(camera.transform, camera.proj, scene.ambientLight);
	}

	glfwSwapBuffers(window);
}