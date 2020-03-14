#include "physxImplEnWalk.h"

PhysxImplEnWalk::PhysxImplEnWalk(int charName) 
{
	runningTime_ = 0;
	stayingTime_ = 0;

	states_.leftPressed_ = false;
	states_.rightPressed_ = false;
	states_.upPressed_ = false;
	states_.downPressed_ = false;
	states_.attack_ = false;
	states_.runAttack_ = false;
	states_.angryState_ = false;
	states_.onEdge_ = false;

	strategy_ = makeStrategy(StrategyParams::peacful, charName);
}

PhysxImplEnWalk::~PhysxImplEnWalk()
{
	cout << "In PhysxImplEnWalk distructor" << endl;
}

void PhysxImplEnWalk::updateDecisionTime(float elapsedTime)
{
	//if (runningTime_ > 0)
	//{
	//	runningTime_ -= elapsedTime;
	//}
	//else if (stayingTime_ > 0)
	//{
	//	stayingTime_ -= elapsedTime;
	//}

	//if (runningTime_ <= 0 && stayingTime_ <= 0)
	//{
	//	runningTime_ = 0;
	//	stayingTime_ = 0;
	//	states_.leftPressed_ = false;
	//	states_.rightPressed_ = false;
	//}
}

void PhysxImplEnWalk::interactionWithMap(Character* character, Vector2f oldEnemyPosition, Map* map, float elapsedTime)
{
	Vector2f position = character->getCurrPosition();
	Vector2f newEnemyPosition = character->getCurrPosition();

	character->setCurrGravityAccel(0);
	states_.onEdge_ = false;

	bool changedDirection = false;

	float pos = 0;

	int gap = 0;
	int gap2 = 0;

	if (states_.leftPressed_)
	{
		gap2 = map->getTileWidth() / 2;
	}
	else
	{
		gap = map->getTileWidth() / 2;
	}

	//if (angryState_)
	//{
	//	//gap *= 2;
	//}

	//preventing from fall
	for (int i = (newEnemyPosition.x) / map->getTileWidth(); i < (newEnemyPosition.x + gap) / map->getTileWidth(); i++)
	{
		for (int j = (oldEnemyPosition.y) / map->getTileHeight(); j < (oldEnemyPosition.y + character->getHeight()) / map->getTileHeight(); j++)
		{
			if (map->getValue(j, i, ' ', map->getTileMapElse()))
			{
				//position.x = oldEnemyPosition.x;
				if (states_.leftPressed_)
				{
					//character->setPosition(oldEnemyPosition.x + (oldEnemyPosition.x - newEnemyPosition.x), oldEnemyPosition.y);
					states_.leftPressed_ = false;
					states_.rightPressed_ = true;
				}
				else if (states_.rightPressed_)
				{
					//character->setPosition(oldEnemyPosition.x - (newEnemyPosition.x - oldEnemyPosition.x), oldEnemyPosition.y);
					states_.rightPressed_ = false;
					states_.leftPressed_ = true;
				}
				character->setPosition(oldEnemyPosition.x, oldEnemyPosition.y);
				return;
			}
		}
	}

	//preventing from bounce
	for (int i = (newEnemyPosition.x) / map->getTileWidth(); i < (newEnemyPosition.x + gap) / map->getTileWidth() && !changedDirection; i++)
	{
		if (!map->getCollision((oldEnemyPosition.y - character->getHeight() / 2) / map->getTileHeight(), i, ' '))
		{
			if (states_.leftPressed_)
			{
				states_.leftPressed_ = false;
				states_.rightPressed_ = true;
			}
			else if (states_.rightPressed_)
			{
				states_.rightPressed_ = false;
				states_.leftPressed_ = true;
			}
			character->setPosition(oldEnemyPosition.x, oldEnemyPosition.y);
			return;
		}
	}

	character->setPosition(position.x, position.y);
}

void PhysxImplEnWalk::updatePosition(Character *character, float elapsedTime)
{
	if (character->getCurrHealthPoints() > 0)
	{
		if (character->getHurt())
		{
			states_.attack_ = false;
			character->setCurrHurtFrame(character->getFrameSpeed() * elapsedTime);
			character->spriteUpdateHurt(character->getCurrSpriteSide());
			return;
		}

		if (character->getCurrState() == "falling") //костыль
		{
			character->setState("staying");
		}

		if (states_.leftPressed_)
		{
			if (character->getCurrState() == "falling" || character->getCurrState() == "jumping")
			{
				character->setPosition(character->getCurrPosition().x - character->getMaxMoveSpeed() * elapsedTime, character->getCurrPosition().y);
			}
			else
			{
				character->setState("running");
				character->setPosition(character->getCurrPosition().x - character->getMaxMoveSpeed() * elapsedTime, character->getCurrPosition().y);
				character->setCurrRunFrame(character->getFrameSpeed() * elapsedTime);
			}
			character->spriteUpdateRun("left");
		}
		else if (states_.rightPressed_)
		{
			if (character->getCurrState() == "falling" || character->getCurrState() == "jumping")
			{
				character->setPosition(character->getCurrPosition().x + character->getMaxMoveSpeed() * elapsedTime, character->getCurrPosition().y);
			}
			else
			{
				character->setState("running");
				character->setPosition(character->getCurrPosition().x + character->getMaxMoveSpeed() * elapsedTime, character->getCurrPosition().y);
				character->setCurrRunFrame(character->getFrameSpeed() * elapsedTime);
			}
			character->spriteUpdateRun("right");
		}
		if (((states_.upPressed_ && character->getCurrState() != "jumping") || character->getCurrState() == "jumping") && character->getCurrState() != "falling")
		{
			if (states_.upPressed_ && character->getCurrState() != "jumping")
			{
				character->setState("jumping");
				character->setCurrJumpAccel(character->getJumpForce());
				character->setCurrGravityAccel(0);
			}
			character->setPosition(character->getCurrPosition().x, character->getCurrPosition().y);
			character->setCurrJumpFrame(character->getFrameSpeed() * elapsedTime);
			character->spriteUpdateJump(character->getCurrSpriteSide());
		}
		if (character->getCurrState() == "staying" )
		{
			character->setPosition(character->getCurrPosition().x, character->getCurrPosition().y);
			character->setCurrIdleFrame(character->getFrameSpeed() * elapsedTime);
			character->spriteUpdateIdle(character->getCurrSpriteSide());
		}
		if (character->getCurrState() == "falling")
		{
			character->setPosition(character->getCurrPosition().x, character->getCurrPosition().y);
			character->setCurrFallFrame(character->getFrameSpeed() * elapsedTime);
			character->spriteUpdateFall(character->getCurrSpriteSide());
		}
		if ((states_.attack_ && !character->getRunAttackState() || character->getRunAttackState()))
		{
			if (character->getCurrState() == "running")
			{
				character->setRunAttackState(true);
				character->setCurrRunAttackFrame(character->getFrameSpeed() * elapsedTime);
				character->spriteUpdateRunAttack(character->getCurrSpriteSide());
			}
		}
		if (states_.attack_ && !character->getAttackState() || character->getAttackState())
		{
			if (character->getCurrState() != "running")
			{
				character->setAttackState(true);
				character->setCurrAttackFrame(character->getFrameSpeed() * elapsedTime);
				character->spriteUpdateAttack(character->getCurrSpriteSide());
			}
		}
	}
	else if (character->getLife())
	{
		character->setCurrDeathFrame(character->getFrameSpeed() * elapsedTime);
		character->spriteUpdateDeath(character->getCurrSpriteSide());
	}
}

void PhysxImplEnWalk::decision(Player* player, Character* character, float elapsedTime)
{
	strategy_->decision(player, character, &states_, elapsedTime);
	//if (character->getName() == "Character1" && !character->getHurt())
	//{
	//	if (character->getCurrState() == "falling")
	//	{
	//		states_.leftPressed_ = false;
	//		states_.rightPressed_ = false;
	//		stayingTime_ = 0;
	//		runningTime_ = 0;
	//	}
	//	else if (states_.angryState_)
	//	{
	//		states_.leftPressed_ = false;
	//		states_.rightPressed_ = false;
	//		states_.attack_ = false;
	//		stayingTime_ = 0;
	//		runningTime_ = 1;

	//		if (character->getCurrSpriteSide() == "left")
	//		{
	//			if (character->getCurrPosition().x - character->getAttackRange() <= player->getCurrPosition().x + player->getWidth() / 2 && character->getCurrPosition().x >= player->getCurrPosition().x && !player->getHurt())
	//			{
	//				states_.attack_ = true;
	//			}
	//		}
	//		else
	//		{
	//			if (character->getCurrPosition().x + character->getAttackRange() >= player->getCurrPosition().x - player->getWidth() / 2 && character->getCurrPosition().x <= player->getCurrPosition().x && !player->getHurt())
	//			{
	//				states_.attack_ = true;
	//			}
	//		}

	//		if (player->getCurrPosition().x - character->getCurrPosition().x <= character->getOverview() && player->getCurrPosition().x - player->getWidth() / 1 - character->getCurrPosition().x > character->getAttackRange() / 2)
	//		{
	//			states_.rightPressed_ = true;
	//		}
	//		else if (character->getCurrPosition().x - player->getCurrPosition().x <= character->getOverview() && character->getCurrPosition().x - player->getWidth() / 1 - player->getCurrPosition().x > character->getAttackRange() / 2)
	//		{
	//			states_.leftPressed_ = true;
	//		}
	//		else
	//		{
	//			if (player->getCurrPosition().x > character->getCurrPosition().x)
	//			{
	//				character->spriteUpdateAttack("right");
	//			}
	//			else if (player->getCurrPosition().x < character->getCurrPosition().x)
	//			{
	//				character->spriteUpdateAttack("left");
	//			}
	//			else
	//			{
	//				//to do
	//			}
	//			character->setState("staying");
	//		}
	//	}
	//	else
	//	{
	//		if (!states_.leftPressed_ && !states_.rightPressed_ && stayingTime_ == 0 && runningTime_ == 0)
	//		{
	//			int r = rand() % 3;

	//			if (r == 0)
	//			{
	//				runningTime_ = rand() % (9 - 8 + 1) + 8;
	//				states_.leftPressed_ = true;
	//			}
	//			else if (r == 1)
	//			{
	//				runningTime_ = rand() % (9 - 8 + 1) + 8;
	//				states_.rightPressed_ = true;
	//			}
	//			else
	//			{
	//				stayingTime_ = rand() % (1 - 1 + 1) + 1;
	//				character->setState("staying");
	//			}
	//		}
	//	}
	//}

	updateDecisionTime(elapsedTime);
}

void PhysxImplEnWalk::setStrategy(int param, int charName)
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

	/*if (param == strategyParams::angry)
	{
		if (character == Characters::Character1)
		{
			strategy_ = makeStrategy(StrategyType::StateAnger1);
		}
	}
	else if (param == strategyParams::peacful)
	{
		strategy_ = makeStrategy(StrategyType::StatePeace1);
	}*/
}