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
}