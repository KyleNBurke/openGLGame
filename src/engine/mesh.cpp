#include "mesh.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "materials/basicMaterial.hpp"
#include "materials/lambertMaterial.hpp"

Mesh::Mesh(Geometry& geometry, Material& material) :
	geometry(geometry),
	material(material) {}

void Mesh::render(glm::mat4& view, glm::mat4& proj) {
	glUseProgram(material.getProgram());

	//compose matrix from pos rot and scale
	//...

	//this can be done much more efficient using an enum to get the material type and a switch case
	BasicMaterial* basic = dynamic_cast<BasicMaterial*>(&material);
	if (basic != nullptr) {
		basic->sendData(proj * glm::inverse(view) * transform);
	}
	LambertMaterial* lambert = dynamic_cast<LambertMaterial*>(&material);
	if (lambert != nullptr) {
		lambert->sendData(proj * glm::inverse(view) * transform);
	}

	glBindVertexArray(geometry.getVao());
	glDrawArrays(GL_TRIANGLES, 0, geometry.getVertexCount());
}