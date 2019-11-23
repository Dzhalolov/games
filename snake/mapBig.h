#pragma once
#ifndef _MAPBIG_H_
#define _MAPBIG_H_


#include "Snake.h"
#include "UserProcessing.h"
class Snake;
class mapBig: private map
{
public:
	int getWidth() override;
	int getHeight() override;
	int getFruitX() override;
	int getFruitY() override;
	int getScore() override;
	void setWidth(int width) override;
	void setHeight(int height) override;
	void setFruitX(int fruitX) override;
	void setFruitY(int fruitY) override;
	void setScore(int score) override;
	void draw(Snake& mySnake);
	void returnBounds(Snake* mySnake);
	void indicatedPoint(int x, int y) override;
	bool checkSnake(int x, int y) override;
	mapBig();
	void randomGeneratorOfFruits() override;
};
#endif // !_MAPBIG_H_

