#pragma once
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/mat4x4.hpp>

class Object3D {
	public:
		Object3D();
		virtual ~Object3D() {};

		virtual void updateMatrix();
		void setMatrix(glm::mat4 matrix);
		const glm::mat4& getMatrix() const;

		bool autoUpdateMatrix;
		glm::vec3 position;
		glm::quat rotation;
		glm::vec3 scale;
	
	protected:
		glm::mat4 matrix;
};