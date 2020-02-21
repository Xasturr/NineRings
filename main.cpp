#include "game.h"

int main()
{
	Game game;
	game.start();

	return 0;
}

/*bugs:
	-вражеский персонаж находясь на краю, заагрившись, бежит в край
	-double damage в классе Player, а не Character
*/