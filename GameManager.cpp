#include "GameManager.h"
#include "LevelManager.h"
#include "TilesManager.h"
#include "CameraManager.h"
#include "PlayerManager.h"
#include "ScoreManager.h"
#include "MenuManager.h"

extern MenuManager menu;
extern ScoreManager score;
extern PlayerManager player;
extern CameraManager camera;
extern LevelManager level;
extern TilesManager tiles;
GameManager::GameManager()
{

}
void GameManager::init()
{
	level.init();
	tiles.init();
	player.init();
	camera.init();
}
void GameManager::set()
{
	if (level.levelUp())
	{
		level.set();  
		tiles.set();
		player.set();
		camera.set();
	}
	else
	{
		menu.set(MenuManager::GAMEOVER);
	}
}

void GameManager::reset()
{
	score.reset();
	player.reset();
}
