#ifndef _SOUND_H_
#define _SOUND_H_

#include "Resource.h"

class Sound : public Resource
{
public:
	Sound(const std::shared_ptr<Core>& _core, const std::string& _name);

	void onLoad(const std::string& _path);
};

#endif // _SOUND_H_
