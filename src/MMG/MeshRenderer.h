#ifndef _MESHRENDERER_H_
#define _MESHRENDERER_H_

#include "Component.h"

class MeshRenderer : public Component
{
private:
	void onStart();
	void onUpdate();
	void onDraw();

public:
	void init(const char* _file);
};

#endif
