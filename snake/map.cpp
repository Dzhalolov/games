#include <Windows.h>
class map
{
protected:
	int width;
	int height;
	int fruitX, fruitY;
	int score;
public:
	map()
	{
		width = 200;
		height = 300;
		randomGeneratorOfFruits();
		score = 0;
	}
	virtual void draw() = 0;
	virtual void indicatedPoint(int x, int y) = 0;
	virtual bool checkSnake(int x, int y) = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual int getFruitX() = 0;
	virtual int getFruitY() = 0;
	virtual int getScore() = 0;
	virtual void setWidth(int width) = 0;
	virtual void setHeight(int height) = 0;
	virtual void setFruitX(int fruitX) = 0;
	virtual void setFruitY(int fruitY) = 0;
	virtual void setScore(int score) = 0;
	virtual void randomGeneratorOfFruits()
	{
		fruitX = rand() % width;
		fruitX = rand() % height;
	}
};