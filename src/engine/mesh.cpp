#include "mesh.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "materials/basicMaterial.hpp"
#include "materials/lambertMaterial.hpp"
#include "helpers/pointLightHelper.hpp"

Mesh::Mesh(Geometry& geometry, Material& material) :
	geometry(geometry),
	material(material) {}

void Mesh::render(const Matrix4& view, const Matrix4& proj, const Vector3& ambientLight) {
	glUseProgram(material.getProgram());

	if (autoUpdateMatrix) {
		updateMatrix();
	}

	//this can be done much more efficient using an enum to get the material type and a switch case (translation matrix should use a UBO)
	BasicMaterial* basic = dynamic_cast<BasicMaterial*>(&material);
	if (basic != nullptr) {
		Matrix4 m = proj * view * matrix;
		basic->sendData(m);
	}
	/*LambertMaterial* lambert = dynamic_cast<LambertMaterial*>(&material);
	if (lambert != nullptr) {
		glm::mat4 transformMat = proj * view * matrix;
		glm::mat3 normalMat = glm::mat3(glm::transpose(glm::inverse(matrix)));
		lambert->sendData(transformMat, matrix, normalMat, ambientLight);
	}*/

	glBindVertexArray(geometry.getVao());
	glDrawArrays(GL_TRIANGLES, 0, geometry.getVertexCount());
}