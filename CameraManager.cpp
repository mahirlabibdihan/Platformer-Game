#include "CameraManager.h"
#include "PlayerManager.h"

extern PlayerManager player;
CameraManager::CameraManager()
{

}
void CameraManager::set()
{
	setPoint(player.getX(), player.getY());
}
void CameraManager::init()
{
	
}
void CameraManager::update()
{
	setPoint(player.getX(), player.getY());
}
