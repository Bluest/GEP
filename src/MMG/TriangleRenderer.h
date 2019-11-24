#ifndef _TRIANGLERENDERER_H_
#define _TRIANGLERENDERER_H_

#include "Component.h"

class TriangleRenderer : public Component
{
private:
	void onStart();
	void onUpdate();
	void onDraw();
};

#endif
