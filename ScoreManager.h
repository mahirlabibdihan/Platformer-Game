#ifndef __SCORE_MANAGER__
#define __SCORE_MANAGER__
#include "GameManager.h"
class ScoreManager {
	int currentScore;
	string name;
public:
	ScoreManager();
	void increase();
	void draw();
	void drawBoard();
	void drawGameOver();
	void save();
	void reset();
	void nameEntry(unsigned char);
};
#endif
