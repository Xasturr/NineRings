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
	angryState_ = false;
	onEdge_ = false;

	stayingTime_ = 0;
	runningTime_ = 0;

	character_->setPosition(posX, posY);
}

Enemy::~Enemy()
{

}

bool Enemy::getEnemyLife()
{
	return character_->getLife();
}

//bool Enemy::getAngryState()
//{
//	return angryState_;
//}

void Enemy::updatePosition(float elapsedTime)
{
	cout << character_->getCurrPosition().x << endl;
	if (leftPressed_)
	{
		//if (onEdge_)
		//{
		//	//cout << "LEFTTTTTTTTTTTTTTT" << endl
		//	character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y);
		//	character_->spriteUpdateIdle();
		//	character_->setCurrIdleFrame(character_->getFrameSpeed() * elapsedTime);
		//	character_->setState("staying");
		//	return;
		//}
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
		cout << "adsd" << endl;
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
			if (abs(player->getCurrPosition().x - character_->getCurrPosition().x) <= character_->getOverview() && abs(player->getCurrPosition().y - character_->getCurrPosition().y) <= character_->getHeight())
			{
				angryState_ = true;
				character_->setMaxMoveSpeed(400);
			}
			else
			{
				angryState_ = false;
				attack_ = false;
				character_->setMaxMoveSpeed(200);
				character_->setState("staying");
				//stayingTime_ = 0;
				//runningTime_ = 0;
			}
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
	onEdge_ = false;

	float pos = 0;

	int gap = 0;

	if (leftPressed_)
	{
		gap = map->getTileWidth();
		gap = -gap;
	}
	else
	{
		gap = map->getTileWidth();
	}
	
	if (attack_)
	{
		gap /= 1;
	}

	for (int i = (newEnemyPosition.x - character_->getLeftGap() + map->getTileWidth() / 2 + gap) / map->getTileWidth(); i < (newEnemyPosition.x + character_->getRightGap() + map->getTileWidth() / 2 + gap) / map->getTileWidth() && !changedDirection; i++)
	{
		for (int j = (oldEnemyPosition.y - character_->getHeight()) / map->getTileHeight(); j < (oldEnemyPosition.y) / map->getTileHeight(); j++)
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

				character_->setPosition(position.x, oldEnemyPosition.y);

				return;	
			}
		}
	}

	for (int i = (oldEnemyPosition.x - character_->getLeftGap() + map->getTileWidth() / 2 + gap) / map->getTileWidth(); i < (oldEnemyPosition.x + character_->getRightGap() + map->getTileWidth() / 2 + gap) / map->getTileWidth(); i++)
	{
		for (int j = (newEnemyPosition.y - character_->getHeight()) / map->getTileHeight(); j < (newEnemyPosition.y) / map->getTileHeight(); j++)
		{
			if (!map->getValue(j, i, ' ', map->getTileMapElse()))
			{
				if (character_->getCurrState() == "jumping")
				{
					if (newEnemyPosition.y > j * map->getTileHeight() + map->getTileHeight() / 2)
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

					position.y = j * map->getTileHeight();
					//cout << position.y << endl;
				}

				//onEdge_ = true;
				character_->setCurrJumpAccel(character_->getJumpForce());
				character_->setCurrGravityAccel(0);
				break;
			}
		}
	}

	character_->setPosition(position.x, position.y);

	if (character_->getCurrState() != "jumping" && character_->getCurrState() != "falling" && character_->getCurrState() != "staying" && position == newEnemyPosition)
	{
		//cout << "here" << endl;
		if (angryState_)
		{
			onEdge_ = true;
			//character_->setState("staying");
			//leftPressed_ = false;
			//rightPressed_ = false;
			character_->setPosition(oldEnemyPosition.x, oldEnemyPosition.y);
			//character_->spriteUpdateIdle();
			//character_->setCurrIdleFrame(elapsedTime);
		}
		else
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
		//attack_ = false;
	}
}

void Enemy::decision(float elapsedTime, Player* player)
{
	if (character_->getName() == "Character1")
	{
		//cout << onEdge_ << endl;
		if (character_->getCurrState() == "falling")
		{
			leftPressed_ = false;
			rightPressed_ = false;
			stayingTime_ = 0;
			runningTime_ = 0;
		}
		else if (angryState_ && !onEdge_)
		{
			leftPressed_ = false;
			rightPressed_ = false;
			attack_ = false;
			stayingTime_ = 0;
			runningTime_ = 1;
		
			if (character_->getCurrSpriteSide() == "left")
			{
				if (character_->getCurrPosition().x - character_->getAttackRange() <= player->getCurrPosition().x + player->getWidth() / 2 && character_->getCurrPosition().x >= player->getCurrPosition().x)
				{
					attack_ = true;
				}
			}
			else
			{
				if (character_->getCurrPosition().x + character_->getAttackRange() >= player->getCurrPosition().x - player->getWidth() / 2 && character_->getCurrPosition().x <= player->getCurrPosition().x)
				{
					attack_ = true;
				}
			}

			//if (abs(player->getCurrPosition().x - character_->getCurrPosition().x) < character_->getAttackRange())
			//{
			//	attack_ = true;
			//}
		
			if (player->getCurrPosition().x - character_->getCurrPosition().x <= character_->getOverview() && player->getCurrPosition().x - player->getWidth() / 2 - character_->getCurrPosition().x > character_->getAttackRange() / 2)
			{
				rightPressed_ = true;
			}
			else if (character_->getCurrPosition().x - player->getCurrPosition().x <= character_->getOverview() && character_->getCurrPosition().x - player->getWidth() / 2 - player->getCurrPosition().x > character_->getAttackRange() / 2)
			{
				leftPressed_ = true;
			}
			else
			{
				if (player->getCurrPosition().x > character_->getCurrPosition().x)
				{
					character_->spriteUpdateAttack("right");
				}
				else if (player->getCurrPosition().x < character_->getCurrPosition().x)
				{
					character_->spriteUpdateAttack("left");
				}
				else
				{
					//to do
				}
				character_->setState("staying");
			}
		}
		else if (!onEdge_)
		{
			if (!leftPressed_ && !rightPressed_ && stayingTime_ == 0 && runningTime_ == 0)
			{
				int r = rand() % 3;
		
				if (r == 0)
				{
					runningTime_ = rand() % (9 - 8 + 1) + 8;
					leftPressed_ = true;
				}
				else if (r == 1)
				{
					runningTime_ = rand() % (9 - 8 + 1) + 8;
					rightPressed_ = true;
				}
				else
				{
					stayingTime_ = rand() % (1 - 1 + 1) + 1;
					character_->setState("staying");
				}
			}
		}
	}

	updateDecisionTime(elapsedTime);
}

void Enemy::updateDecisionTime(float elapsedTime)
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
		leftPressed_ = false;
		rightPressed_ = false;
	}
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
	if (player->getAttackState() && !player->getCharacterMadeDamage() && !player->getDamageDisabled())
	{
		if (player->getCurrPosition().y - player->getHeight() < character_->getCurrPosition().y && player->getCurrPosition().y > character_->getCurrPosition().y - character_->getHeight())
		{
			if (player->getCurrSpriteSide() == "left")
			{
				if (player->getCurrPosition().x - player->getAttackRange() <= character_->getCurrPosition().x + character_->getWidth() / 2 && player->getCurrPosition().x > character_->getCurrPosition().x)
				{
					player->setEnemyDamaged(true);
					character_->setHealthPoints(character_->getHealthPoints() - player->getAttackDamage());
					cout << "Enemy health: " << character_->getHealthPoints() << endl;
				}
			}
			else
			{
				if (player->getCurrPosition().x + player->getAttackRange() > character_->getCurrPosition().x - character_->getWidth() / 2 && player->getCurrPosition().x < character_->getCurrPosition().x)
				{
					player->setEnemyDamaged(true);
					character_->setHealthPoints(character_->getHealthPoints() - player->getAttackDamage());
					cout << "Enemy health: " << character_->getHealthPoints() << endl;
				}
			}
		}
	}

	if (character_->getAttackState() && !character_->getCharacterMadeDamage() && !character_->getDamageDisabled())
	{
		//if (player->getCurrPosition().y - player->getHeight() < character_->getCurrPosition().y && player->getCurrPosition().y > character_->getCurrPosition().y - character_->getHeight())
		if (character_->getCurrPosition().y - character_->getHeight() < player->getCurrPosition().y && character_->getCurrPosition().y > player->getCurrPosition().y - player->getHeight())
		{
			if (character_->getCurrSpriteSide() == "left")
			{
				if (character_->getCurrPosition().x - character_->getAttackRange() <= player->getCurrPosition().x + player->getWidth() / 2 && character_->getCurrPosition().x > player->getCurrPosition().x)
				{
					character_->setEnemyDamaged(true);
					player->setHealthPoints(player->getHealthPoints() - character_->getAttackDamage());
					cout << "Player health: " << player->getHealthPoints() << endl;
				}
			}
			else
			{
				if (character_->getCurrPosition().x + character_->getAttackRange() > player->getCurrPosition().x - player->getWidth() / 2 && character_->getCurrPosition().x < player->getCurrPosition().x)
				{
					character_->setEnemyDamaged(true);
					player->setHealthPoints(player->getHealthPoints() - character_->getAttackDamage());
					cout << "Player health: " << player->getHealthPoints() << endl;
				}
			}
			//if (abs(player->getCurrPosition().x - character_->getCurrPosition().x) <= character_->getAttackRange())
			//{
			//
			//}
		}
	}
}