#pragma once

#include <glad/glad.h>

class Geometry {
	public:
		Geometry();
		
		GLuint vbo;
		GLuint vao;
		int vertexCount;

	protected:
		void init(float vertices[], int verticesSize, int vertexCount);
};