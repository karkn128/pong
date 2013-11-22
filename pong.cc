#include <iostream>
#include "console.h"
#include "wall.h"
#include "paddle.h"
#include "ball.h"
using namespace std;

int main() {
	Console console;
	char command;
	Console *cptr = &console;
	Wall wall = Wall(cptr);
	wall.fill();

	Paddle paddle{cptr};
	paddle.drawPaddle();

	Ball ball{cptr};



	bool game_over = false;
	while (!game_over){
		if (console.get(command)){
			if(command == 'a')
				paddle.moveLeft();
			if(command == 'd')
				paddle.moveRight();
			if(command == 'q')
				game_over = true;
		}
		else
		{
			paddle.drawPaddle();
			ball.drawBall();
		}
	}
}
