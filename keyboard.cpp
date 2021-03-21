#include "GameManager.h"
#include "PlayerManager.h"
#include "CameraManager.h"

extern CameraManager camera;
extern PlayerManager player;

void iG::iKeyboard(unsigned char key)
{
	switch (key)
	{
		case 'q':
			glutLeaveMainLoop();
			break;
	}
}

void iG::iSpecialKeyboard(unsigned char key)
{
	switch (key)
		{
		case GLUT_KEY_UP:
			player.moveUp();
			break;
		case GLUT_KEY_DOWN:
			player.moveDown();
			break;
		case GLUT_KEY_LEFT:
			player.moveLeft();
			break;
		case GLUT_KEY_RIGHT:
			player.moveRight();
			break;
		}
}
