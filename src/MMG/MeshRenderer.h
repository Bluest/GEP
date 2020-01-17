#include "rend.h"

#include "Component.h"

class Model;
class Material;

/** \brief Component that render's an Entity's model and material.
*/
class MeshRenderer : public Component
{
public:
	/** \brief Sets the model and material to render.
		\param _model The entity's model
		\param _material The entity's material
	*/
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
