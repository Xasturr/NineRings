#include "treasureFactory.h"

TreasureFactory::TreasureFactory() 
{
	currentTreasureName = "Coin";
}

TreasureFactory::~TreasureFactory()
{
	cout << "In TreasureFactory destructor" << endl;

	for (auto it = treasures_.begin(); it != treasures_.end(); it++)
	{
		treasures_.erase(it);
		Treasure* treasure = it->second;
		delete treasure;
	}
}

Treasure* TreasureFactory::getTreasure()
{
	Treasure* treasure = NULL;

	auto iter = treasures_.find(currentTreasureName);

	if (iter != treasures_.end())
	{
		treasure = treasures_[currentTreasureName];
	}
	else
	{
		if (currentTreasureName == "Coin")
		{
			if (!treasureCoin_)
			{
				treasureCoin_ = new TreasureCoin();
			}
			treasure = treasureCoin_;
		}
		treasures_.insert({ currentTreasureName, treasure });
	}
	return treasure;
}

void TreasureFactory::setTreasureName(string treasureName)
{
	currentTreasureName = treasureName;
}