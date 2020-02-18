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
	cout << "In Enemy destructor" << endl;
	delete character_;
}

bool Enemy::getEnemyLife()
{
	return character_->getLife();
}

void Enemy::updatePosition(float elapsedTime)
{
	if (character_->getCurrHealthPoints() > 0)
	{
		if (character_->getHurt())
		{
			attack_ = false;
			character_->setCurrHurtFrame(character_->getFrameSpeed() * elapsedTime);
			character_->spriteUpdateHurt(character_->getCurrSpriteSide());
			return;
		}

		if (leftPressed_)
		{
			if (character_->getCurrState() == "falling" || character_->getCurrState() == "jumping")
			{
				character_->setPosition(character_->getCurrPosition().x - character_->getMaxMoveSpeed() * elapsedTime, character_->getCurrPosition().y);
			}
			else
			{
				character_->setState("running");
				character_->setPosition(character_->getCurrPosition().x - character_->getMaxMoveSpeed() * elapsedTime, character_->getCurrPosition().y);
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
				character_->setPosition(character_->getCurrPosition().x + character_->getMaxMoveSpeed() * elapsedTime, character_->getCurrPosition().y);
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
			character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y);
			character_->setCurrJumpFrame(character_->getFrameSpeed() * elapsedTime);
			character_->spriteUpdateJump(character_->getCurrSpriteSide());
		}
		if (character_->getCurrState() == "staying")
		{
			character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y);
			character_->setCurrIdleFrame(character_->getFrameSpeed() * elapsedTime);
			character_->spriteUpdateIdle();
		}
		if (character_->getCurrState() == "falling")
		{
			character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y);
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
		//if (character_->getCurrState() == "hurt")
	}
	else if (character_->getLife())
	{
		character_->setCurrDeathFrame(character_->getFrameSpeed() * elapsedTime);
		character_->spriteUpdateDeath(character_->getCurrSpriteSide());
	}
	//else
	//{
	//	cout << "You are dead" << endl;
	//	exit(0);
	//}
}

void Enemy::draw(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime)
{
	if (player->getCurrPosition().x + viewSize.x / 2 + 50 >= character_->getCurrPosition().x && player->getCurrPosition().x - viewSize.x / 2 - 50 <= character_->getCurrPosition().x)
	{
		if (player->getCurrPosition().y + viewSize.y / 2 + 50 >= character_->getCurrPosition().y && player->getCurrPosition().y - viewSize.y / 2 - 50 <= character_->getCurrPosition().y)
		{
			//if (abs(player->getCurrPosition().x - character_->getCurrPosition().x) <= character_->getOverview() && abs(player->getCurrPosition().y - character_->getCurrPosition().y) <= character_->getHeight())
			if (abs(player->getCurrPosition().x - character_->getCurrPosition().x) <= character_->getOverview() && player->getCurrPosition().y == character_->getCurrPosition().y)
			{
				angryState_ = true;
				character_->setMaxMoveSpeed(300);
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
	
	character_->setCurrGravityAccel(0);

	onEdge_ = false;

	bool changedDirection = false;

	float pos = 0;

	int gap = map->getTileWidth() / 2;

	if (leftPressed_)
	{
		gap = -gap;
	}
	
	//if (angryState_)
	//{
	//	//gap *= 2;
	//}

	//preventing from fall
	for (int i = (newEnemyPosition.x + gap) / map->getTileWidth(); i < (newEnemyPosition.x + gap) / map->getTileWidth(); i++)
	{
		for (int j = (oldEnemyPosition.y) / map->getTileHeight(); j < (oldEnemyPosition.y + character_->getHeight()) / map->getTileHeight(); j++)
		{
			if (map->getValue(j, i, ' ', map->getTileMapElse()))
			{
				//position.x = oldEnemyPosition.x;
				if (leftPressed_)
				{
					//character_->setPosition(oldEnemyPosition.x + (oldEnemyPosition.x - newEnemyPosition.x), oldEnemyPosition.y);
					leftPressed_ = false;
					rightPressed_ = true;
				}
				else if (rightPressed_)
				{
					//character_->setPosition(oldEnemyPosition.x - (newEnemyPosition.x - oldEnemyPosition.x), oldEnemyPosition.y);
					rightPressed_ = false;
					leftPressed_ = true;
				}
				character_->setPosition(oldEnemyPosition.x, oldEnemyPosition.y);
				return;	
			}
		}
	}

	//preventing from bounce
	for (int i = (newEnemyPosition.x + gap) / map->getTileWidth(); i < (newEnemyPosition.x + gap) / map->getTileWidth() && !changedDirection; i++)
	{
		if (!map->getCollision((oldEnemyPosition.y - character_->getHeight() / 2) / map->getTileHeight(), i, ' '))
		{
			if (leftPressed_)
			{
				//character_->setPosition(oldEnemyPosition.x + (oldEnemyPosition.x - newEnemyPosition.x), oldEnemyPosition.y);
				leftPressed_ = false;
				rightPressed_ = true;
			}
			else if (rightPressed_)
			{
				//character_->setPosition(oldEnemyPosition.x - (newEnemyPosition.x - oldEnemyPosition.x), oldEnemyPosition.y);
				rightPressed_ = false;
				leftPressed_ = true;
			}
			character_->setPosition(oldEnemyPosition.x, oldEnemyPosition.y);
			return;
		}
	}

	//for (int i = (oldEnemyPosition.x - character_->getLeftGap()*0 + map->getTileWidth() / 2 + gap) / map->getTileWidth(); i < (oldEnemyPosition.x + character_->getRightGap()*0 + map->getTileWidth() / 2 + gap) / map->getTileWidth(); i++)
	//{
	//	for (int j = (newEnemyPosition.y) / map->getTileHeight(); j < (newEnemyPosition.y + character_->getHeight()) / map->getTileHeight(); j++)
	//	{
	//		if (map->getValue(j, i, ' ', map->getTileMapElse()))
	//		{
	//			cout << j << endl;
	//			if (position.x == newEnemyPosition.x && newEnemyPosition.x != oldEnemyPosition.x)
	//			{
	//				character_->setState("running");
	//			}
	//			else
	//			{
	//				character_->setState("staying");
	//			}
	//
	//			onEdge_ = true;
	//			character_->setCurrJumpAccel(character_->getJumpForce());
	//			character_->setCurrGravityAccel(0);
	//		//	break;
	//		}
	//	}
	//}
	
	//if (character_->getCurrState() != "jumping" && character_->getCurrState() != "falling" && character_->getCurrState() != "staying" && onEdge_)
	//{
	//	if (angryState_)
	//	{
	//		cout << "aaaaaaaa" << endl;
	//		//onEdge_ = true;
	//		character_->setState("staying");
	//		leftPressed_ = false;
	//		rightPressed_ = false;
	//		character_->setPosition(oldEnemyPosition.x, oldEnemyPosition.y);
	//		character_->spriteUpdateIdle();
	//		character_->setCurrIdleFrame(elapsedTime);
	//	}
	//	else
	//	{
	//		cout << "bbbbbbbbb" << endl;
	//		if (leftPressed_)
	//		{
	//			leftPressed_ = false;
	//			rightPressed_ = true;
	//			character_->setPosition(oldEnemyPosition.x + (oldEnemyPosition.x - newEnemyPosition.x), oldEnemyPosition.y);
	//		}
	//		else if (rightPressed_)
	//		{
	//			rightPressed_ = false;
	//			leftPressed_ = true;
	//			character_->setPosition(oldEnemyPosition.x - (newEnemyPosition.x - oldEnemyPosition.x), oldEnemyPosition.y);
	//		}
	//		else
	//		{
	//			character_->setPosition(oldEnemyPosition.x, oldEnemyPosition.y);
	//		}
	//		//cout << "HERE" << endl;
	//		//character_->setState("falling");
	//	}
	//	//attack_ = false;
	//}
	//else
	//{
	//	onEdge_ = false;
	character_->setPosition(position.x, position.y);
	//}
}
	
void Enemy::decision(float elapsedTime, Player* player)
{
	if (character_->getName() == "Character1" && !character_->getHurt())
	{
		if (character_->getCurrState() == "falling")
		{
			leftPressed_ = false;
			rightPressed_ = false;
			stayingTime_ = 0;
			runningTime_ = 0;
		}
		else if (angryState_)
		{
			leftPressed_ = false;
			rightPressed_ = false;
			attack_ = false;
			stayingTime_ = 0;
			runningTime_ = 1;
		
			if (character_->getCurrSpriteSide() == "left")
			{
				if (character_->getCurrPosition().x - character_->getAttackRange() <= player->getCurrPosition().x + player->getWidth() / 2 && character_->getCurrPosition().x >= player->getCurrPosition().x && !player->getHurt())
				{
					attack_ = true;
				}
			}
			else
			{
				if (character_->getCurrPosition().x + character_->getAttackRange() >= player->getCurrPosition().x - player->getWidth() / 2 && character_->getCurrPosition().x <= player->getCurrPosition().x && !player->getHurt())
				{
					attack_ = true;
				}
			}
		
			if (player->getCurrPosition().x - character_->getCurrPosition().x <= character_->getOverview() && player->getCurrPosition().x - player->getWidth() / 1 - character_->getCurrPosition().x > character_->getAttackRange() / 2)
			{
				rightPressed_ = true;
			}
			else if (character_->getCurrPosition().x - player->getCurrPosition().x <= character_->getOverview() && character_->getCurrPosition().x - player->getWidth() / 1 - player->getCurrPosition().x > character_->getAttackRange() / 2)
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
		else 
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

void Enemy::setCurrHealthPoints(int healthPoints)
{
	character_->setCurrHealthPoints(healthPoints);
}

void Enemy::setHurt(bool flag)
{
	character_->setHurt(flag);
}

int Enemy::getWidth()
{
	return character_->getWidth();
}

int Enemy::getHeight()
{
	return character_->getHeight();
}

int Enemy::getCurrHealthPoints()
{
	return character_->getCurrHealthPoints();
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
	if (player->getAttackState() && !player->getCharacterMadeDamage() && !player->getDamageDisabled() && character_->getCurrHealthPoints() > 0 && !character_->getHurt())
	{
		if (player->getCurrPosition().y - player->getHeight() < character_->getCurrPosition().y && player->getCurrPosition().y > character_->getCurrPosition().y - character_->getHeight())
		{
			if (player->getCurrSpriteSide() == "left")
			{
				if (player->getCurrPosition().x - player->getAttackRange() <= character_->getCurrPosition().x + character_->getWidth() / 2 && player->getCurrPosition().x > character_->getCurrPosition().x)
				{
					player->setEnemyDamaged(true);
					character_->setCurrHealthPoints(character_->getCurrHealthPoints() - player->getAttackDamage());
					cout << "Enemy health: " << character_->getCurrHealthPoints() << endl;
					character_->setHurt(true);
				}
			}
			else
			{
				if (player->getCurrPosition().x + player->getAttackRange() > character_->getCurrPosition().x - character_->getWidth() / 2 && player->getCurrPosition().x < character_->getCurrPosition().x)
				{
					player->setEnemyDamaged(true);
					character_->setCurrHealthPoints(character_->getCurrHealthPoints() - player->getAttackDamage());
					cout << "Enemy health: " << character_->getCurrHealthPoints() << endl;
					character_->setHurt(true);
				}
			}
		}
	}

	if (character_->getAttackState() && !character_->getCharacterMadeDamage() && !character_->getDamageDisabled() && player->getCurrHealthPoints() > 0 && !player->getHurt())
	{
		if (character_->getCurrPosition().y - character_->getHeight() < player->getCurrPosition().y && character_->getCurrPosition().y > player->getCurrPosition().y - player->getHeight())
		{
			if (character_->getCurrSpriteSide() == "left")
			{
				if (character_->getCurrPosition().x - character_->getAttackRange() <= player->getCurrPosition().x + player->getWidth() / 2 && character_->getCurrPosition().x > player->getCurrPosition().x)
				{
					character_->setEnemyDamaged(true);
					player->setCurrHealthPoints(player->getCurrHealthPoints() - character_->getAttackDamage());
					//cout << "Player health: " << player->getCurrHealthPoints() << endl;
					player->setHurt(true);
				}
			}
			else
			{
				if (character_->getCurrPosition().x + character_->getAttackRange() > player->getCurrPosition().x - player->getWidth() / 2 && character_->getCurrPosition().x < player->getCurrPosition().x)
				{
					character_->setEnemyDamaged(true);
					player->setCurrHealthPoints(player->getCurrHealthPoints() - character_->getAttackDamage());
					//cout << "Player health: " << player->getCurrHealthPoints() << endl;
					player->setHurt(true);
				}
			}
		}
	}
}