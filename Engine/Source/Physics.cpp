#include "Components.h"
#include "Objects.h"
#include "FrameTime.h"

Physics::Physics(GameObject* owner, glm::vec3 vel, float a) {
	Owner = owner;
	Owner->Components.push_back(this);

	Velocity = vel;
	Acceleration = a;
	oTrans = dynamic_cast<Transform*>(Owner->GetComponent(TRANSFORM));
}

Physics::~Physics(void) {

}

void Physics::onUpdate(void) {
	float dt = FrameTimeGetElapsed();
	glm::vec3 frameVel = Velocity * dt;
	oTrans->Translate(frameVel);
}
