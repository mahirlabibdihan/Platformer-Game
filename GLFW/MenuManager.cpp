#include "MenuManager.h"
#include "TilesManager.h"
#include "PlayerManager.h"
#include "SpikesManager.h"
#include "LevelManager.h"
#include "ScoreManager.h"
#include "AudioManager.h"
#include "text.h"
extern AudioManager sound;
extern ScoreManager score;
extern LevelManager level;
extern GameManager game;
extern SpikesManager spikes;
extern PlayerManager player;
extern TilesManager tiles;

MenuManager::MenuManager()
{
	menuName = MAIN;
	option = PLAY_GAME;
}

void MenuManager::init()
{
	bgImage.init("Data\\Image\\img_mars.jpg",false);	
}
GLint MenuManager::get()
{
	return menuName;
}
void MenuManager::set(menus n)
{
	menuName = n;
}
void MenuManager::drawPlayGame()
{
	bgImage.draw(0, 0, iG::iGetWindowWidth(), iG::iGetWindowHeight());
	tiles.draw();
	player.draw();
	spikes.draw();
	score.draw();
	player.drawLife();
	level.draw();
	game.drawTime();
}
void MenuManager::drawGameOver()
{
	bgImage.draw(0, 0, iG::iGetWindowWidth(), iG::iGetWindowHeight());
	iG::iSetColor(100, 100, 100, 0.5);
	iG::iRectangle(iG::iGetWindowWidth() / 2 - 650, iG::iGetWindowHeight() / 2 - 90, 1300, 180);
	glPushMatrix();
	glTranslatef(iG::iGetWindowWidth() / 2 - 300, iG::iGetWindowHeight() / 2 - 200, 0.0f);
	glScalef(0.5f, 0.5f, 1.0f);
	iG::iSetColor(BLACK);
	Text::render(0, 0, "ENTER YOUR NAME");
	glPopMatrix();

	score.drawGameOver();

}
void MenuManager::keyDown()
{
	if (option >= QUIT_GAME)
	{
		option = PLAY_GAME;
	}
	else if (option == PLAY_GAME)
	{
		option = SCORE_BOARD;
	}
	else
	{
		option = QUIT_GAME;
	}
}
void MenuManager::keyUp()
{
	if (option == PLAY_GAME)
	{
		option = QUIT_GAME;
	}
	else if (option == SCORE_BOARD)
	{
		option = PLAY_GAME;
	}
	else
	{
		option = SCORE_BOARD;
	}
}
void MenuManager::keyEnter()
{
	if (option == PLAY_GAME)
	{
		sound.play("Data/Music/Background.wav", true);
		menuName = PLAY;
		game.reset();
		game.set();
	}
	else if (option == SCORE_BOARD)
	{
		menuName = SCORE;
	}
	else
	{
		exit(0);
		// glutLeaveMainLoop();
	}
}
void MenuManager::drawMainMenu()
{
	bgImage.draw(0, 0, iG::iGetWindowWidth(), iG::iGetWindowHeight());
	if (option == PLAY_GAME)
	{
		iG::iSetColor(100,100,100,0.5);
		iG::iRectangle(iG::iGetWindowWidth() / 2.0f - 400, iG::iGetWindowHeight() / 2.0f + 150, 800.0f, 180.0f);
	}
	iG::iSetColor(BLACK);
	Text::render(iG::iGetWindowWidth() / 2.0f - 350, iG::iGetWindowHeight() / 2.0f + 200, "Play Game");



	if (option == SCORE_BOARD)
	{
		iG::iSetColor(100, 100, 100, 0.5);
		iG::iRectangle(iG::iGetWindowWidth() / 2.0f - 450, iG::iGetWindowHeight() / 2.0f - 100, 900.0f, 180.0f);
	}
	iG::iSetColor(BLACK);
	Text::render(iG::iGetWindowWidth() / 2.0f - 400, iG::iGetWindowHeight() / 2.0f - 50, "Score Board");



	if (option == QUIT_GAME)
	{
		iG::iSetColor(100, 100, 100, 0.5);
		iG::iRectangle(iG::iGetWindowWidth() / 2.0f - 400, iG::iGetWindowHeight() / 2.0f - 350, 800, 180);
	}
	iG::iSetColor(BLACK);
	Text::render(iG::iGetWindowWidth() / 2.0f - 350, iG::iGetWindowHeight() / 2.0f - 300, "Quit Game");
}
void MenuManager::drawScoreBoard()
{
	bgImage.draw(0, 0, iG::iGetWindowWidth(), iG::iGetWindowHeight());
	score.drawBoard();
}