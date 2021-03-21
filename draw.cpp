#include "GameManager.h"
#include "color.h"
#include "TilesManager.h"
#include "PlayerManager.h"
#include "SpikesManager.h"

extern SpikesManager spikes;
extern PlayerManager player;
extern TilesManager tiles;
void iG::iDraw()
{
	iClear();
	tiles.draw();
	player.draw();
	spikes.draw();
}
