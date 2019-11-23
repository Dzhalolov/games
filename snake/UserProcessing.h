#pragma once
#ifndef _USERPROCESSING_H_
#define _USERPROCESSING_H_ 

#include <conio.h>
#include "Snake.h"
class UserProcessing
{
	enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
	eDirection dir = STOP;//check how does it work

public:
	UserProcessing();
	friend eDirection checkKnock(eDirection dir);

public:
	void changePosition(eDirection dir, Snake* mySnake);

};
#endif // !_USERPROCESSING_H_


