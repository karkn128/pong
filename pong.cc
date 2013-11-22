#include <iostream>
#include "console.h"
#include "paddle.h"
#include "ball.h"
using namespace std;

void fill(Console &console){
	//+ signs in both top corners
	console.setPos(0, 0);
	console.put('+');
	console.setPos(console.getWidth()-1, 0);
	console.put('+');
	//+ signs in both bottom corners
	console.setPos(0, console.getHeight()-1);
	console.put('+');
	console.setPos(console.getWidth()-1, console.getHeight()-1);
	console.put('+');

	//Lines on both sides corners not included
	for(int i = 1; i != console.getHeight()-1; ++i){
		console.setPos(0, i);
		console.put('|');
		console.setPos(console.getWidth()-1, i);
		console.put('|');
	}
	//Lines on top and bottom corners not included
	for(int i = 1; i != console.getWidth()-1; ++i){
		console.setPos(i, 0);
		console.put('-');
		console.setPos(i, console.getHeight()-1);
		console.put('-');

	}
}

int main() {
	Console console;

	fill(console);

	Paddle paddle(console);
	Ball ball(console, paddle, game_over);
	bool game_over = false;
	char command;
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
