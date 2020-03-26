#include "treasureFactory.h"

TreasureFactory::TreasureFactory() 
{
	currentTreasureName = "Coin";
}

TreasureFactory::~TreasureFactory()
{
	cout << "In TreasureFactory destructor" << endl;

	map<pair<int, int>, Treasure*>::iterator it;

	for (it = treasures_.begin(); it != treasures_.end(); it++)
	{
<<<<<<< HEAD
		treasures_.erase(it);
		Treasure* treasure = it->second;
		delete treasure;
=======
		Treasure* treasure = it->second;
		delete treasure;
		treasures_.erase(it);
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57
	}
}

Treasure* TreasureFactory::getTreasure(Vector2f position, int tileWidth, int tileHeight)
{
	Treasure* treasure = NULL;

	pair<int, int> pos;
	pos.first = position.x;
	pos.second = position.y;

	map<pair<int, int>, Treasure*>::iterator it;

	it = treasures_.find(pos);

	if (it != treasures_.end())
	{
		treasure = treasures_[pos];
	}
	else
	{
		if (currentTreasureName == "Coin")
		{
			position.x *= tileWidth;
			position.y *= tileHeight;

			treasure = new TreasureCoin(position);
			treasures_.insert({pos, treasure});
		}
	}
	return treasure;
}

void TreasureFactory::setTreasureName(string treasureName)
{
	currentTreasureName = treasureName;
}