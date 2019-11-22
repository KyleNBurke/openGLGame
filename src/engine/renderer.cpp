#include "renderer.hpp"
#include "mesh.hpp"
#include "math/matrix4.hpp"

Renderer::Renderer() {}

void Renderer::render(GLFWwindow* window, Scene& scene, Camera& camera) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int i = 0;
	for (const std::unique_ptr<PointLight>& pointLight : scene.getPointLights()) {
		pointLight->update(i);
		i++;
	}

	PointLight::updateLightCount(i);

	camera.updateMatrix();

	for (std::unique_ptr<Mesh>& mesh : scene.meshes) {
		Matrix4 view = Matrix4(camera.getMatrix()).invert();
		mesh->render(view, camera.proj, scene.ambientLight);
	}

	glfwSwapBuffers(window);
}