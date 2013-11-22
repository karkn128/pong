#include "console.h"
#include <string>
class Paddle{
public:
	Paddle(Console *c);
	void drawPaddle();
	void moveLeft();
	void moveRight();


private:
	Console *console;
	const std::string paddle;
	int height;
	int width;
};
