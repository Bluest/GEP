#include "Resource.h"

/** \brief Resource class for a .obj mesh.
*/
class Model : public Resource
{
public:
	/** \brief Calls the base Resource constructor.
		\param _core Pointer to Core
		\param _name The unique name of the resource
	*/
	Model(const std::shared_ptr<Core>& _core, const std::string& _name);

	/** \brief Loads the file at _path.
		\param _path Relative file path to load from
	*/
	void onLoad(const std::string& _path);

	/** \brief Getter for the model's mesh.
		\return A pointer to Model::mesh
	*/
	std::sr1::shared_ptr<rend::Mesh> getMesh();

private:
	std::sr1::shared_ptr<rend::Mesh> mesh;
};
