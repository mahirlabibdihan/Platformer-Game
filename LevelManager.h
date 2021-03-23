#ifndef __LEVEL_MANAGER__
#define __LEVEL_MANAGER__
#include "GameManager.h"
class LevelManager
{
	int levelNum,totalLevels;
	int cols,rows;

	// Starting and ending position of a level
	int startR, startC, endR, endC;


	char** levelField;
	string levels[3]=
	{
		"",
		"Data\\Levels\\Level1.txt",
		"Data\\Levels\\Level2.txt"
	};
public:
	LevelManager();
	~LevelManager();
	void init();
	void set();
	void setTotalLevels(int);
	int getCols();
	int getRows();
	int getStartR();
	int getStartC();
	int getEndR();
	int getEndC();
	bool levelUp();
	char getCell(int,int);
	void draw();
	void reset();
};
#endif