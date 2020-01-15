#ifndef _MODEL_H_
#define _MODEL_H_

#include "Resource.h"

class Model : public Resource
{
public:
	Model(const std::shared_ptr<Core>& _core, const std::string& _name);

	void onLoad(const std::string& _path);
	std::sr1::shared_ptr<rend::Mesh> getMesh();

private:
	std::sr1::shared_ptr<rend::Mesh> mesh;
};

#endif // _MODEL_H_
