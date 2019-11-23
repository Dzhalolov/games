#include "UserProcessing.h"
#include <iostream>



void UserProcessing::condition(Snake* mySnake)
{
	checkKnock(dir);
	if (dir!= UserProcessing::eDirection::STOP)
	{
		changePosition(dir, mySnake);
	}
}

void UserProcessing::changePosition(eDirection dir, Snake* mySnake)
{
	
	switch (dir)
	{
	case LEFT:
		mySnake->setX(mySnake->getX()-1);
		break;
	case RIGHT:
		mySnake->setX(mySnake->getX() + 1);
		break;
	case UP:
		mySnake->setY(mySnake->getY() - 1);
		break;
	case DOWN:
		mySnake->setY(mySnake->getY() + 1);
		break;
	}
}

void UserProcessing::checkKnock(UserProcessing::eDirection &dir)
{
	if (_kbhit())
	{
		switch (_getch())
		{ 
		case 'a':
			dir = UserProcessing::eDirection::LEFT;
			break;
		case 'd':
			dir =  UserProcessing::eDirection::RIGHT;
			break;
		case 'w':
			dir =  UserProcessing::eDirection::UP;
			break;
		case 's':
			dir = UserProcessing::eDirection::DOWN;
			break;
		case 'x':
			dir = UserProcessing::eDirection::STOP;
		}
	}
	
}
