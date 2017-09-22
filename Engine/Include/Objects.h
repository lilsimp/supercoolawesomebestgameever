#ifndef OBJECTS_H
#define OBJECTS_H

#include <string>
#include <vector>
#include "main.h"
#include "Component.h"

typedef class ObjectManager ObjectManager;

enum MODEL_TYPE {
	NO_MODEL = -1,
	CRATE_MODEL,
	NANOSUIT_MODEL,
	CANNON_MODEL,
	MODEL_NUM
};

class GameObject {
public:
	GameObject(void) : Owner(NULL), Name("INVALID"), model(NO_MODEL), ACTIVE(false) {};
	~GameObject();

	void SetOwner(ObjectManager* owner);
	AbstractComp* GetComponent(ComponentID id) const;

	ObjectManager* Owner;
	std::string Name;
	bool ACTIVE;
	std::vector<AbstractComp*> Components;

	MODEL_TYPE model;
};

#endif
