#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <string>

class Core;

/** \brief Base resource class.
*/
class Resource
{
public:
	/** \brief The resource stores its name and a pointer to Core.
		\param _core Pointer to Core
		\param _name The unique name of the resource
	*/
	Resource(const std::shared_ptr<Core>& _core, const std::string& _name);

	/** \brief Abstract: All derived resources must have an onLoad(_path) method.
		\param _path Relative file path to load from 
	*/
	virtual void onLoad(const std::string& _path) = 0;

	/** \brief Getter for the resource's name.
		\return The resource's identifying name
	*/
	std::string getName();

protected:
	std::shared_ptr<Core> core;
	std::string name;

private:
};

#endif // _RESOURCE_H_
