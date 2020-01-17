#include "Musician.h"

void Musician::init()
{
	getEntity()->transform.position = glm::vec3(3.5f, -2.0f, -15.0f);
	getEntity()->transform.rotation.y = 180;
	t = 0.0f;
}

void Musician::onStart()
{
	getEntity()->getComponent<SoundSource>()->play("Tune");
}

void Musician::onUpdate()
{
	getEntity()->transform.scale += 0.001f * sin(t);
	t += 0.01f;
}
