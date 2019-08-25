#pragma once

#include <glad/glad.h>
#include <string>
#include <sstream>

class Shader {
	public:
		Shader();
		void init(std::string baseFileName);

		GLuint program;
		GLint transformLoc;
	
	private:
		void load(std::string fileName, GLuint shader);

		static const std::string path;
};