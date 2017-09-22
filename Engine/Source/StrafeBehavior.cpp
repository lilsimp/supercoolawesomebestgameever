#include "Components.h"
#include "Objects.h"

StrafeBehavior::StrafeBehavior(GameObject* owner, glm::vec3 start, float dist) :
	StartPos(start), MaxDistance(dist) {
	Owner = owner;
	Owner->Components.push_back(this);

	oPhys = dynamic_cast<Physics*>(Owner->GetComponent(PHYSICS));
	oTrans = dynamic_cast<Transform*>(Owner->GetComponent(TRANSFORM));
}

StrafeBehavior::~StrafeBehavior(void) {

}

void StrafeBehavior::onUpdate(void) {
	float curDist = glm::distance(oTrans->posVec, StartPos);
	if (curDist >= MaxDistance) {
		oPhys->Velocity *= -1;
		StartPos = oTrans->posVec;
	}
}
