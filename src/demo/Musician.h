#include <MMG.h>

class Musician : public Component
{
public:
	void init();

private:
	float t;

	void onStart();
	void onUpdate();
};
