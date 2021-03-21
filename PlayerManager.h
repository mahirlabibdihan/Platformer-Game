#ifndef __PLAYER_MANAGER__
#define __PLAYER_MANAGER__
#include "Box.h"
class PlayerManager:public Box
{
	float velX;
	float newX, newY;
	float gravity;
	bool onGround;
	float row, col;
	int life;
	float velY;
	int startR, startC, endR, endC;

public:
	PlayerManager();
	void update();
	void draw();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	float getRow();
	float getCol();
	void setPosition(float, float);
	void init();
	void die();
	void setStart(int,int);
	void setEnd(int,int);
};
#endif