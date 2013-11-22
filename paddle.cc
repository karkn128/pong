#include "paddle.h"
#include <string>

Paddle::Paddle(Console &c) : console(c), paddle("o----------o")
{
	height = console.getHeight() - (console.getHeight() / 4);
	width = (console.getWidth() / 2) - paddle.size();
}

unsigned int Paddle::getY(){
	return height;
}

unsigned int Paddle::getX(){
	return width;
}

unsigned int Paddle::length(){
	return paddle.size();
}

void Paddle::drawPaddle(){

	for(int i = 1; i != console.getWidth()-1; i++){
		console.setPos(i, height);
		console.put(' ');
	}
	console.setPos(width, height);
	console.put(paddle);

}

void Paddle::moveLeft(){
	if(width > 1)
		width--;
}

void Paddle::moveRight(){
	if((width + paddle.size()) < (unsigned int) console.getWidth()-1)
		width++;
}

