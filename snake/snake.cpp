#include "Snake.h"

void Snake::goToXY(int x, int y)
{

	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}




int Snake::getX()
{
	return x;
}

int Snake::getTime()
{
	return time;
}

int Snake::getY()
{
	return y;
}

int Snake::getNTail()
{
	return nTail;
}

int Snake::getMaxTail()
{
	return maxTail;
}

bool Snake::getGameOver()
{
	return gameOver;
}

void Snake::setX(int x)
{
	this->x = x;
}

void Snake::setY(int y)
{
	this->y = y;
}

void Snake::setNTail(int nTail)
{
	this->nTail = nTail;
}

void Snake::setMaxTail(int maxTail)
{
	this->maxTail = maxTail;
}

Snake::Snake(int width, int height)
{
	gameOver = false;
	maxTail = 100;
	tailX = new int[maxTail];
	tailY = new int[maxTail];
	x = rand() % (width - 1);
	y = rand() % (height - 1);
	nTail = 0;

}

void Snake::logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
}

void Snake::startCondition()
{
	gameOver = false;
	//dir = STOP;
	//x = 7;//width / 2 - 1;
	//y = 3;//height / 2 - 1;
	//fruitX = rand() % width;
	//fruitY = rand() % height;
	//score = 0;

}

void Snake::checkTail(map* myMap)
{
	for (int i = 0; i < nTail; ++i)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}
	if (x == myMap->getFruitX() && y == myMap->getFruitY())
	{
		myMap->setScore(myMap->getScore() + 10);
		myMap->setFruitX(rand() % myMap->getWidth() - 1);
		myMap->setFruitY(rand() % myMap->getHeight() - 1);
		nTail += 1;
		
		if (time)
			time -= 30;
	}
	//std::cout << myMap;
}



Snake::~Snake()
{
	delete [] tailX, tailY;
}



