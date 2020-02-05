#include "enemy.h"

Enemy::Enemy(string charName, float posX, float posY)
{
	charName_ = charName;

	if (charName_ == "Character1")
	{
		character_ = new Character1(posX, posY);
	}
	else
	{
		cout << "Wrong character" << endl;
		exit(EXIT_FAILURE);
	}

	leftPressed_ = false;
	rightPressed_ = false;
	upPressed_ = false;
	downPressed_ = false;
	attack_ = false;
	runAttack_ = false;

	character_->setPosition(posX, posY);
}

Enemy::~Enemy()
{

}

bool Enemy::getEnemyLife()
{
	return character_->getLife();
}

void Enemy::updatePosition(float elapsedTime)
{
	if (leftPressed_)
	{
		if (character_->getCurrState() == "falling" || character_->getCurrState() == "jumping")
		{
			character_->setPosition(character_->getCurrPosition().x - character_->getMaxMoveSpeed() * elapsedTime, character_->getCurrPosition().y);
		}
		else
		{
			character_->setState("running");
			character_->setPosition(character_->getCurrPosition().x - character_->getMaxMoveSpeed() * elapsedTime, character_->getCurrPosition().y + character_->getGravity() * elapsedTime);
			character_->setCurrRunFrame(character_->getFrameSpeed() * elapsedTime);
		}
		character_->spriteUpdateRun("left");
	}
	else if (rightPressed_)
	{
		if (character_->getCurrState() == "falling" || character_->getCurrState() == "jumping")
		{
			character_->setPosition(character_->getCurrPosition().x + character_->getMaxMoveSpeed() * elapsedTime, character_->getCurrPosition().y);
		}
		else
		{
			character_->setState("running");
			character_->setPosition(character_->getCurrPosition().x + character_->getMaxMoveSpeed() * elapsedTime, character_->getCurrPosition().y + character_->getGravity() * elapsedTime);
			character_->setCurrRunFrame(character_->getFrameSpeed() * elapsedTime);
		}
		character_->spriteUpdateRun("right");
	}
	if (((upPressed_ && character_->getCurrState() != "jumping") || character_->getCurrState() == "jumping") && character_->getCurrState() != "falling")
	{
		if (upPressed_ && character_->getCurrState() != "jumping")
		{
			character_->setState("jumping");
			character_->setCurrJumpAccel(character_->getJumpForce());
			character_->setCurrGravityAccel(0);
		}
		character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y - character_->getCurrJumpAccel() * elapsedTime);
		character_->setCurrJumpFrame(character_->getFrameSpeed() * elapsedTime);
		character_->spriteUpdateJump(character_->getCurrSpriteSide());
	}
	if (character_->getCurrState() == "staying")
	{
		character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y + character_->getGravity() * elapsedTime);
		character_->setCurrIdleFrame(character_->getFrameSpeed() * elapsedTime);
		character_->spriteUpdateIdle();
	}
	if (character_->getCurrState() == "falling")
	{
		//cout << "WWWWWWWWWWWWWWWWW" << endl;
		character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y + (character_->getCurrGravityAccel()) * elapsedTime);
		character_->setCurrFallFrame(character_->getFrameSpeed() * elapsedTime);
		character_->spriteUpdateFall(character_->getCurrSpriteSide());
	}
	if ((attack_ && !character_->getRunAttackState() || character_->getRunAttackState()))
	{
		if (character_->getCurrState() == "running")
		{
			character_->setRunAttackState(true);
			character_->setCurrRunAttackFrame(character_->getFrameSpeed() * elapsedTime);
			character_->spriteUpdateRunAttack(character_->getCurrSpriteSide());
		}
	}
	if (attack_ && !character_->getAttackState() || character_->getAttackState())
	{
		if (character_->getCurrState() != "running")
		{
			character_->setAttackState(true);
			character_->setCurrAttackFrame(character_->getFrameSpeed() * elapsedTime);
			character_->spriteUpdateAttack(character_->getCurrSpriteSide());
		}
	}
}

void Enemy::draw(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime)
{
	if (player->getCurrPosition().x + viewSize.x / 2 + 50 >= character_->getCurrPosition().x && player->getCurrPosition().x - viewSize.x / 2 - 50 <= character_->getCurrPosition().x)
	{
		if (player->getCurrPosition().y + viewSize.y / 2 + 50 >= character_->getCurrPosition().y && player->getCurrPosition().y - viewSize.y / 2 - 50 <= character_->getCurrPosition().y)
		{
			////character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y + character_->getGravity() * elapsedTime);
			//character_->setCurrIdleFrame(character_->getFrameSpeed() * elapsedTime);
			//character_->spriteUpdateIdle();
			checkDamage(player);
			window->draw(character_->getSprite());
		}
	}
}

void Enemy::interactionWithMap(Vector2f oldEnemyPosition, Vector2f newEnemyPosition, Map* map, float elapsedTime)
{
	Vector2f position = newEnemyPosition;
	
	bool changedDirection = false;

	for (int i = (newEnemyPosition.x - character_->getLeftGap()) / map->getTileWidth(); i < (newEnemyPosition.x + character_->getRightGap()) / map->getTileWidth() && !changedDirection; i++)
	{
		for (int j = (oldEnemyPosition.y - character_->getUpperGap()) / map->getTileHeight(); j < (oldEnemyPosition.y + character_->getLowerGap()) / map->getTileHeight(); j++)
		{
			if (!map->getValue(j, i, ' ', map->getTileMapElse()))
			{
				position.x = oldEnemyPosition.x;
				if (leftPressed_)
				{
					leftPressed_ = false;
					rightPressed_ = true;
				}
				else if (rightPressed_)
				{
					rightPressed_ = false;
					leftPressed_ = true;
				}
				changedDirection = true;
				//i = (newEnemyPosition.x + character_->getRightGap()) / map->getTileWidth() - 1;
				break;
			}
		}
	}

	for (int i = (oldEnemyPosition.x - character_->getLeftGap()) / map->getTileWidth(); i < (oldEnemyPosition.x + character_->getRightGap()) / map->getTileWidth(); i++)
	{
		for (int j = (newEnemyPosition.y - character_->getUpperGap()) / map->getTileHeight(); j < (newEnemyPosition.y + character_->getLowerGap()) / map->getTileHeight(); j++)
		{
			if (!map->getValue(j, i, ' ', map->getTileMapElse()))
			{
				if (character_->getCurrState() == "jumping")
				{
					if (newEnemyPosition.y > j * map->getTileHeight())
					{
						character_->setState("falling");
						character_->setPosition(oldEnemyPosition.x, oldEnemyPosition.y);
						character_->setCurrGravityAccel(0);
						return;
					}
				}
				else
				{
					if (position.x == newEnemyPosition.x && newEnemyPosition.x != oldEnemyPosition.x)
					{
						character_->setState("running");
					}
					else
					{
						character_->setState("staying");
					}

					position.y = j * map->getTileHeight() - character_->getLowerGap();
				}

				character_->setCurrJumpAccel(character_->getJumpForce());
				character_->setCurrGravityAccel(0);
				break;
			}
		}
	}

	character_->setPosition(position.x, position.y);

	if (character_->getCurrState() != "jumping" && character_->getCurrState() != "falling" && character_->getCurrState() != "staying" && position == newEnemyPosition)
	{
		if (leftPressed_)
		{
			leftPressed_ = false;
			rightPressed_ = true;
			character_->setPosition(oldEnemyPosition.x + (oldEnemyPosition.x - newEnemyPosition.x), oldEnemyPosition.y);
		}
		else if (rightPressed_)
		{
			rightPressed_ = false;
			leftPressed_ = true;
			character_->setPosition(oldEnemyPosition.x - (newEnemyPosition.x - oldEnemyPosition.x), oldEnemyPosition.y);
		}
		//character_->setState("falling");
	}
}

void Enemy::decision()
{
	//if (character_->getCurrState() == "falling")
	//{
	//	leftPressed_ = false;
	//	rightPressed_ = false;
	//}
	//else if (!leftPressed_ && !rightPressed_)
	//{
	//	leftPressed_ = true;
	//}
}

void Enemy::calculateVariables(float elapsedTime)
{
	if (character_->getCurrState() == "falling")
	{
		character_->setCurrGravityAccel(character_->getCurrGravityAccel() + character_->getGravity() * elapsedTime);
	}
	else if (character_->getCurrState() == "jumping")
	{
		character_->setCurrGravityAccel(character_->getCurrGravityAccel() + character_->getGravity() * elapsedTime);
		character_->setCurrJumpAccel(character_->getCurrJumpAccel() - character_->getCurrGravityAccel() * elapsedTime);
	}
}

Vector2f Enemy::getPosition()
{
	return character_->getSprite().getPosition();
}

Sprite Enemy::getSprite()
{
	return character_->getSprite();
}

void Enemy::checkDamage(Player* player)
{
	if (player->getAttackState() && !player->getEnemyDamaged() && !player->getDamageDisabled())
	{
		if (player->getCurrSpriteSide() == "left")
		{
			if (player->getCurrPosition().x - player->getAttackRange() < character_->getCurrPosition().x && player->getCurrPosition().x > character_->getCurrPosition().x)
			{
				player->setEnemyDamaged(true);
				character_->setHealthPoints(character_->getHealthPoints() - player->getAttackDamage());
			}
		}
		else
		{
			if (player->getCurrPosition().x < character_->getCurrPosition().x && player->getCurrPosition().x + player->getAttackRange() > character_->getCurrPosition().x)
			{
				player->setEnemyDamaged(true);
				character_->setHealthPoints(character_->getHealthPoints() - player->getAttackDamage());
			}
		}

		cout << character_->getHealthPoints() << endl;
	}
}