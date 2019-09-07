#include "mesh.hpp"
#include <glm/gtc/type_ptr.hpp>

Mesh::Mesh(Geometry& geometry, Material& material) :
	geometry(geometry),
	material(material) {}

void Mesh::render(glm::mat4& proj) {
	glUseProgram(material.getShader().program);

	//compose model matrix
	//...

	//pass matrix to shader
	glUniformMatrix4fv(material.getShader().transformLoc, 1, GL_FALSE, glm::value_ptr(proj * transform));

	glBindVertexArray(geometry.getVao());
	glDrawArrays(GL_TRIANGLES, 0, geometry.getVertexCount());
}