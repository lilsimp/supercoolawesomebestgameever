#ifndef RANDOMROTATIONBEHAVIOR_H
#define RANDOMROTATIONBEHAVIOR_H

#include "Component.h"

class RandRotationBehavior : public Component<RANDOMROTATIONBEHAVIOR> {
public:
	RandRotationBehavior(GameObject* owner);
	~RandRotationBehavior(void);

	void onUpdate(void);

	Transform* oTrans;
};

#endif // !RANDOMROTATIONBEHAVIOR_H
