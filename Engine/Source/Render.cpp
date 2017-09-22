#include "Render.h"
#include "Shader.h"
#include "Mesh.h"
#include "Model.h"
#include "Transform.h"

static Shader* shader;
static Model models[MODEL_NUM];

// positions of the point lights
static glm::vec3 pointLightPositions[] = {
	glm::vec3(0.7f,  0.2f,  2.0f),
	glm::vec3(2.3f, -3.3f, -4.0f),
	glm::vec3(-4.0f,  2.0f, -12.0f),
	glm::vec3(0.0f,  0.0f, -3.0f)
};

/************************************************************/
/************************************************************/

void RenderInit(void) {
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	// Mesh drawing
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void RenderShutdown(void) {

}

void RenderLoad() {
	// Create and compile our GLSL program from the shaders
	shader = new Shader("Shaders/MultiLight.vs", "Shaders/MultiLight.fs");

	models[CRATE_MODEL] = Model("Models/cube/cube.obj");
	models[NANOSUIT_MODEL] = Model("Models/nanosuit/nanosuit.obj");
	models[CANNON_MODEL] = Model("Models/cannon/cannon.obj");
}

void RenderUnload(void) {
	delete shader;
}

void RenderGameObjects(ObjectManager *pObjManager) {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::vector< std::vector<GameObject*> >::iterator it;

	shader->Use();

	Camera* camera = pObjManager->WorldCam;

	shader->setVec3("viewPos", camera->position);

	/*
	Here we set all the uniforms for the 5/6 types of lights we have. We have to set them manually and index
	the proper PointLight struct in the array to set each uniform variable. This can be done more code-friendly
	by defining light types as classes and set their values in there, or by using a more efficient uniform approach
	by using 'Uniform buffer objects', but that is something we'll discuss in the 'Advanced GLSL' tutorial.
	*/
	// directional light
	shader->setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
	shader->setVec3("dirLight.ambient", 0.25f, 0.25f, 0.25f);
	shader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
	shader->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
	// point light 1
	shader->setVec3("pointLights[0].position", pointLightPositions[0]);
	shader->setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
	shader->setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
	shader->setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
	shader->setFloat("pointLights[0].constant", 1.0f);
	shader->setFloat("pointLights[0].linear", 0.09);
	shader->setFloat("pointLights[0].quadratic", 0.032);
	// point light 2
	shader->setVec3("pointLights[1].position", pointLightPositions[1]);
	shader->setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
	shader->setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
	shader->setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
	shader->setFloat("pointLights[1].constant", 1.0f);
	shader->setFloat("pointLights[1].linear", 0.09);
	shader->setFloat("pointLights[1].quadratic", 0.032);
	// point light 3
	shader->setVec3("pointLights[2].position", pointLightPositions[2]);
	shader->setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
	shader->setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
	shader->setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
	shader->setFloat("pointLights[2].constant", 1.0f);
	shader->setFloat("pointLights[2].linear", 0.09);
	shader->setFloat("pointLights[2].quadratic", 0.032);
	// point light 4
	shader->setVec3("pointLights[3].position", pointLightPositions[3]);
	shader->setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
	shader->setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
	shader->setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
	shader->setFloat("pointLights[3].constant", 1.0f);
	shader->setFloat("pointLights[3].linear", 0.09);
	shader->setFloat("pointLights[3].quadratic", 0.032);
	// spotLight
	shader->setVec3("spotLight.position", camera->position);
	shader->setVec3("spotLight.direction", camera->front);
	shader->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
	shader->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
	shader->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
	shader->setFloat("spotLight.constant", 1.0f);
	shader->setFloat("spotLight.linear", 0.09);
	shader->setFloat("spotLight.quadratic", 0.032);
	shader->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
	shader->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "projection"), 1, GL_FALSE, &pObjManager->WorldCam->Projection[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "view"), 1, GL_FALSE, &pObjManager->WorldCam->View[0][0]);

	// Loop through each game object
	for (it = pObjManager->Objects.begin(); it !=  pObjManager->Objects.end(); ++it) {
		std::vector<GameObject*>::iterator Objs;
		for (Objs = (*it).begin(); Objs != (*it).end(); ++Objs) {

			GameObject* obj = (*Objs);
			Transform* trans = dynamic_cast<Transform*>(obj->GetComponent(TRANSFORM));

			// Transformation matrices
			glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, &trans->Model[0][0]);

			// Draw the loaded model
			models[obj->model].Draw(*shader);
		}
	}
}
