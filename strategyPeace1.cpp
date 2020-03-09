#include "strategyPeace1.h"

StrategyPeace1::~StrategyPeace1()
{
	cout << "In StrategyPeace destructor" << endl;
}

void StrategyPeace1::decision(Player* player, Character* character, states* states, float elapsedTime)
{
	if (!states->leftPressed_ && !states->rightPressed_ && !character->getHurt())
	{
		int r = rand() % 2;
		states->attack_ = false;
		//character->setState("running");

		if (r == 0)
		{
			//runningTime_ = rand() % (9 - 8 + 1) + 8;
			states->leftPressed_ = true;
		}
		else if (r == 1)
		{
			//runningTime_ = rand() % (9 - 8 + 1) + 8;
			states->rightPressed_ = true;
		}
		//else
		//{
		//	//stayingTime_ = rand() % (1 - 1 + 1) + 1;
		//	character->setState("staying");
		//}
	}
}