#pragma once

#include <glad/glad.h>
#include <string>

class Material {
	public:
		Material();
		virtual GLuint getProgram() const = 0;

	protected:
		void init(std::string baseFileName, GLuint& program, GLint& transformLoc);
		void load(std::string fileName, GLuint shader);
};