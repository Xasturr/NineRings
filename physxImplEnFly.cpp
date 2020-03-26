#include "physxImplEnFly.h"

PhysxImplEnFly::PhysxImplEnFly(int minPosX, int maxPosX, int charName)
{
	minPosX_ = minPosX;
	maxPosX_ = maxPosX;

	strategy_ = makeStrategy(StrategyParams::peacful, charName);
}

PhysxImplEnFly::~PhysxImplEnFly()
{
	cout << "In PhysxImplEnFly distructor" << endl;

	delete strategy_;
}

void PhysxImplEnFly::interactionWithMap(Character* character, Vector2f oldEnemyPosition, Map* map, float elapsedTime)
{
	Vector2f position = character->getCurrPosition();
	Vector2f newEnemyPosition = character->getCurrPosition();

	if (newEnemyPosition.x >= maxPosX_ || newEnemyPosition.x <= minPosX_)
	{
		if (states_.leftPressed_)
		{
			states_.leftPressed_ = false;
			states_.rightPressed_ = true;
		}
		else
		{
			states_.leftPressed_ = true;
			states_.rightPressed_ = false;
		}
		
		position.x = oldEnemyPosition.x;
	}

	character->setPosition(position.x, position.y);
}

void PhysxImplEnFly::updatePosition(Character* character, float elapsedTime)
{
	if (character->getCurrHealthPoints() > 0)
	{
		if (character->getHurt())
		{
			character->setCurrHurtFrame(character->getFrameSpeed() * elapsedTime);
			character->spriteUpdateHurt(character->getCurrSpriteSide());
			return;
		}

		if (states_.leftPressed_)
		{
			character->setState("flying");
			character->setPosition(character->getCurrPosition().x - character->getMaxMoveSpeed() * elapsedTime, character->getCurrPosition().y);
			character->setCurrFlyFrame(character->getFrameSpeed() * elapsedTime);
			
			character->spriteUpdateFly("left");
		}
		else if (states_.rightPressed_)
		{
			character->setState("flying");
			character->setPosition(character->getCurrPosition().x + character->getMaxMoveSpeed() * elapsedTime, character->getCurrPosition().y);
			character->setCurrFlyFrame(character->getFrameSpeed() * elapsedTime);
			
			character->spriteUpdateFly("right");
		}
		else
		{
			character->setCurrFlyFrame(character->getFrameSpeed() * elapsedTime);
			character->spriteUpdateFly(character->getCurrSpriteSide());
		}

		if (states_.shoot_ && character->getCurrShotCoolDown() == 0)
		{
			character->addFlyingShell(character->getCurrShellName(), character->getCurrShellAngle());
			character->setCurrShotCoolDown(character->getMaxShotCoolDown());
			states_.shoot_ = false;
		}
	}
	else if (character->getLife())
	{
		character->setCurrDeathFrame(character->getFrameSpeed() * elapsedTime);
		character->spriteUpdateDeath(character->getCurrSpriteSide());
	}
}

void PhysxImplEnFly::decision(Player* player, Character* character, float elapsedTime)
{
	strategy_->decision(player, character, &states_, elapsedTime);
<<<<<<< HEAD
=======
	//if (!character->getHurt())
	//{
	//	if (player->getCurrPosition().x < minPosX_ && player->getCurrPosition().x > maxPosX_)
	//	{
	//		states->angryState_ = false;
	//	}

	//	if (states->angryState_)
	//	{
	//		states->leftPressed_ = false;
	//		states->rightPressed_ = false;

	//		if (player->getCurrPosition().x - character->getCurrPosition().x <= character->getOverview()
	//			&& player->getCurrPosition().x - character->getCurrPosition().x > 0
	//			&& player->getCurrPosition().x - player->getWidth() - character->getCurrPosition().x > character->getAttackRange() / 2)
	//		{
	//			if (player->getCurrPosition().x < maxPosX_)
	//			{
	//				states->rightPressed_ = true;
	//			}
	//		}
	//		else if (character->getCurrPosition().x - player->getCurrPosition().x <= character->getOverview()
	//			&& character->getCurrPosition().x - player->getCurrPosition().x > 0
	//			&& character->getCurrPosition().x - player->getWidth() - player->getCurrPosition().x > character->getAttackRange() / 2)
	//		{
	//			if (player->getCurrPosition().x > minPosX_)
	//			{
	//				states->leftPressed_ = true;
	//			}
	//		}
	//		else if (character->getCurrShotCoolDown() == 0)
	//		{
	//			float angle = atan2(-player->getCurrPosition().y + character->getCurrPosition().y, -player->getCurrPosition().x + character->getCurrPosition().x) * 180 / 3.14 - 90;
	//			//rayRotation_ = (atan2(-playerPos_.y + enemyPos_.y, -playerPos_.x + enemyPos_.x)) * 180 / 3.14;
	//			character->setCurrShellAgle(angle);
	//			states->shoot_ = true;
	//		}

	//		if (player->getCurrPosition().x < character->getCurrPosition().x)
	//		{
	//			character->spriteUpdateFly("left");
	//		}
	//		else
	//		{
	//			character->spriteUpdateFly("right");
	//		}

	//		return;
	//	}

	//	if (!states->leftPressed_ && !states->rightPressed_)
	//	{
	//		int r = rand() % 2;

	//		if (r == 0)
	//		{
	//			states->leftPressed_ = true;
	//		}
	//		else
	//		{
	//			states->rightPressed_ = true;
	//		}
	//	}
	//}
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57
}

void PhysxImplEnFly::setStrategy(int param, int charName)
{
	if (strategy_)
	{
		if (strategy_->getStrategyParam() != param)
		{
			delete strategy_;
			strategy_ = makeStrategy(param, charName);
		}
	}
	else
	{
		strategy_ = makeStrategy(param, charName);
	}
<<<<<<< HEAD
=======

	//if (param == strategyParams::angry)
	//{
	//	strategy_ = makeStrategy(StrategyType::StateAnger1);
	//}
	//else if (param == strategyParams::peacful)
	//{
	//	strategy_ = makeStrategy(StrategyType::StatePeace1);
	//}
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57
}