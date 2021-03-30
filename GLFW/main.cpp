#include "AudioManager.h"
#include "GameManager.h"
#include "PlayerManager.h"
#include "CameraManager.h"
#include "LevelManager.h"
#include "TilesManager.h"
#include "SpikesManager.h"
#include "MenuManager.h"
#include "ScoreManager.h"
#include "color.h"

AudioManager sound;
ScoreManager score;
MenuManager menu;
SpikesManager spikes;
CameraManager camera;
PlayerManager player;
GameManager game;
LevelManager level;
TilesManager tiles;
/*
void iDraw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	iG::iShowImage(0.0f, 0.0f, iG::iWindowWidth, iG::iWindowHeight, "Data/image/img_mars.jpg");
	iG::iSetColor(rand() % 256, rand() % 256, rand() % 256);
	iG::iCircle(iG::iWindowWidth / 2.0f, iG::iWindowHeight / 2.0f, 200.0f, sides);
}*/

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
	iG::iWindowWidth = width;
	iG::iWindowHeight = height;
}
void update()		// Game screen update
{
	if (menu.get() == MenuManager::PLAY)
	{
		game.incTimer();
		player.update();	// Updating Player position
		spikes.update();	// Updating Spikes position
		camera.update();	// Updating camera position
	}
	Sleep(30);
	// glutPostRedisplay();
	// glutTimerFunc(30, update, 0);
}
void iG::windowSetup()
{
	// Setting bounds of pc screen
	iG::iSetScreenHeight(GetSystemMetrics(SM_CYFULLSCREEN));
	iG::iSetScreenWidth(GetSystemMetrics(SM_CXFULLSCREEN));

	// Setting position of game window
	iG::iSetWindowX(0);
	iG::iSetWindowY(0);

	// Setting game window bounds
	iG::iSetWindowHeight(iG::iGetScreenHeight());
	iG::iSetWindowWidth(iG::iGetScreenWidth());

	// Setting window background color
	iG::iSetBGColor(GREEN);
}
int main()
{
	iG::windowSetup();
	iG::iInitialize("Bounce");
	return 0;
}

