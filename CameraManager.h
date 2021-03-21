#ifndef __CAMERA_MANAGER__
#define __CAMERA_MANAGER__
#include "Point.h"
class CameraManager:public Point
{
	float row, col;
public:
	CameraManager();
	void init();
	void update();
	float getRow();
	float getCol();
};
#endif