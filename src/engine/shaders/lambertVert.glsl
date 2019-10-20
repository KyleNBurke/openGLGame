#version 430 core

#define MAX_POINT_LIGHTS 10

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;
uniform mat4 transform;
uniform mat4 modelMatrix;
uniform mat3 normalMatrix;
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

	color = ambientLight;

	for (int i = 0; i < pointLights.count; i++) {
		vec3 transformedVertPos = normalize(vec3(modelMatrix * vec4(aPos, 1.0f)));
		vec3 transformedNorm = normalize(normalMatrix * aNorm);
		color += calcPointLightColor(pointLights.lights[i], transformedVertPos, transformedNorm);
	}
}

vec3 calcPointLightColor(PointLight light, vec3 vertPos, vec3 normal) {
	vec3 lightDir = normalize(light.position - vertPos);
	float diff = max(dot(normal, lightDir), 0.0f);
	float atten = 1.0f;
	return light.color * diff * atten;
}