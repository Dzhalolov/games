#pragma once
#ifndef _USERPROCESSING_H_
#define _USERPROCESSING_H_ 

#include <conio.h>
#include "Snake.h"
class Snake;
class UserProcessing
{
	enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
	eDirection dir = STOP;//check how does it work
	UserProcessing() {}                               // Private constructor
	~UserProcessing() {}
	UserProcessing(const UserProcessing&);                 // Prevent copy-construction
	UserProcessing& operator=(const UserProcessing&);
//	~UserProcessing();
public:
	/*if (dir = checkKnock(dir))
	{
		Snake* mySnake = new Snake(100, 100);
		changePosition(dir, mySnake);
	}*/
	static UserProcessing& instance()
	{
		static UserProcessing inst;
		return inst;
	}
public:
	void changePosition(eDirection dir, Snake* mySnake);
	void checkKnock(UserProcessing::eDirection& dir);
	void condition(Snake* mySnake);
};
#endif // !_USERPROCESSING_H_


