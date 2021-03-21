#include "GameManager.h"
#include "LevelManager.h"
#include "TilesManager.h"
#include "CameraManager.h"
#include "PlayerManager.h"
#include "ScoreManager.h"

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
	level.setTotalLevels(2);
	if (level.levelUp())
	{
		level.load();
	}

	score.reset();
	player.reset();
	player.init();
	camera.init();
	tiles.init();
	tiles.setField();
}

