#include "mesh.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "materials/basicMaterial.hpp"
#include "materials/lambertMaterial.hpp"
#include "helpers/pointLightHelper.hpp"

Mesh::Mesh(Geometry& geometry, Material& material) :
	geometry(geometry),
	material(material) {}

void Mesh::render(const glm::mat4& view, const glm::mat4& proj, const glm::vec3& ambientLight) {
	glUseProgram(material.getProgram());

	//compose matrix from pos rot and scale
	//...

	//need a better design for this
	PointLightHelper* pointLightHelper = dynamic_cast<PointLightHelper*>(this);
	if (pointLightHelper != nullptr) {
		pointLightHelper->transform = pointLightHelper->pointLight.transform;
	}

	//this can be done much more efficient using an enum to get the material type and a switch case (translation matrix should use a UBO)
	BasicMaterial* basic = dynamic_cast<BasicMaterial*>(&material);
	if (basic != nullptr) {
		basic->sendData(proj * view * transform);
	}
	LambertMaterial* lambert = dynamic_cast<LambertMaterial*>(&material);
	if (lambert != nullptr) {
		glm::mat4 transformMat = proj * view * transform; //rename the last transform to model
		glm::mat3 normalMat = glm::mat3(glm::transpose(glm::inverse(transform)));
		lambert->sendData(transformMat, transform, normalMat, ambientLight);
	}

	glBindVertexArray(geometry.getVao());
	glDrawArrays(GL_TRIANGLES, 0, geometry.getVertexCount());
}