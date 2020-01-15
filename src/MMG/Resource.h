#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <string>

class Core;

class Resource
{
public:
	Resource(const std::shared_ptr<Core>& _core, const std::string& _name);

	// Abstract: All derived resources should have an onLoad function
	virtual void onLoad(const std::string& _path) = 0;
	std::string getName();

protected:
	std::shared_ptr<Core> core;
	std::string name;

private:
};

#endif // _RESOURCE_H_
