#ifndef _MESH_RENDERER_H_
#define _MESH_RENDERER_H_

#include "rend.h"

#include "Component.h"

class Model;
class Material;

class MeshRenderer : public Component
{
public:
	void init(const std::shared_ptr<Model>& _model, const std::shared_ptr<Material>& _material);

private:
	std::shared_ptr<Model> model;
	std::shared_ptr<Material> material;

	// Shortcut pointers
	std::sr1::shared_ptr<rend::Shader> shader;
	std::sr1::shared_ptr<rend::Mesh> mesh;
	std::sr1::shared_ptr<rend::Texture> texture;

	glm::mat4 updateModel();

	void onDraw();
};

#endif // _MESH_RENDERER_H_
