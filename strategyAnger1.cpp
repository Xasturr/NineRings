#include "strategyAnger1.h"

StrategyAnger1::StrategyAnger1()
{
	cout << "In StrategyAnger1 constructor" << endl;
}

StrategyAnger1::~StrategyAnger1()
{
	cout << "In StrategyAnger1 destructor" << endl;
}

void StrategyAnger1::decision(Player* player, Character* character, states* states, float elapsedTime)
{
	if (!character->getHurt())
	{
		states->leftPressed_ = false;
		states->rightPressed_ = false;
		states->attack_ = false;

		if (character->getCurrSpriteSide() == "left")
		{
			if (character->getCurrPosition().x - character->getAttackRange() <= player->getCurrPosition().x + player->getWidth() / 2 && character->getCurrPosition().x >= player->getCurrPosition().x && !player->getHurt())
			{
				states->attack_ = true;
			}
		}
		else
		{
			if (character->getCurrPosition().x + character->getAttackRange() >= player->getCurrPosition().x - player->getWidth() / 2 && character->getCurrPosition().x <= player->getCurrPosition().x && !player->getHurt())
			{
				states->attack_ = true;
			}
		}

		if (player->getCurrPosition().x - character->getCurrPosition().x <= character->getOverview() && player->getCurrPosition().x - player->getWidth() / 1 - character->getCurrPosition().x > character->getAttackRange() / 2)
		{
			states->rightPressed_ = true;
		}
		else if (character->getCurrPosition().x - player->getCurrPosition().x <= character->getOverview() && character->getCurrPosition().x - player->getWidth() / 1 - player->getCurrPosition().x > character->getAttackRange() / 2)
		{
			states->leftPressed_ = true;
		}
		else
		{
			if (player->getCurrPosition().x > character->getCurrPosition().x)
			{
				character->spriteUpdateAttack("right");
			}
			else if (player->getCurrPosition().x < character->getCurrPosition().x)
			{
				character->spriteUpdateAttack("left");
			}
			else
			{
				//to do
			}
			character->setState("staying");
		}
	}
}

int StrategyAnger1::getStrategyParam()
{
	return StrategyParams::angry;
}