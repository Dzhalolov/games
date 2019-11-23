#include "UserProcessing.h"
#include <iostream>

UserProcessing::UserProcessing()
{
	if (dir = checkKnock(dir))
	{
		Snake *mySnake = new Snake(100, 100);
		std::cout << 'u';
		changePosition(dir, mySnake);
	}
std::cout << 'u';
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
		mySnake->setX(mySnake->getX() + 1);
		break;
	case DOWN:
		mySnake->setX(mySnake->getX() + 1);
		break;
	}
}

UserProcessing::eDirection checkKnock(UserProcessing::eDirection dir)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			return UserProcessing::eDirection::LEFT;
		case 'd':
			return UserProcessing::eDirection::RIGHT;
		case 'w':
			return UserProcessing::eDirection::UP;
		case 's':
			return UserProcessing::eDirection::DOWN;
		case 'x':
			return UserProcessing::eDirection::STOP;
		}
	}
	
}
