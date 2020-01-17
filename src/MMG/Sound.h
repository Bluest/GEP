#ifndef _SOUND_H_
#define _SOUND_H_

#include <vector>

#include <AL/al.h>

#include "Resource.h"

class Sound : public Resource
{
public:
	Sound(const std::shared_ptr<Core>& _core, const std::string& _name);
	~Sound();

	void onLoad(const std::string& _path);
	ALuint getBufferId();

private:
	ALuint bufferId;

	void load_ogg(const std::string& _path,
		std::vector<char>& _bufferData, ALenum& _format, ALsizei& _freq);
};

#endif // _SOUND_H_
