#include "LevelManager.h"
#include "Color.h"
LevelManager::LevelManager()
{
	levelNum = totalLevels = 0;
	levelField = NULL;
}
LevelManager::~LevelManager()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] levelField[i];
	}
	delete[] levelField;
}
void LevelManager::init()
{
	totalLevels = 2;
}
void LevelManager::setTotalLevels(int n)
{
	totalLevels = n;
}
void LevelManager::set()
{
	ifstream in(levels[levelNum], ios::in);
	if (!in)
	{
		cout << "File Reading error" << endl;
		return;
	}
	in >> rows >> cols;
	in >> startR >> startC;
	in >> endR >> endC;
	levelField = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		levelField[i] = new char[cols];
	}

	for (int i = rows - 1; i > -1; i--)
	{
		in.ignore(10, '\n');
		for (int j = 0; j < cols; j++)
		{
			in >> levelField[i][j];
			cout << levelField[i][j] << " ";
		}
		cout << endl;
	}
	in.close();
}
int LevelManager::getCols()
{
	return cols;
}
int LevelManager::getRows()
{
	return rows;
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
char LevelManager::getCell(int row,int col)
{
	return levelField[row][col];
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

void LevelManager::reset()
{
	levelNum =  0;
}

void LevelManager::draw()
{
	char temp[40];
	snprintf(temp, 40, "LEVEL :  %d", levelNum);
	iG::iSetColor(RED);
	iG::iText(iG::iGetWindowWidth() - 200, iG::iGetWindowHeight() - 150, temp);
}