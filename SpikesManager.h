#ifndef __SPIKES_MANAGER__
#define __SPIKES_MANAGER__
#include "Spike.h"
#include "GameManager.h"
class SpikesManager
{
	vector<Spike> s;
public:
	SpikesManager();
	void addSpike(float,float);
	void update();
	void draw();
	bool checkCollision();
	void clear();
};
#endif
