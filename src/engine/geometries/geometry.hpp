#pragma once

#include <glad/glad.h>
#include <cstddef>

class Geometry {
	public:
		Geometry(const float vertices[], std::size_t verticesSize, std::size_t vertexCount);
		GLuint getVbo() const;
		GLuint getVao() const;
		int getVertexCount() const;

	private:
		GLuint vbo;
		GLuint vao;
		int vertexCount;
};