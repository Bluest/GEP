#ifndef _SOUND_SOURCE_H_
#define _SOUND_SOURCE_H_

#include <string>
#include <list>

#include <AL/al.h>

#include "Component.h"

class Sound;

class SoundSource : public Component
{
public:
	void init();
	~SoundSource();

	void addSound(const std::shared_ptr<Sound>& _sound);
	void play(const std::string& _name);

private:
	ALuint sourceId;

	std::list<std::shared_ptr<Sound>> sounds;
};

#endif // _SOUND_SOURCE_H_
