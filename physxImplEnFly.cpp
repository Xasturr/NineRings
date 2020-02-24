#include "physxImplEnFly.h"

PhysxImplEnFly::PhysxImplEnFly(int minPosX, int maxPosX)
{
	minPosX_ = minPosX;
	maxPosX_ = maxPosX;
}

PhysxImplEnFly::~PhysxImplEnFly()
{
	cout << "In PhysxImplEnFly distructor" << endl;
}

void PhysxImplEnFly::interactionWithMap(struct states* states, Character* character, Vector2f oldEnemyPosition, Map* map, float elapsedTime)
{
	Vector2f position = character->getCurrPosition();
	Vector2f newEnemyPosition = character->getCurrPosition();

	if (newEnemyPosition.x >= maxPosX_ || newEnemyPosition.x <= minPosX_)
	{
		if (states->leftPressed_)
		{
			states->leftPressed_ = false;
			states->rightPressed_ = true;
		}
		else
		{
			states->leftPressed_ = true;
			states->rightPressed_ = false;
		}
		
		position.x = oldEnemyPosition.x;
	}

	character->setPosition(position.x, position.y);
}

void PhysxImplEnFly::updatePosition(Character* character, states* states, float elapsedTime)
{
	if (character->getCurrHealthPoints() > 0)
	{
		if (character->getHurt())
		{
			character->setCurrHurtFrame(character->getFrameSpeed() * elapsedTime);
			character->spriteUpdateHurt(character->getCurrSpriteSide());
			return;
		}

		if (states->leftPressed_)
		{
			character->setState("flying");
			character->setPosition(character->getCurrPosition().x - character->getMaxMoveSpeed() * elapsedTime, character->getCurrPosition().y);
			character->setCurrFlyFrame(character->getFrameSpeed() * elapsedTime);
			
			character->spriteUpdateFly("left");
		}
		else if (states->rightPressed_)
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

		if (states->shoot_ && character->getCurrShotCoolDown() == 0)
		{
			character->addFlyingShell(character->getCurrShellName(), character->getCurrShellAngle());
			character->setCurrShotCoolDown(character->getMaxShotCoolDown());
			states->shoot_ = false;
		}
	}
	else if (character->getLife())
	{
		character->setCurrDeathFrame(character->getFrameSpeed() * elapsedTime);
		character->spriteUpdateDeath(character->getCurrSpriteSide());
	}
}

void PhysxImplEnFly::decision(Player* player, Character* character, states* states, float elapsedTime)
{
	if (!character->getHurt())
	{
		if (player->getCurrPosition().x < minPosX_ && player->getCurrPosition().x > maxPosX_)
		{
			states->angryState_ = false;
		}

		if (states->angryState_)
		{
			states->leftPressed_ = false;
			states->rightPressed_ = false;

			if (player->getCurrPosition().x - character->getCurrPosition().x <= character->getOverview()
				&& player->getCurrPosition().x - character->getCurrPosition().x > 0
				&& player->getCurrPosition().x - player->getWidth() - character->getCurrPosition().x > character->getAttackRange() / 2)
			{
				if (player->getCurrPosition().x < maxPosX_)
				{
					states->rightPressed_ = true;
				}
			}
			else if (character->getCurrPosition().x - player->getCurrPosition().x <= character->getOverview()
				&& character->getCurrPosition().x - player->getCurrPosition().x > 0
				&& character->getCurrPosition().x - player->getWidth() - player->getCurrPosition().x > character->getAttackRange() / 2)
			{
				if (player->getCurrPosition().x > minPosX_)
				{
					states->leftPressed_ = true;
				}
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

		if (!states->leftPressed_ && !states->rightPressed_)
		{
			int r = rand() % 2;

			if (r == 0)
			{
				states->leftPressed_ = true;
			}
			else
			{
				states->rightPressed_ = true;
			}
		}
	}
}