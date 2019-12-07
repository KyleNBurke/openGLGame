#pragma once

#include "material.hpp"
#include "../math/vector3.hpp"
#include "../math/matrix4.hpp"
#include "../math/matrix3.hpp"

class LambertMaterial : public Material {
	public:
		LambertMaterial(Vector3 color = Vector3());
		void lambertInit();
		void sendData(const Matrix4& transMat, const Matrix4& modelMat, const Matrix3& normMat, const Vector3& ambientLight);
		GLuint getProgram() const;
		
		Vector3 color;

	private:
		static bool initialized;
		static GLuint program;
		static GLint transformLoc;
		static GLint modelMatrixLoc;
		static GLint normalMatrixLoc;
		static GLint materialColorLoc;
		static GLint ambientLightLoc;
};