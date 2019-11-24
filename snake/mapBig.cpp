#include "mapBig.h"
void mapBig::draw(Snake& mySnake)
{
	
	system("cls");
	for (int i = 0; i < width+1; i++)
		std::cout << "#";
	std::cout << std::endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
				std::cout << "#";
			if (i == mySnake.y && j == mySnake.x)
				std::cout << "0";
			else if (i == fruitY && j == fruitX)
				std::cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < mySnake.nTail; k++)
				{
					if (mySnake.tailX[k] == j && mySnake.tailY[k] == i)
					{
						print = true;
						std::cout << 'o';
					}
				}
				if (!print)
					std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < width + 1; i++)
		std::cout << "#";
	std::cout << std::endl;
	std::cout << "Score: " << score;
	mySnake.logic();
	UserProcessing::instance().condition(&mySnake);
	returnBounds(&mySnake);
	mySnake.checkTail(this);
}

void mapBig:: returnBounds(Snake* mySnake)
{
	if (mySnake->getX() >= width - 1)
		mySnake->setX(0);
	else if (mySnake->getX() < 0)
		mySnake->setX(width - 1);
	if (mySnake->getY() >= height)
		mySnake->setY(0);
	else if (mySnake->getY() < 0)
		mySnake->setY(height - 2);

}


void mapBig::indicatedPoint(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool mapBig::checkSnake(int x, int y)
{
	return false;
}

mapBig::mapBig()
{

}

void mapBig::randomGeneratorOfFruits()
{
}

int mapBig::getWidth()
{
	return width;
}

int mapBig::getHeight()
{
	return height;
}

int mapBig::getFruitX()
{
	return fruitX;
}

int mapBig::getFruitY()
{
	return fruitY;
}

int mapBig::getScore()
{
	return score;
}

void mapBig::setWidth(int width)
{
	this->width = width;
}

void mapBig::setHeight(int height)
{
	this->height = height;
}

void mapBig::setFruitX(int fruitX)
{
	this->fruitX = fruitX;
}

void mapBig::setFruitY(int fruitY)
{
	this->fruitY = fruitY;
}

void mapBig::setScore(int score)
{
	this->score = score;
}
