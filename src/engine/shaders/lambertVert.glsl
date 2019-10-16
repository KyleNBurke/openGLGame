#version 430 core

#define MAX_POINT_LIGHTS 10

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;
uniform mat4 transform;
uniform vec3 materialColor;
uniform vec3 ambientLight;
out vec3 color;

struct PointLight {
	vec3 position;
	vec3 color;
};

layout (std140, binding = 1) uniform PointLightBlock {
	PointLight lights[MAX_POINT_LIGHTS];
	int count;
} pointLights;

vec3 calcPointLightColor(PointLight light, vec3 vertPos, vec3 normal);

void main() {
	gl_Position = transform * vec4(aPos, 1.0f);
	//color = pointLights.lights[0].color;

	color = ambientLight;
	int temp = 1;

	for (int i = 0; i < temp; i++) {
		color += calcPointLightColor(pointLights.lights[i], aPos, aNorm);
	}
}

vec3 calcPointLightColor(PointLight light, vec3 vertPos, vec3 normal) {
	vec3 lightDir = normalize(light.position - vertPos);
	float diff = max(dot(normal, lightDir), 0.0f);
	float atten = 1.0f;
	return light.color * diff * atten;
}