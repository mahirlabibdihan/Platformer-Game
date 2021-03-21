#include "CameraManager.h"
#include "PlayerManager.h"

extern PlayerManager player;
CameraManager::CameraManager()
{

}
void CameraManager::init()
{
	setPoint(player.getX(), player.getY());
	row = player.getRow();
	col = player.getCol();
}
void CameraManager::update()
{
	setPoint(player.getX(), player.getY());
	row = player.getRow();
	col = player.getCol();
}
float CameraManager::getRow()
{
	return row;
}
float CameraManager::getCol()
{
	return col;
}