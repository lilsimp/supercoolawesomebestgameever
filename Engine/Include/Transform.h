#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "main.h"
#include "Component.h"
#include <vector>

typedef class Camera Camera;

class Transform : public Component<TRANSFORM>{
public:
	Transform(GameObject* owner, glm::vec3 scale = glm::vec3(1), 
			  glm::vec3 trans = glm::vec3(0), glm::vec3 rotate = glm::vec3(0));
	~Transform();

	void onUpdate(void);
	void Translate(glm::vec3 transVec);

	Camera* main_cam;
	glm::vec3 scaleVec, posVec, rotVec;
	glm::mat4 Scale, Position, Rotation, Model;
	
private:
	void setMats(void);
};

#endif // !TRANSFORM_H
