#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "Resource.h"

class Material : public Resource
{
public:
	Material(const std::string& _path);

private:
	std::sr1::shared_ptr<rend::Texture> texture;
	std::sr1::shared_ptr<rend::Shader> shader;
};

#endif // _MATERIAL_H_
