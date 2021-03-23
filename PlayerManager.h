#ifndef __PLAYER_MANAGER__
#define __PLAYER_MANAGER__
#include "Box.h"
class PlayerManager:public Box
{
	float velX,velY;
	float newX, newY;	// Expected next position
	float gravity;

	bool onGround;	// True if player is on ground
	float row, col;
	int life;

	//Starting and ending position of a level
	int startR, startC, endR, endC;

public:
	PlayerManager();
	void update();
	void draw();
	void drawLife();	// Draw remaining lives in top right corner of game screen
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	float getRow();
	float getCol();
	void setPosition(float, float);
	void init();
	void set();
	void setStart(int,int);
	void setEnd(int,int);
	void reset();
};
#endif