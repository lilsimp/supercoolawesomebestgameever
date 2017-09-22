#include "Components.h"
#include "Objects.h"

RandRotationBehavior::RandRotationBehavior(GameObject* owner) {
	Owner = owner;
	Owner->Components.push_back(this);

	oTrans = dynamic_cast<Transform*>(Owner->GetComponent(TRANSFORM));
}

RandRotationBehavior::~RandRotationBehavior(void) {
}

void RandRotationBehavior::onUpdate(void) {
	float angle = glfwGetTime() / 1000.0 * 65;  // base 15° per second
	oTrans->Rotation = \
		glm::rotate(glm::mat4(1.0f), angle*3.0f, glm::vec3(1, 0, 0)) *  // X axis
		glm::rotate(glm::mat4(1.0f), angle*2.0f, glm::vec3(0, 1, 0)) *  // Y axis
		glm::rotate(glm::mat4(1.0f), angle*4.0f, glm::vec3(0, 0, 1));   // Z axis
}
