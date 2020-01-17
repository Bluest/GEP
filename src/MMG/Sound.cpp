#include <iostream>

#include <Exception.h>
#include <stb_vorbis.h>

#include "Sound.h"

Sound::Sound(const std::shared_ptr<Core>& _core, const std::string& _name) : Resource(_core, _name)
{
	std::cout << " <Sound> from \"";

	bufferId = 0;
}

Sound::~Sound()
{
	alDeleteBuffers(1, &bufferId);
}

void Sound::onLoad(const std::string& _path)
{
	try
	{
		std::cout << _path << "\"" << std::endl;

		alGenBuffers(1, &bufferId);

		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;

		load_ogg(_path, bufferData, format, freq);

		alBufferData(bufferId, format, &bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()), freq);
	}
	catch (rend::Exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

ALuint Sound::getBufferId()
{
	return bufferId;
}

void Sound::load_ogg(const std::string& _path,
	std::vector<char>& _bufferData, ALenum& _format, ALsizei& _freq)
{
	int channels = 0;
	int sampleRate = 0;
	short* output = nullptr;

	size_t samples = stb_vorbis_decode_filename(
		_path.c_str(), &channels, &sampleRate, &output);

	if (samples < 0)
	{
		throw rend::Exception("Failed to open sound file");
	}

	// Record the sample rate required by OpenAL
	_freq = sampleRate;

	// Record the format required by OpenAL
	if (channels == 1)
	{
		_format = AL_FORMAT_MONO16;
	}
	else
	{
		_format = AL_FORMAT_STEREO16;

		// Force format to be mono (Useful for positional audio)
		// format = AL_FORMAT_MONO16;
		// freq *= 2;
	}

	// Allocate enough space based on short (two chars) multipled by the number of
	// channels and length of clip
	_bufferData.resize(sizeof(*output) * channels * samples);
	memcpy(&_bufferData.at(0), output, _bufferData.size());

	// Clean up the read data
	free(output);
}
