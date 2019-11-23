#pragma once
#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <iostream>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include "map.cpp"

class Snake
{
	friend class mapBig;
	friend class map;
//friend Map I think it's make sense
	int x, y;
	int nTail;
	bool gameOver;
	int maxTail;
	int* tailX = new int[maxTail];
	int* tailY = new int[maxTail];
	void goToXY(int x, int y);//dublicate of funtion with class map, i'm not sure about function place:(
public:
	int getX();
	int getY();
	int getNTail();
	int getMaxTail();
	bool getGameOver();
	void setX(int x);
	void setY(int y);
	void setNTail(int nTail);
	void setMaxTail(int maxTail);
	void setGameOver(int gameOver);
	Snake(int, int);
	void logic();
	void startCondition();
	void checkTail(map *myMap);
	~Snake();
};
#endif //!_SNAKE_H_
