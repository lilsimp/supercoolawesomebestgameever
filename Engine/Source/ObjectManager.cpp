#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <utility>

#include "ObjectManager.h"
#include "Component.h"
#include "Render.h"

ObjectManager::ObjectManager(Camera* cam, unsigned long max) {
	WorldCam = cam;
	MAX_OBJECTS = max;
	
	OBJECT_ARRAY = new GameObject[MAX_OBJECTS * MODEL_NUM];

	for (unsigned long i = 0; i < MAX_OBJECTS * MODEL_NUM; ++i)
		OBJECT_ARRAY[i].SetOwner(this);

	Objects.resize(MODEL_NUM);
}

ObjectManager::~ObjectManager(void) {
	for (int i = 0; i < MODEL_NUM; ++i)
		Objects[i].clear();

	delete [] OBJECT_ARRAY;
}

void ObjectManager::Update(void) {
	for (unsigned long i = 0; i < ACTIVE_OBJECTS; ++i) {
		unsigned int comps = OBJECT_ARRAY[i].Components.size();
		for (unsigned int j = 0; j < comps; ++j)
			OBJECT_ARRAY[i].Components[j]->onUpdate();
	}
}

void ObjectManager::EndFrame(void) {
	std::vector<GameObject*>::iterator queObj;
	GameObject* obj;

	for (queObj = Queue_create.begin(); queObj != Queue_create.end(); ++queObj) {
		GameObject* obj = (*queObj);
		MODEL_TYPE type = obj->model;

		Objects[type].push_back(obj);

		obj->ACTIVE = true;
		ACTIVE_OBJECTS++;
	}

	Queue_create.clear();
}

GameObject* ObjectManager::CreateGameObject(std::string name, MODEL_TYPE model) {
	if (ACTIVE_OBJECTS < (MAX_OBJECTS * MODEL_NUM)) {
		GameObject* obj = &OBJECT_ARRAY[ACTIVE_OBJECTS + Queue_create.size()];

		obj->Name = name;
		obj->model = model;

		Queue_create.push_back(obj);

		return obj;
	}
	else 
		return NULL;
}
