#ifndef PHYSICS_H
#define PHYSICS_H

#include "Component.h"

class Physics : public Component<PHYSICS> {
public:
	Physics(GameObject* owner, glm::vec3 vel = vec3(0), float a = 0);
	~Physics();

	void onUpdate(void);

	float Acceleration;
	glm::vec3 Velocity;

private:
	Transform* oTrans;
};

#endif // !PHYSICS_H
