#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__
#include "iGraphics.h"
class GameManager
{
	int score;
public:
	GameManager();
	void init();
	void scoreUp();
};
#endif