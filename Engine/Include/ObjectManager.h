#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "Objects.h"
#include "Camera.h"

#include <list>
#include <vector>

class ObjectManager {
public:
	ObjectManager(Camera* cam, unsigned long max = 256);
	~ObjectManager(void);

	void Update(void);
	void EndFrame(void);

	GameObject* CreateGameObject(std::string name, MODEL_TYPE model);

	Camera* WorldCam;

	// Sorted by MESH_TYPE = index into the vector, 
	// Textured or untext into list
	std::vector< std::vector<GameObject*> > Objects;

	unsigned long MAX_OBJECTS;
	unsigned long ACTIVE_OBJECTS;
	GameObject* OBJECT_ARRAY;

private:
	std::vector<GameObject*> Queue_create;
	std::vector< std::pair<MODEL_TYPE, unsigned long> > Queue_delete;

};

#endif // !OBJECTMANAGER_H
