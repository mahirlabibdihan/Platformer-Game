#include "LevelManager.h"
LevelManager::LevelManager()
{
	levelNum = totalLevels = 0;
	levelField = NULL;
}
LevelManager::~LevelManager()
{
	for (int i = 0; i < levelHeight; i++)
	{
		delete[] levelField[i];
	}
	delete[] levelField;
}
void LevelManager::setTotalLevels(int n)
{
	totalLevels = n;
}
void LevelManager::load()
{
	ifstream in(levels[levelNum], ios::in);
	if (!in)
	{
		cout << "File Reading error" << endl;
		return;
	}
	in >> levelHeight >> levelWidth;
	in >> startR >> startC;
	in >> endR >> endC;
	levelField = new char* [levelHeight];
	for (int i = 0; i < levelHeight; i++)
	{
		levelField[i] = new char[levelWidth];
	}

	for (int i = levelHeight - 1; i > -1; i--)
	{
		in.ignore(10, '\n');
		for (int j = 0; j < levelWidth; j++)
		{
			in >> levelField[i][j];
			cout << levelField[i][j] << " ";
		}
		cout << endl;
	}
	in.close();
}
int LevelManager::getWidth()
{
	return levelWidth;
}
int LevelManager::getHeight()
{
	return levelHeight;
}
bool LevelManager::levelUp()
{
	if(levelNum <totalLevels)
	{
		levelNum++;
		return true;
	}
	return false;
}
char LevelManager::get(int row,int col)
{
	return levelField[row][col];
}
void LevelManager::set(int row,int col, char c)
{
	levelField[row][col]=c;
}

int LevelManager::getStartR()
{
	return startR;
}
int LevelManager::getStartC()
{
	return startC;
}
int LevelManager::getEndR()
{
	return endR;
}
int LevelManager::getEndC()
{
	return endC;
}