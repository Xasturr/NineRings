#include "game.h"

int main()
{
	Game game;
	game.start();

	return 0;
}

/*bugs:
	-��������� �������� �������� �� ����, �����������, ����� � ����
	-double damage � ������ Player, � �� Character
*/

//patterns:
//singleton (Engine)
//builder (Engine-Level)
//bridge (Physix)
//factory (Strategy)
//strategy (Strategy)
//flyweight (Treasure)
//decorator (Double damage)