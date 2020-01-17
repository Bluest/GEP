#include <vector>

#include <AL/al.h>

#include "Resource.h"

/** \brief Resource class for .ogg audio files.
*/
class Sound : public Resource
{
public:
	/** \brief Calls the base Resource constructor.
		\param _core Pointer to Core
		\param _name The unique name of the resource
	*/
	Sound(const std::shared_ptr<Core>& _core, const std::string& _name);

	/** \brief Deletes the AL buffer used by the sound.
	*/
	~Sound();

	/** \brief Loads the file at _path.
		\param _path Relative file path to load from
	*/
	void onLoad(const std::string& _path);

	/** \brief Getter for the sound's buffer id.
		\return Sound::bufferId
	*/
	ALuint getBufferId();

private:
	ALuint bufferId;

	void load_ogg(const std::string& _path,
		std::vector<char>& _bufferData, ALenum& _format, ALsizei& _freq);
};
