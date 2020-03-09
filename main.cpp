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

//patterns:
//singleton (Engine)
//builder (Engine-Level)
//bridge (Physix)
//factory (Strategy)
//strategy (Strategy)
//flyweight (Treasure)
//decorator (Double damage)