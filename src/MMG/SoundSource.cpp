#include <glm/glm.hpp>

#include "SoundSource.h"
#include "Core.h"
#include "Camera.h"
#include "Entity.h"
#include "Sound.h"

void SoundSource::init()
{
	sourceId = 0;
	alGenSources(1, &sourceId);
}

SoundSource::~SoundSource()
{
	alDeleteSources(1, &sourceId);
}

void SoundSource::addSound(const std::shared_ptr<Sound>& _sound)
{
	sounds.push_back(_sound);
}

void SoundSource::play(const std::string& _name)
{
	std::shared_ptr<Sound> use = nullptr;

	if (!sounds.empty())
	{
		for (auto it = sounds.begin(); it != sounds.end(); it++)
		{
			if ((*it)->getName() == _name)
			{
				use = *it;
			}
		}
	}
	else
	{
		throw rend::Exception("SoundSource has no sounds to play");
	}

	if (!use)
	{
		throw rend::Exception("SoundSource does not have sound: " + _name);
	}

	glm::vec3 position = getCore()->getCamera()->getPosition() + getEntity()->transform.position;

	ALint state = 0;
	alGetSourcei(sourceId, AL_SOURCE_STATE, &state);

	if (state != AL_PLAYING)
	{
		alSource3f(sourceId, AL_POSITION, position.x, position.y, position.z);
		alSourcei(sourceId, AL_BUFFER, use->getBufferId());
		alSourcePlay(sourceId);
	}
}
