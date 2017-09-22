#include "Components.h"
#include "ObjectManager.h"
#include "Camera.h"
#include "Scripts.h"
#include "FrameTime.h"
#include "Render.h"

Transform::Transform(GameObject* owner, glm::vec3 scale,
	glm::vec3 trans, glm::vec3 rotate) : scaleVec(scale), posVec(trans), rotVec(rotate) {
	
	Owner = owner;
	Owner->Components.push_back(this);

	main_cam = Owner->Owner->WorldCam;
}

Transform::~Transform(void) {
}

void Transform::onUpdate(void) {
	setMats();

	Model = Position * Rotation * Scale;
}

void Transform::Translate(glm::vec3 transVec) {
	posVec += transVec;
}

void Transform::setMats(void) {
	Scale = glm::scale(scaleVec);
	Position = glm::translate(posVec);
}
