#include "strategyPeace1.h"

StrategyPeace1::StrategyPeace1()
{
	cout << "In StrategyPeace constructor" << endl;
}

StrategyPeace1::~StrategyPeace1()
{
	cout << "In StrategyPeace destructor" << endl;
}

void StrategyPeace1::decision(Player* player, Character* character, states* states, float elapsedTime)
{
	states->attack_ = false;

	if (!states->leftPressed_ && !states->rightPressed_ && !character->getHurt())
	{
		int r = rand() % 2;

		if (r == 0)
		{
			states->leftPressed_ = true;
		}
		else if (r == 1)
		{
			states->rightPressed_ = true;
		}
	}
}

int StrategyPeace1::getStrategyParam()
{
	return StrategyParams::peacful;
}