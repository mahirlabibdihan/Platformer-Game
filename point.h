#ifndef __POINT__
#define __POINT__
class Point {
protected:
	float x, y;
public:
	Point();
	Point(float x, float y);
	float getX();
	float getY();
	void setPoint(float x, float y);
	void setX(float x);
	void setY(float y);
	void changeX(float x);
	void changeY(float y);
};
#endif