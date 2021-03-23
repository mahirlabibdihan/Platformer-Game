#ifndef __LEVEL_MANAGER__
#define __LEVEL_MANAGER__
#include "GameManager.h"
class LevelManager
{
	int levelNum,totalLevels;
	int cols,rows;
	
	int startR, startC, endR, endC;	// Starting and ending position of a level

	char** levelField;

	// Level text files
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
	void set();	// Reading level from file
	void reset();
	void setTotalLevels(int);
	int getCols();
	int getRows();
	int getStartR();
	int getStartC();
	int getEndR();
	int getEndC();
	bool levelUp();
	char getCell(int,int);
	void draw();	// Draw level number in top right corner of game screen
};
#endif