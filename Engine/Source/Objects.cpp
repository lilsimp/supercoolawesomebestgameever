#include "Objects.h"
#include "Components.h"

GameObject::~GameObject() {
	for (int i = Components.size() - 1; i >= 0; --i)
		delete Components[i];
}

void GameObject::SetOwner(ObjectManager* owner) {
	Owner = owner;
}

AbstractComp* GameObject::GetComponent(ComponentID id) const {
	for (int i = 0; i < Components.size(); ++i)
		if (Components[i]->GetCompID() == id)
			return Components[i];

	return NULL;
}
