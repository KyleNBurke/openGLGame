#include "geometry.hpp"

Geometry::Geometry(const float vertices[], std::size_t verticesSize, std::size_t vertexCount) {
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	this->vertexCount = vertexCount;
}

GLuint Geometry::getVbo() const {
	return vbo;
}

GLuint Geometry::getVao() const {
	return vao;
}

int Geometry::getVertexCount() const {
	return vertexCount;
}