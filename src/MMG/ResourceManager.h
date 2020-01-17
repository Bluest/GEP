#include <list>
#include <memory>
#include <string>

class Core;
class Resource;

/** \brief Handles the loading and accessing of resources.
*/
class ResourceManager
{
public:
	/** \brief Stores the passed pointer to Core.
		\param _core Pointer to Core
	*/
	ResourceManager(std::shared_ptr<Core> _core);

	/** \brief Loads the resource at _path, storing it as _name.
		\param _name Unique name for the resource to be accessed by
		\param _path Relative file path to load from
	*/
	template <typename T>
	void load(const std::string& _name, const std::string& _path)
	{
		std::shared_ptr<T> resource = std::make_shared<T>(core, _name);
		resource->onLoad(_path);
		resources.push_back(resource);
	}

	/** \brief Gets a resource from the ResourceManager.
		\param _name The name of the resource to use
		\return A pointer to the resource
	*/
	template <typename T>
	std::shared_ptr<T> use(const std::string& _name)
	{
		for (auto it = resources.begin(); it != resources.end(); it++)
		{
			if ((*it)->getName() == _name)
			{
				return std::dynamic_pointer_cast<T>(*it);
			}
		}

		throw rend::Exception("Resource \"" + _name + "\" not found");
		return nullptr;
	}

private:
	std::shared_ptr<Core> core;
	std::list<std::shared_ptr<Resource>> resources;
};
