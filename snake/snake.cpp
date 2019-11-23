#include "Snake.h"
#include "UserProcessing.h"

void Snake::goToXY(int x, int y)
{

	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}




int Snake::getX()
{
	return x;
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
	return true;
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

void Snake::setGameOver(int gameOver)
{
	this->gameOver = gameOver;
}

Snake::Snake(int width, int height)
{
	x = rand() % width;
	y = rand() % height;
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
		myMap->setFruitX(rand() % myMap->getWidth());
		myMap->setFruitX(rand() % myMap->getHeight());
		nTail += 1;
	}
}



Snake::~Snake()
{
}

int main()
{
	//goToXY(1, 1);
	//std::cout << "Hello World!\n";
	//UserProcessing userProcessing;
	Snake snake(100, 100);
	std::cout << snake.getX();
	snake.setX(snake.getX() + 1);
	std::cout << snake.getX();
		//goToXY(5, 1);
	//std::cout << "Hello World!\n";
	return 0;
}

