#include "GameManager.h"
#include "LevelManager.h"
#include "TilesManager.h"
#include "CameraManager.h"
#include "PlayerManager.h"

extern PlayerManager player;
extern CameraManager camera;
extern LevelManager level;
extern TilesManager tiles;
GameManager::GameManager()
{
	score = 0;
}
void GameManager::init()
{
	level.setTotalLevels(2);
	if (level.levelUp())
	{
		level.load();
	}
	player.init();
	camera.init();
	tiles.init();
	tiles.setField();
}
void GameManager::scoreUp()
{
	score += 10;
}