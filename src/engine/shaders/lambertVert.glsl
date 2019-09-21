#version 430 core

layout (location = 0) in vec3 aPos;
out vec3 color;
uniform mat4 transform;
uniform vec3 ambientLight;

struct pointLight {
	vec3 position;
	vec3 color;
};

layout (std140, binding = 1) uniform pointLightBlock {
	//pointLight lights[1];
	vec3 colorTest;
};

void main() {
	gl_Position = transform * vec4(aPos, 1.0);
	//color = lights[0].color;
	color = colorTest;
}