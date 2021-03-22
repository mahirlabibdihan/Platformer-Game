#ifndef __TILES_MANAGER__
#define __TILES_MANAGER__
#include "GameManager.h"
#include "Tile.h"
#include "Box.h"
class TilesManager
{
	Tile** tilesField;
	int width, height;	// Of a single tile
	int rows, cols;		// Total in a level
	int visibleRows, visibleCols;	// Visible in screen
	
public:
	float offsetRows, offsetCols;
	float tileOffsetX, tileOffsetY;
	TilesManager();
	void set();
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
