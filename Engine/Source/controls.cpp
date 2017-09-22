// Include GLFW
#include "main.h"
#include "controls.h"
#include "FrameTime.h"

extern GLFWwindow* window;

glm::vec3 position = glm::vec3(20,20,20);
// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;

float speed = 30.0f; // 3 units / second
float mouseSpeed = 0.005f;



void computeMatricesFromInputs(Camera* cam){
	float deltaTime = FrameTimeGetElapsed();

	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	// Reset mouse position for next frame
	glfwSetCursorPos(window, 1600/2, 900/2);

	// Compute new orientation
	horizontalAngle += mouseSpeed * float(1600 /2 - xpos );
	verticalAngle   += mouseSpeed * float(900 /2 - ypos );

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle), 
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);
	
	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f/2.0f), 
		0,
		cos(horizontalAngle - 3.14f/2.0f)
	);
	
	// Up vector
	glm::vec3 up = glm::cross( right, direction );

	// Move forward
	if (glfwGetKey( window, GLFW_KEY_W ) == GLFW_PRESS){
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey( window, GLFW_KEY_S ) == GLFW_PRESS){
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey( window, GLFW_KEY_D ) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey( window, GLFW_KEY_A ) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}
	// Camera matrix
	cam->View = glm::lookAt(position,           // Camera is here
							position+direction, // and looks here : at the same position, plus "direction"
							up);                // Head is up (set to 0,-1,0 to look upside-down)
	cam->position = position;
	cam->front = direction;
}