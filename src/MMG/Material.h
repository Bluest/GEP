#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "Resource.h"

class Material : public Resource
{
public:
	Material(const std::shared_ptr<Core>& _core, const std::string& _name);

	void onLoad(const std::string& _path);
	std::sr1::shared_ptr<rend::Shader> getShader();
	std::sr1::shared_ptr<rend::Texture> getTexture();

private:
	std::sr1::shared_ptr<rend::Shader> shader;
	std::sr1::shared_ptr<rend::Texture> texture;
};

#endif // _MATERIAL_H_
