#include "main.h"
#include "Scripts.h"

glm::vec3 circleStep(float radius, int steps, int t) {
	float x = (cos(t)) * (radius / steps);
	float z = (sin(t)) * (radius / steps);

	return glm::vec3(x, 0.0f, z);
}
