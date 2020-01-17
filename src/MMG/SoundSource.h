#include <string>
#include <list>

#include <AL/al.h>

#include "Component.h"

class Sound;

/** \brief Component that plays sounds from an Entity.
*/
class SoundSource : public Component
{
public:
	/** \brief Generates the AL source for this component.
	*/
	void init();

	/** \brief Deletes the AL source.
	*/
	~SoundSource();

	/** \brief Adds a Sound resource to this SoundSource's library.
		\param _sound A pointer to the Sound that is being added
	*/
	void addSound(const std::shared_ptr<Sound>& _sound);

	/** \brief Plays a sound from this SoundSource's library.
		\param _name The name of the sound to be played
	*/
	void play(const std::string& _name);

private:
	ALuint sourceId;

	std::list<std::shared_ptr<Sound>> sounds;
};
