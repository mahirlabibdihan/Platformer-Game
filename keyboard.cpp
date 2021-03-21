#include "GameManager.h"
#include "PlayerManager.h"
#include "CameraManager.h"
#include "MenuManager.h"
#include "ScoreManager.h"

extern ScoreManager score;
extern MenuManager menu;
extern CameraManager camera;
extern PlayerManager player;

void iG::iKeyboard(unsigned char key)
{
	switch (menu.getMenu())
	{
	case MenuManager::MAIN:
		switch (key)
		{
		case 'q':
			glutLeaveMainLoop();
			break;
		case '\r':
			menu.keyEnter();
			break;
		}
		break;
	case MenuManager::PLAY:
		switch (key)
		{
		case '\b':
			menu.setMenu(MenuManager::MAIN);
			break;
		}
		break;
	case MenuManager::SCORE:
		switch (key)
		{
		case '\b':
			menu.setMenu(MenuManager::MAIN);
			break;
		}
		break;
	case MenuManager::GAMEOVER:
		score.nameEntry(key);
		break;
	}
	cout << "Menu:" << menu.getMenu() << endl;
}

void iG::iSpecialKeyboard(unsigned char key)
{
	switch (menu.getMenu())
	{
	case MenuManager::MAIN:
		switch (key)
		{
		case GLUT_KEY_UP:
			menu.keyUp();
			break;
		case GLUT_KEY_DOWN:
			menu.keyDown();
			break;
		}

	case MenuManager::PLAY:
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
		case GLUT_KEY_END:
			menu.setMenu(MenuManager::MAIN);
			break;
		}
		break;
	}
	
}
