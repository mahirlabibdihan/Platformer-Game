#include "Tile.h"
Tile::Tile()
{
	this->type = '.';
}
void Tile::draw()
{
	iG::iSetColor(getColor());
	iG::iRectangle(getX(), getY(), getWidth(), getHeight());
}

void Tile::setType(char c)
{
	this->type = c;
}
char Tile::getType()
{
	return type;   
}    