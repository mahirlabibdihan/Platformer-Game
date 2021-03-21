#ifndef __SPIKE__
#define __SPIKE__
#include "Box.h"
class Spike:public Box
{
	float amplitude, velX, centerX;
public:
	Spike();
	void init();
	void setCenter(float,float);
	void update();
};
#endif // !__SPIKE__

