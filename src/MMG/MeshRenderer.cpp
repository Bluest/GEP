#include "MeshRenderer.h"
#include "Core.h"

void MeshRenderer::init(const char* _file)
{
	printf("Loading file: %s\n", _file);
}

void MeshRenderer::onStart()
{
	printf("MeshRenderer: onStart()\n");
}

void MeshRenderer::onUpdate()
{
	printf("MeshRenderer: onUpdate()\n");
}

void MeshRenderer::onDraw()
{
	printf("MeshRenderer: onDraw()\n");
}
