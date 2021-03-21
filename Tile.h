#include "GameManager.h"
#include "Box.h"
class Tile:public Box {
	char type;
public:
	Tile();
	void setType(char);
	char getType();
	void draw();
};