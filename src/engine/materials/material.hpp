#pragma once

#include "../shaders/shader.hpp"

class Material {
	public:
		Material();
		virtual Shader& getShader() = 0;
	
	protected:
		static bool shaderInitialized;
};