#ifndef CUBEBEHAVIOR_H
#define CUBEBEHAVIOR_H

#include "Component.h"

class StrafeBehavior : public Component<CUBEBEHAVIOR> {
public:
	StrafeBehavior(GameObject* owner, glm::vec3 start, float dist);
	~StrafeBehavior();

	void onUpdate(void);

	glm::vec3 StartPos;
	float MaxDistance;
	Physics* oPhys;
	Transform* oTrans;
};

#endif // !CUBEBEHAVIOR_H
