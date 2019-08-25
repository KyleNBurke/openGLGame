#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "scene.hpp"
#include "camera.hpp"

class Renderer {
	public:
		Renderer();
		void render(GLFWwindow* window, Scene scene, Camera camera); //prob just need refs
};