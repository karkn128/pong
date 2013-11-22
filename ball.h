#include "console.h"

class Ball{
public:
	Ball(Console *c);
	void drawBall();

private:
	char ball;
	Console *console;

};
