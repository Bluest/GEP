#include "MeshRenderer.h"
#include "Model.h"
#include "Material.h"
#include "Core.h"
#include "Entity.h"

void MeshRenderer::init(const std::shared_ptr<Model>& _model, const std::shared_ptr<Material>& _material)
{
	model = _model;
	material = _material;

	// Set shortcuts
	shader = material->getShader();
	mesh = model->getMesh();
	texture = material->getTexture();
}

glm::mat4 MeshRenderer::updateModel()
{
	// Initialised as identity matrix
	glm::mat4 model(1.0f);

	// Pointer to entity's Transform
	std::shared_ptr<Transform> transform = std::make_shared<Transform>(getEntity()->transform);

	// Update model position
	model = glm::translate(model, transform->position);

	// Update model rotation
	model = glm::rotate(model, glm::radians(transform->rotation.x), glm::vec3(1, 0, 0));
	model = glm::rotate(model, glm::radians(transform->rotation.y), glm::vec3(0, 1, 0));
	model = glm::rotate(model, glm::radians(transform->rotation.z), glm::vec3(0, 0, 1));

	// Update model scale
	model = glm::scale(model, transform->scale);

	return model;
}

void MeshRenderer::onDraw()
{
	// shader->setUniform("u_Projection", getCore()->currentCamera()->getPerspective());
	mesh->setTexture("u_Texture", texture); 
	shader->setUniform("u_Projection", glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f));
	shader->setUniform("u_Model", updateModel());

	shader->setMesh(mesh);

	shader->render();
}
