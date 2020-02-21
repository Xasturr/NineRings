#include "physxImplEnWalk.h"

PhysxImplEnWalk::PhysxImplEnWalk() 
{
	runningTime_ = 0;
	stayingTime_ = 0;
}

PhysxImplEnWalk::~PhysxImplEnWalk()
{
	cout << "In PhysxImplEnWalk distructor" << endl;
}

void PhysxImplEnWalk::updateDecisionTime(states* states, float elapsedTime)
{
	if (runningTime_ > 0)
	{
		runningTime_ -= elapsedTime;
	}
	else if (stayingTime_ > 0)
	{
		stayingTime_ -= elapsedTime;
	}

	if (runningTime_ <= 0 && stayingTime_ <= 0)
	{
		runningTime_ = 0;
		stayingTime_ = 0;
		states->leftPressed_ = false;
		states->rightPressed_ = false;
	}
}

void PhysxImplEnWalk::interactionWithMap(struct states* states, Character* character, Vector2f oldEnemyPosition, Map* map, float elapsedTime)
{
	Vector2f position = character->getCurrPosition();
	Vector2f newEnemyPosition = character->getCurrPosition();

	character->setCurrGravityAccel(0);
	states->onEdge_ = false;

	bool changedDirection = false;

	float pos = 0;

	int gap = map->getTileWidth();

	if (states->leftPressed_)
	{
		gap = 0;
	}

	//if (angryState_)
	//{
	//	//gap *= 2;
	//}

	//preventing from fall
	for (int i = (newEnemyPosition.x + gap) / map->getTileWidth(); i < (newEnemyPosition.x + gap) / map->getTileWidth(); i++)
	{
		for (int j = (oldEnemyPosition.y) / map->getTileHeight(); j < (oldEnemyPosition.y + character->getHeight()) / map->getTileHeight(); j++)
		{
			if (map->getValue(j, i, ' ', map->getTileMapElse()))
			{
				//position.x = oldEnemyPosition.x;
				if (states->leftPressed_)
				{
					//character->setPosition(oldEnemyPosition.x + (oldEnemyPosition.x - newEnemyPosition.x), oldEnemyPosition.y);
					states->leftPressed_ = false;
					states->rightPressed_ = true;
				}
				else if (states->rightPressed_)
				{
					//character->setPosition(oldEnemyPosition.x - (newEnemyPosition.x - oldEnemyPosition.x), oldEnemyPosition.y);
					states->rightPressed_ = false;
					states->leftPressed_ = true;
				}
				character->setPosition(oldEnemyPosition.x, oldEnemyPosition.y);
				return;
			}
		}
	}

	//preventing from bounce
	for (int i = (newEnemyPosition.x + gap) / map->getTileWidth(); i < (newEnemyPosition.x + gap) / map->getTileWidth() && !changedDirection; i++)
	{
		if (!map->getCollision((oldEnemyPosition.y - character->getHeight() / 2) / map->getTileHeight(), i, ' '))
		{
			if (states->leftPressed_)
			{
				states->leftPressed_ = false;
				states->rightPressed_ = true;
			}
			else if (states->rightPressed_)
			{
				states->rightPressed_ = false;
				states->leftPressed_ = true;
			}
			character->setPosition(oldEnemyPosition.x, oldEnemyPosition.y);
			return;
		}
	}

	character->setPosition(position.x, position.y);
}

void PhysxImplEnWalk::updatePosition(Character *character, states* states, float elapsedTime)
{
	if (character->getCurrHealthPoints() > 0)
	{
		if (character->getHurt())
		{
			states->attack_ = false;
			character->setCurrHurtFrame(character->getFrameSpeed() * elapsedTime);
			character->spriteUpdateHurt(character->getCurrSpriteSide());
			return;
		}

		if (states->leftPressed_)
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
		else if (states->rightPressed_)
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
		if (((states->upPressed_ && character->getCurrState() != "jumping") || character->getCurrState() == "jumping") && character->getCurrState() != "falling")
		{
			if (states->upPressed_ && character->getCurrState() != "jumping")
			{
				character->setState("jumping");
				character->setCurrJumpAccel(character->getJumpForce());
				character->setCurrGravityAccel(0);
			}
			character->setPosition(character->getCurrPosition().x, character->getCurrPosition().y);
			character->setCurrJumpFrame(character->getFrameSpeed() * elapsedTime);
			character->spriteUpdateJump(character->getCurrSpriteSide());
		}
		if (character->getCurrState() == "staying")
		{
			character->setPosition(character->getCurrPosition().x, character->getCurrPosition().y);
			character->setCurrIdleFrame(character->getFrameSpeed() * elapsedTime);
			character->spriteUpdateIdle();
		}
		if (character->getCurrState() == "falling")
		{
			character->setPosition(character->getCurrPosition().x, character->getCurrPosition().y);
			character->setCurrFallFrame(character->getFrameSpeed() * elapsedTime);
			character->spriteUpdateFall(character->getCurrSpriteSide());
		}
		if ((states->attack_ && !character->getRunAttackState() || character->getRunAttackState()))
		{
			if (character->getCurrState() == "running")
			{
				character->setRunAttackState(true);
				character->setCurrRunAttackFrame(character->getFrameSpeed() * elapsedTime);
				character->spriteUpdateRunAttack(character->getCurrSpriteSide());
			}
		}
		if (states->attack_ && !character->getAttackState() || character->getAttackState())
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

void PhysxImplEnWalk::decision(Player* player, Character* character, states* states, float elapsedTime)
{
	if (character->getName() == "Character1" && !character->getHurt())
	{
		if (character->getCurrState() == "falling")
		{
			states->leftPressed_ = false;
			states->rightPressed_ = false;
			stayingTime_ = 0;
			runningTime_ = 0;
		}
		else if (states->angryState_)
		{
			states->leftPressed_ = false;
			states->rightPressed_ = false;
			states->attack_ = false;
			stayingTime_ = 0;
			runningTime_ = 1;

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
		else
		{
			if (!states->leftPressed_ && !states->rightPressed_ && stayingTime_ == 0 && runningTime_ == 0)
			{
				int r = rand() % 3;

				if (r == 0)
				{
					runningTime_ = rand() % (9 - 8 + 1) + 8;
					states->leftPressed_ = true;
				}
				else if (r == 1)
				{
					runningTime_ = rand() % (9 - 8 + 1) + 8;
					states->rightPressed_ = true;
				}
				else
				{
					stayingTime_ = rand() % (1 - 1 + 1) + 1;
					character->setState("staying");
				}
			}
		}
	}

	updateDecisionTime(states, elapsedTime);
}