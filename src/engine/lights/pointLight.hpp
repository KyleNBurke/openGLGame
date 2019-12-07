#pragma once

#include "../object3D.hpp"
#include <glad/glad.h>

class PointLight : public Object3D {
	public:
		PointLight(Vector3 color = Vector3(1.0f));
		void update(int offset);
		static void updateLightCount(int count);
		
		static const int maxCount;
		GLuint getBlock();
		Vector3 color;

	private:
		void init();
		static bool initialized;
		static GLuint block;
		static GLuint bindingPoint;
};