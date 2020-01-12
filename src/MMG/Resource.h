#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <string>

class Resource
{
public:
	Resource(const std::string& _path);

	std::string getName();

protected:
	std::string name;
};

#endif // _RESOURCE_H_
