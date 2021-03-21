#include "GameManager.h"
#include "color.h"
#include "TilesManager.h"
#include "PlayerManager.h"
#include "SpikesManager.h"
#include "MenuManager.h"
#include "ScoreManager.h"

extern ScoreManager score;
extern MenuManager menu;
extern SpikesManager spikes;
extern PlayerManager player;
extern TilesManager tiles;
void iG::iDraw()
{
	iClear();
	switch (menu.getMenu())
	{
	case MenuManager::PLAY:
		menu.drawPlayGame();
		break;
	case MenuManager::MAIN:
		menu.drawMainMenu();
		break;
	case MenuManager::GAMEOVER:
		menu.drawGameOver();
		break;
	case MenuManager::SCORE:
		score.drawBoard();
		break;
	}
	
}
