#include "GameManager.h"
#include "PlayerManager.h"
#include "MenuManager.h"
#include "ScoreManager.h"

extern ScoreManager score;
extern MenuManager menu;
extern PlayerManager player;

int sides = 3;
void iG::iKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	{
		switch (menu.get())
		{
		case MenuManager::MAIN:
			if (action == GLFW_PRESS)
			{
				switch (key)
				{
				case GLFW_KEY_UP:
					menu.keyUp();
					break;
				case GLFW_KEY_DOWN:
					menu.keyDown();
					break;
				case GLFW_KEY_Q:
					// glutLeaveMainLoop();
					exit(0);
					break;
				case GLFW_KEY_ENTER:
					cout << "Enter" << endl;
					menu.keyEnter();
					break;
				}
			}
			break;

		case MenuManager::PLAY:
			switch (key)
			{
			case GLFW_KEY_UP:
				player.moveUp();
				break;
			case GLFW_KEY_DOWN:
				player.moveDown();
				break;
			case GLFW_KEY_LEFT:
				player.moveLeft();
				break;
			case GLFW_KEY_RIGHT:
				player.moveRight();
				break;
			case GLFW_KEY_END:
				menu.set(MenuManager::MAIN);
				break;
			case GLFW_KEY_BACKSPACE:
				menu.set(MenuManager::MAIN);
				break;

			}
			break;
		case MenuManager::SCORE:
			switch (key)
			{
			case GLFW_KEY_UP:
				score.keyUp();
				break;
			case GLFW_KEY_DOWN:
				score.keyDown();
				break;
			}
		}
	}


	/*
	if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (sides < 100)	sides++;
	}
	else if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (sides > 3) sides--;
	}
	*/
	/*
	switch (menu.get())
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
			menu.set(MenuManager::MAIN);
			break;
		}
		break;
	case MenuManager::SCORE:
		switch (key)
		{
		case '\b':
			menu.set(MenuManager::MAIN);
			break;
		case 'd':
			score.erase();
			break;
		case 'e':
			score.edit();
			break;
		}
		break;
	case MenuManager::GAMEOVER:
		score.nameEntry(key);
		break;
	}*/
}
/*
void iG::iSpecialKeyboard(unsigned char key)
{
	switch (menu.get())
	{
	case MenuManager::MAIN:
		switch (key)
		{
		case GLFW_KEY_UP:
			menu.keyUp();
			break;
		case GLFW_KEY_DOWN:
			menu.keyDown();
			break;
		}

	case MenuManager::PLAY:
		switch (key)
		{
		case GLFW_KEY_UP:
			player.moveUp();
			break;
		case GLFW_KEY_DOWN:
			player.moveDown();
			break;
		case GLFW_KEY_LEFT:
			player.moveLeft();
			break;
		case GLFW_KEY_RIGHT:
			player.moveRight();
			break;
		case GLFW_KEY_END:
			menu.set(MenuManager::MAIN);
			break;
		}
		break;
	case MenuManager::SCORE:
		switch (key)
		{
		case GLUT_KEY_UP:
			score.keyUp();
			break;
		case GLUT_KEY_DOWN:
			score.keyDown();
			break;
		}
	}
}
*/