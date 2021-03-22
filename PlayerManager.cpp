#include "PlayerManager.h"
#include "TilesManager.h"
#include "Color.h"
#include "GameManager.h"
#include "SpikesManager.h"
#include"LevelManager.h"
#include "ScoreManager.h"
#include "MenuManager.h"
#include "CameraManager.h"


extern CameraManager camera;
extern PlayerManager player;
extern MenuManager menu;
extern ScoreManager score;
extern LevelManager level;
extern SpikesManager spikes;
extern GameManager game;
extern TilesManager tiles;
PlayerManager::PlayerManager()
{
	life = 3;
	velX = velY = 0;
	row = col = 0;
	newX = newY = 0;
	onGround = true;
	this->setPoint(0, 0);
	this->setColor(RED);
}
void PlayerManager::update()
{
	if (velX > 15.0f) velX = 10.0f;
	if (velX < -15.0f) velX = -10.0f;

	if (velY < -100.0f) velY = -100.0f;

	moveDown();

	newX = round(x + velX);
	newY = round(y + velY);

	if (onGround)
	{
		velX *= .9;
	}

	if (fabs(velX) < .1) velX = 0;

	cout << newX << endl;



	if (velY < 0)
	{
		if (tiles.getCell(floor(newY / height), floor(x / width)) == '#' || tiles.getCell(floor(newY / height), ceil(x / width)) == '#')
		{
			newY = floor(y / height) * height;
			velY = 0;
			onGround = true;
		}
	}

	if (velY > 0)
	{
		if (tiles.getCell(ceil(newY / height), floor(x / width)) == '#' || tiles.getCell(ceil(newY / height), ceil(x / width)) == '#')
		{
			newY = ceil(y / height) * height;
			velY = -.1;
		}
	}

	if (velX > 0)
	{
		if (tiles.getCell(floor(newY / height), ceil(newX / width)) == '#' || tiles.getCell(ceil(newY / height), ceil(newX / width)) == '#')
		{
			newX = ceil(x / width) * width;
			velX = 0;
		}
	}
	if (velX < 0)
	{
		if (tiles.getCell(floor(newY / height), floor(newX / width)) == '#' || tiles.getCell(ceil(newY / height), floor(newX / width)) == '#')
		{
			newX = floor(x / width) * width;
			velX = 0;
		}
	}
	if (tiles.getCell(floor(newY / height), floor(newX / width)) == 'o')
	{
		tiles.setCell(floor(newY / height), floor(newX / width), '.');
		score.increase();
	}

	if (tiles.getCell(floor(newY / height), ceil(newX / width)) == 'o')
	{
		tiles.setCell(floor(newY / height), ceil(newX / width), '.');
		score.increase();
	}

	if (tiles.getCell(ceil(newY / height), floor(newX / width)) == 'o')
	{
		tiles.setCell(ceil(newY / height), floor(newX / width), '.');
		score.increase();
	}

	if (tiles.getCell(ceil(newY / height), ceil(newX / width)) == 'o')
	{
		tiles.setCell(ceil(newY / height), ceil(newX / width), '.');
		score.increase();
	}
	x = newX;
	y = newY;
	if (spikes.checkCollision())
	{
		set();
		life--;
	}
	if (!life)
	{
		menu.set(MenuManager::GAMEOVER);
	}
	if (x == endC * width && y == endR * height)
	{
		game.set();
	}

}
void PlayerManager::init()
{	
	this->setHeight(tiles.getHeight());
	this->setWidth(tiles.getWidth());
}

void PlayerManager::set()
{
	this->setStart(level.getStartR(), level.getStartC());
	this->setEnd(level.getEndR(), level.getEndC());
	newX = x = startC * height;
	newY = y = startR * width;
}
void PlayerManager::reset()
{
	life = 3;
	velX = velY = 0;
	x = y = newX = newY = 0;
	onGround = true;
}

void PlayerManager::setStart(int row, int col)
{
	startR = row;
	startC = col;
}
void PlayerManager::setEnd(int row, int col)
{
	endR = row;
	endC = col;
}
void PlayerManager::setPosition(float row, float col)
{
	newX = x = col * height;
	newY = y = row * width;
}
void PlayerManager::moveUp()
{
	if (velY == 0 && onGround)
	{
		velY = 22.0f;
		onGround = false;
	}
}
void PlayerManager::moveDown()
{
	velY -= 1.0f;
}
void PlayerManager::moveRight()
{
	if (velY == 0)
	{
		velX += 5.0f;
	}
	else
	{
		velX += 3.0f;
	}

}
void PlayerManager::moveLeft()
{
	if (velY == 0)
	{
		velX -= 5.0f;
	}
	else
	{
		velX -= 3.0f;
	}
}

void PlayerManager::draw()
{
	iG::iSetColor(getColor());
	iG::iCircle(getX() - tiles.offsetCols * getWidth() + getWidth() / 2, getY() - tiles.offsetRows * getHeight() + getHeight() / 2, getWidth() / 2);
}

void PlayerManager::drawLife()
{
	char temp[40];
	snprintf(temp, 40, "LIFE :  %d", life);
	iG::iSetColor(RED);
	iG::iText(iG::iGetWindowWidth() - 200, iG::iGetWindowHeight() - 100, temp);

}
float PlayerManager::getRow()
{
	return row;
}
float PlayerManager::getCol()
{
	return col;
}