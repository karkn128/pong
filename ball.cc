#include "ball.h"


Ball::Ball(Console *c) : console(c)
{
	ball = 'O';
}


void Ball::drawBall(){
	console->setPos(20, 10);
	console->put(ball);
}
