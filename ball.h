#ifndef BALL_H
#define BALL_H

#include "console.h"
#include "paddle.h"
#include <random>

class Ball{

public:
	Ball(Console &c, Paddle &p, bool &gameOver);
	void drawBall();
	void move();
	void collide();

private:
	char ball;
	Console &console;
	Paddle &paddle;
	bool &gameOver;
	unsigned int x;
	unsigned int y;
	int dirX;
	int dirY;
};
#endif
