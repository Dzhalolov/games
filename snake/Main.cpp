#include "Snake.h"

int main()
{
	//goToXY(1, 1);
	//std::cout << "Hello World!\n";
	//UserProcessing userProcessing;
	//Snake snake(100, 100);
	//std::cout << snake.getX();
	//snake.setX(snake.getX() + 1);
	//std::cout << snake.getX();
	//goToXY(5, 1);
	//std::cout << "Hello World!\n";
	mapBig* firstMap = new mapBig();
	//Snake* mySnake = new Snake(firstMap->getWidth, firstMap->getHeight);
	Snake* mySnake = new Snake(10, 10);
	while (!mySnake->getGameOver())
		firstMap->draw(*mySnake);
		
	return 0;
}