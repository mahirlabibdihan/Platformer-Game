#ifndef __MENU_MANAGER__
#define __MENU_MANAGER__
#include "GameManager.h"
class MenuManager {
public:
	enum menus { MAIN, PLAY, SCORE, GAMEOVER };
	enum menuOption {PLAY_GAME,SCORE_BOARD,QUIT_GAME};
	MenuManager();
	int get();
	void set(menus);
	void keyDown();
	void keyUp();
	void keyEnter();
	void draw();
	void drawPlayGame();
	void drawMainMenu();
	void drawGameOver();
	void drawScoreBoard();
private:
	menus menuName;
	menuOption option;
};
#endif
