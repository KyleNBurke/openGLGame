#include "lambertMaterial.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

bool LambertMaterial::initialized = false;
GLuint LambertMaterial::program = 0;
GLint LambertMaterial::transformLoc = 0;
GLint LambertMaterial::modelMatrixLoc = 0;
GLint LambertMaterial::normalMatrixLoc = 0;
GLint LambertMaterial::materialColorLoc = 0;
GLint LambertMaterial::ambientLightLoc = 0;

LambertMaterial::LambertMaterial(Vector3 color) :
	color(color)
{
	if (!initialized) {
		init("lambert", program, transformLoc);
		lambertInit();
		initialized = true;
	}
}

void LambertMaterial::lambertInit() {
	modelMatrixLoc = glGetUniformLocation(program, "modelMatrix");
	normalMatrixLoc = glGetUniformLocation(program, "normalMatrix");
	materialColorLoc = glGetUniformLocation(program, "materialColor");
	ambientLightLoc = glGetUniformLocation(program, "ambientLight");
}

void LambertMaterial::sendData(const Matrix4& transMat, const Matrix4& modelMat, const Matrix3& normMat, const Vector3& ambientLight) {
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, transMat.getElements());
	glUniformMatrix4fv(modelMatrixLoc, 1, GL_FALSE, modelMat.getElements());
	glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, normMat.getElements());

	float colorElements[] = {color.x, color.y, color.z};
	glUniform3fv(materialColorLoc, 1, colorElements);

	float ambientLightElements[] = {ambientLight.x, ambientLight.y, ambientLight.z};
	glUniform3fv(ambientLightLoc, 1, ambientLightElements);
}

GLuint LambertMaterial::getProgram() const {
	return LambertMaterial::program;
}