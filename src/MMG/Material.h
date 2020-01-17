#include "Resource.h"

/** \brief Resource class for a shader and a texture.
*/
class Material : public Resource
{
public:
	/** \brief Calls the base Resource constructor.
		\param _core Pointer to Core
		\param _name The unique name of the resource
	*/
	Material(const std::shared_ptr<Core>& _core, const std::string& _name);

	/** \brief Loads the file at _path.
		\param _path Relative file path to load from
	*/
	void onLoad(const std::string& _path);

	/** \brief Getter for the material's shader.
		\return A pointer to Material::shader
	*/
	std::sr1::shared_ptr<rend::Shader> getShader();

	/** \brief Getter for the material's texture.
		\return A pointer to Material::texture
	*/
	std::sr1::shared_ptr<rend::Texture> getTexture();

private:
	std::sr1::shared_ptr<rend::Shader> shader;
	std::sr1::shared_ptr<rend::Texture> texture;
};
