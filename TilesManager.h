#ifndef __TILES_MANAGER__
#define __TILES_MANAGER__
#include "GameManager.h"
#include "Tile.h"
#include "Box.h"
class TilesManager
{
	Tile** tilesField;
	int rows, cols;
	int width, height;
	int visibleRows, visibleCols;
	
public:
	float offsetRows, offsetCols;
	float tileOffsetX, tileOffsetY;
	TilesManager();
	void setField();
	char getCell(int, int);
	void setCell(int, int, char);
	char getCellXY(int, int);
	void draw();
	int getRows();
	int getCols();
	int getWidth();
	int getHeight();
	void init();
};
#endif
