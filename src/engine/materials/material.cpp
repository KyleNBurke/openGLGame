#include "material.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Material::Material() {}

void Material::init(std::string baseFileName, GLuint& program, GLint& transformLoc) {
	std::string path = "./src/engine/shaders/";

	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

	load(path + baseFileName + "Vert.glsl", vertShader);
	load(path + baseFileName + "Frag.glsl", fragShader);

	program = glCreateProgram();
	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);
	
	GLint linked = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if(linked == GL_FALSE) {
		GLint length = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		char* error = new char[length];
		glGetProgramInfoLog(program, length, &length, error);
		std::cout << "shader link error:" << std::endl << error << std::endl;
		delete[] error;
	}

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
	
	transformLoc = glGetUniformLocation(program, "transform");
}

void Material::load(std::string fileName, GLuint shader) {
	std::ifstream file(fileName, std::ios_base::in);
	std::stringstream source;
	source << file.rdbuf();
	file.close();

	std::string sourceStr = source.str();
	int sourceLength = sourceStr.length();
	const char* sourceStrC = sourceStr.c_str();
	glShaderSource(shader, 1, &sourceStrC, &sourceLength);

	glCompileShader(shader);

	GLint compiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if(compiled == GL_FALSE) {
		GLint length = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		char* error = new char[length];
		glGetShaderInfoLog(shader, length, &length, error);
		std::cout << "shader compile error:" << std::endl << error << std::endl;
		delete[] error;
	}
}