#include "TilesManager.h"
#include "LevelManager.h"
#include "CameraManager.h"
#include "GameManager.h"
#include "SpikesManager.h"

extern SpikesManager spikes;
extern GameManager game;
extern CameraManager camera;
extern LevelManager level;
TilesManager::TilesManager()
{
	rows = cols = 0;
	width = 70;
	height = 70;
	tileOffsetX = tileOffsetY = 0;
	tilesField = NULL;
}

void TilesManager::draw()
{
	offsetCols = camera.getX()/width- visibleCols / 2.0f;
	offsetRows = camera.getY()/height - visibleRows / 2.0f;

	if (offsetCols < 0) offsetCols = 0;
	if (offsetRows < 0) offsetRows = 0;
	if (offsetCols > cols - visibleCols) offsetCols = cols - visibleCols;
	if (offsetRows > rows - visibleRows) offsetRows = rows - visibleRows;

	tileOffsetX = (offsetCols - (int)offsetCols) * width;
	tileOffsetY = (offsetRows - (int)offsetRows) * height;

	for (int i = 0; i <= visibleRows+1 && i + offsetRows < rows; i++)
	{
		for (int j = 0; j <= visibleCols+1 && j + offsetCols < cols; j++)
		{
			if (tilesField[int(i + offsetRows)][int(j + offsetCols)].getType() == '.')
			{
			
			}
			else if (tilesField[int(i + offsetRows)][int(j + offsetCols)].getType() == 'o')
			{
				cout << "COIN" << endl;
				iG::iSetColor(YELLOW);
				iG::iCircle(j * width - tileOffsetX + width / 2, i * height - tileOffsetY + height / 2, width / 2);
			}
			else
			{
				iG::iSetColor(BLACK);
				iG::iRectangle(j * width - tileOffsetX, i * height - tileOffsetY, width, height);
			}
		}
	}
}

void TilesManager::init()
{
	visibleRows = iG::iGetWindowHeight() / height;
	visibleCols = iG::iGetWindowWidth() / width;
}
void TilesManager::setField()
{
	spikes.clear();
	rows = level.getHeight();
	cols = level.getWidth();
	tilesField = new Tile * [rows];
	for (int i = 0; i < rows; i++)
	{
		tilesField[i] = new Tile[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (level.get(i, j) == 'x')
			{
				spikes.addSpike(j * width, i * height);
			}
			else
			{
				tilesField[i][j].setType(level.get(i, j));
				if (level.get(i, j) == '.')
					tilesField[i][j].setColor(GREEN);
				else if (level.get(i, j) == 'o')
					tilesField[i][j].setColor(YELLOW);
				else
					tilesField[i][j].setColor(BLACK);
			}
		}
	}
}

char TilesManager::getCell(int row, int col)
{
	if (row <rows && row >-1 && col <cols && col >-1)
		return tilesField[row][col].getType();
	else
		return '#';
}

void TilesManager::setCell(int row, int col,char c)
{
	
	if (row <rows && row >-1 && col <cols && col >-1)
		tilesField[row][col].setType(c);
}


char TilesManager::getCellXY(int x, int y)
{
	if (y / height > -1 && y / height <rows && x / width >-1 && x / width < cols)
		return tilesField[y / height][x / width].getType();
	else
		return ' ';
}

int TilesManager::getWidth()
{
	return width;
}
int TilesManager::getHeight()
{
	return height;
}

int TilesManager::getRows()
{
	return rows;
}
int TilesManager::getCols()
{
	return cols;
}