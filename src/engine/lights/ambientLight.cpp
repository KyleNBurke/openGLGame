#include "ambientLight.hpp"

AmbientLight::AmbientLight(glm::vec3 color = glm::vec3(), float intensity = 0.2) : Light(color, intensity) {}