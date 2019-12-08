#include "mesh.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "materials/basicMaterial.hpp"
#include "materials/lambertMaterial.hpp"
#include "helpers/pointLightHelper.hpp"

Mesh::Mesh(Geometry& geometry, Material& material) : geometry(geometry), material(material) {}

void Mesh::render(const Matrix4& view, const Matrix4& proj, const Vector3& ambientLight) {
	glUseProgram(material.getProgram());

	if (autoUpdateMatrix) {
		updateMatrix();
	}

	Matrix4 transformMat = proj * view * matrix;

	//this can be done much more efficient using an enum to get the material type and a switch case (translation matrix should use a UBO)
	BasicMaterial* basic = dynamic_cast<BasicMaterial*>(&material);
	if (basic != nullptr) {
		basic->sendData(transformMat);
	}

	LambertMaterial* lambert = dynamic_cast<LambertMaterial*>(&material);
	if (lambert != nullptr) {
		Matrix3 normalMat = Matrix3(Matrix4(matrix).invert().transpose());
		lambert->sendData(transformMat, matrix, normalMat, ambientLight);
	}

	glBindVertexArray(geometry.getVao());
	glDrawArrays(GL_TRIANGLES, 0, geometry.getVertexCount());
}