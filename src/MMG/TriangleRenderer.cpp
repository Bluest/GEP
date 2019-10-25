#include "TriangleRenderer.h"
#include "Core.h"

void TriangleRenderer::onStart()
{
	printf("TriangleRenderer started\n");
}

void TriangleRenderer::onUpdate()
{
	printf("ok dying now\n");
	getCore()->quit();
}
