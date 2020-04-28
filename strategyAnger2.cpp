#include "strategyAnger2.h"

StrategyAnger2::StrategyAnger2()
{
	cout << "In strategyAnger2 constructor" << endl;
}

StrategyAnger2::~StrategyAnger2()
{
	cout << "In StrategyAnger2 destructor" << endl;
}

void StrategyAnger2::decision(Player* player, Character* character, states* states, float elapsedTime)
{
	if (!character->getHurt())
	{
		states->leftPressed_ = false;
		states->rightPressed_ = false;

		if (player->getCurrPosition().x - character->getCurrPosition().x <= character->getOverview()
			&& player->getCurrPosition().x - character->getCurrPosition().x > 0
			&& player->getCurrPosition().x - player->getWidth() - character->getCurrPosition().x > character->getAttackRange() / 2)
		{
			states->rightPressed_ = true;
		}
		else if (character->getCurrPosition().x - player->getCurrPosition().x <= character->getOverview()
			&& character->getCurrPosition().x - player->getCurrPosition().x > 0
			&& character->getCurrPosition().x - player->getWidth() - player->getCurrPosition().x > character->getAttackRange() / 2)
		{
			states->leftPressed_ = true;
		}
		else if (character->getCurrShotCoolDown() == 0)
		{
			float angle = atan2(-player->getCurrPosition().y + character->getCurrPosition().y, -player->getCurrPosition().x + character->getCurrPosition().x) * 180 / 3.14 - 90;
			//rayRotation_ = (atan2(-playerPos_.y + enemyPos_.y, -playerPos_.x + enemyPos_.x)) * 180 / 3.14;
			character->setCurrShellAgle(angle);
			states->shoot_ = true;
		}

		if (player->getCurrPosition().x < character->getCurrPosition().x)
		{
			character->spriteUpdateFly("left");
		}
		else
		{
			character->spriteUpdateFly("right");
		}

		return;
	}
}

int StrategyAnger2::getStrategyParam()
{
	return StrategyParams::angry;
}