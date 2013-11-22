#include "ball.h"
#include "paddle.h"
#include <random>

Ball::Ball(Console &c, Paddle &p, bool &gameOver) : console(c), paddle(p), gameOver(gameOver)
{
	std::random_device ranDevice;
	std::uniform_int_distribution<int> distr(0, 1);
	ball = 'O';

	if(distr(ranDevice) == 0)
		dirX = -1;
	else
		dirX = 1;
	if(distr(ranDevice) == 0)
		dirY = -1;
	else
		dirY = 1;
	std::uniform_int_distribution<int> distriX(0, console.getWidth()-1);
	y = 10;
	x = distriX(ranDevice);

}

void Ball::move(){
	x += dirX;
	y += dirY;

}
void Ball::collide(){
	if(y == 1)
		dirY = 1;
	if(y == (unsigned int) console.getHeight()-2)
		gameOver = true;
	if(x == 1)
		dirX = 1;
	if(x == (unsigned int) console.getWidth()-2)
		dirX = -1;
	//If ball hits paddle
	if(y == paddle.getY()-1 && x > paddle.getX() &&  x < paddle.getX() + paddle.length())
		dirY = -1;

}

void Ball::drawBall(){
	console.setPos(x, y);
	console.put(' ');
	collide();
	move();

	console.setPos(x, y);
	console.put(ball);
}
