#ifndef __MENU_MANAGER__
#define __MENU_MANAGER__
#include "GameManager.h"
class MenuManager {
	
public:
	enum menus { MAIN, PLAY, SCORE, GAMEOVER };
	enum menuOption {PLAY_GAME,SCORE_BOARD,QUIT_GAME};
	MenuManager();
	int getMenu();
	void setMenu(menus);
	void drawPlayGame();
	void drawMainMenu();
	void drawGameOver();
	void keyDown();
	void keyUp();
	void draw();
	void keyEnter();
private:
	menus menuName;
	menuOption option;
};
#endif
