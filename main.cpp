#include "game.h"

int main()
{
	Game game;
	game.start();

	return 0;
}

//patterns:
//singleton (Engine)
//builder (Level)
//bridge (Physix)
//strategy (Strategy)
//flyweight (Treasure)
//factory (Treasure)
//decorator (Double damage)
//proxy (TreasureCoin)