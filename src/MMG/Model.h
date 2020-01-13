#ifndef _MODEL_H_
#define _MODEL_H_

#include "Resource.h"

class Model : public Resource
{
public:
	Model(const std::string& _path);

private:
	std::sr1::shared_ptr<rend::Mesh> mesh;
};

#endif // _MODEL_H_
