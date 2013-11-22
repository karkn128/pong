#ifndef PADDLE_H
#define PADDLE_H

#include "console.h"
#include <string>
class Paddle{
public:
	Paddle(Console &c);
	void drawPaddle();
	void moveLeft();
	void moveRight();
	unsigned int getY() const;
	unsigned int getX() const;
	unsigned int length() const;


private:
	Console &console;
	const std::string paddle;
	unsigned int height;
	unsigned int width;
};

#endif
