#include "wall.h"

Wall::Wall(Console *c) : console(c)
{

}

void Wall::fill(){
	//+ signs in both top corners
	console->setPos(0, 0);
	console->put('+');
	console->setPos(console->getWidth()-1, 0);
	console->put('+');
	//+ signs in both bottom corners
	console->setPos(0, console->getHeight()-1);
	console->put('+');
	console->setPos(console->getWidth()-1, console->getHeight()-1);
	console->put('+');

	//Lines on both sides corners not included
	for(int i = 1; i != console->getHeight()-1; ++i){
		console->setPos(0, i);
		console->put('|');
		console->setPos(console->getWidth()-1, i);
		console->put('|');
	}
	//Lines on top and bottom corners not included
	for(int i = 1; i != console->getWidth()-1; ++i){
		console->setPos(i, 0);
		console->put('-');
		console->setPos(i, console->getHeight()-1);
		console->put('-');

	}
}
