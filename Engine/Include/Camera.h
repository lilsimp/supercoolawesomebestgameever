#ifndef CAMERA_H
#define CAMERA_H

#include "main.h"

class Camera {
public:
	Camera(glm::mat4 projection, glm::mat4 view) :
		Projection(projection), View(view), proj(true) {};

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection;

	// Camera matrix
	glm::mat4 View;

	glm::vec3 position;
	glm::vec3 front;

	bool proj;
};

#endif // !CAMERA_H
