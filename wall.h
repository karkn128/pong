#include "console.h"

class Wall{
public:
	Wall(Console *c);
	void fill();

private:
	Console *console;
};
