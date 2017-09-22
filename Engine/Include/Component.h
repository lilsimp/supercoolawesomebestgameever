#ifndef COMPONENT_H
#define COMPONENT_H

#include "main.h"

typedef class GameObject GameObject;

enum ComponentID {
	TRANSFORM = 0,
	PHYSICS,
	CUBEBEHAVIOR,
	RANDOMROTATIONBEHAVIOR,
	MAX_COMPONENT
};

class AbstractComp {
public:
	virtual void onUpdate(void) = 0;
	virtual ComponentID GetCompID(void) const = 0;
};

template <ComponentID id> 
class Component : public AbstractComp {
public:
	Component() : CompID(id) {};
	ComponentID GetCompID(void) const {
		return CompID;
	};

	virtual void onUpdate(void) = 0;

	ComponentID CompID;
	GameObject* Owner;
};

#endif
