#include "enemy.h"

Enemy::Enemy(int charName, float posX, float posY, PhysxImplement* physx)
{
	charName_ = charName;

	if (charName_ == Characters::Character1_name)
	{
		character_ = new Character1(posX, posY);
	}
	else if (charName_ == Characters::CharacterBat_name)
	{
		character_ = new CharacterBat(posX, posY);
	}
	else
	{
		cout << "Wrong character" << endl;
		exit(EXIT_FAILURE);
	}

	physx_ = physx;
	character_->setPosition(posX, posY);
}

Enemy::~Enemy()
{
	cout << "In Enemy destructor" << endl;
	delete character_;
	delete physx_;
}

bool Enemy::getEnemyLife()
{
	return character_->getLife();
}

bool Enemy::getHurt()
{
	return character_->getHurt();
}

void Enemy::updatePosition(float elapsedTime)
{
	physx_->updatePosition(character_, elapsedTime);
}

void Enemy::draw(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime)
{
	if (player->getCurrPosition().x + viewSize.x / 2 + 50 >= character_->getCurrPosition().x && player->getCurrPosition().x - viewSize.x / 2 - 50 <= character_->getCurrPosition().x)
	{
		if (player->getCurrPosition().y + viewSize.y / 2 + 50 >= character_->getCurrPosition().y && player->getCurrPosition().y - viewSize.y / 2 - 50 <= character_->getCurrPosition().y)
		{
			//if (abs(player->getCurrPosition().x - character_->getCurrPosition().x) <= character_->getOverview() && abs(player->getCurrPosition().y - character_->getCurrPosition().y) <= character_->getHeight())
			if (character_->calculateAngryState(player->getCurrPosition()))
			{
				//states_.angryState_ = true;
				//physx_->states_.angryState_ = true;

				physx_->setStrategy(StrategyParams::angry, character_->getName());
				
<<<<<<< HEAD
				//character_->setMaxMoveSpeed(380);
=======
				character_->setMaxMoveSpeed(300);
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57
			}
			else
			{
				physx_->setStrategy(StrategyParams::peacful, character_->getName());
				//states_.angryState_ = false;
				//states_.attack_ = false;
<<<<<<< HEAD
				//character_->setMaxMoveSpeed(250);
=======
				character_->setMaxMoveSpeed(200);
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57
				//character_->setState("staying");
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

void Enemy::interactionWithMap(Vector2f oldEnemyPosition, Map* map, float elapsedTime)
{
	physx_->interactionWithMap(character_, oldEnemyPosition, map, elapsedTime);
}
	
void Enemy::decision(float elapsedTime, Player* player)
{
	physx_->decision(player, character_, elapsedTime);
}

void Enemy::calculateVariables(float elapsedTime)
{
	if (character_->getCurrShotCoolDown() > 0)
	{
		character_->setCurrShotCoolDown(character_->getCurrShotCoolDown() - elapsedTime);

		if (character_->getCurrShotCoolDown() < 0)
		{
			character_->setCurrShotCoolDown(0);
		}
	}
	//if (character_->getCurrState() == "falling")
	//{
	//	character_->setCurrGravityAccel(character_->getCurrGravityAccel() + character_->getGravity() * elapsedTime);
	//}
	//else if (character_->getCurrState() == "jumping")
	//{
	//	character_->setCurrGravityAccel(character_->getCurrGravityAccel() + character_->getGravity() * elapsedTime);
	//	character_->setCurrJumpAccel(character_->getCurrJumpAccel() - character_->getCurrGravityAccel() * elapsedTime);
	//}
}

void Enemy::setCurrHealthPoints(int healthPoints)
{
	character_->setCurrHealthPoints(healthPoints);
}

void Enemy::setHurt(bool flag)
{
	character_->setHurt(flag);
}

void Enemy::flyingShellsUpdateAndDraw(float elapsedTime, Map* map, RenderWindow* window)
{
	character_->flyingShellsUpdateAndDraw(elapsedTime, map, window);
}

void Enemy::setStrategy(int param)
{
	physx_->setStrategy(param, character_->getName());
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

int Enemy::flyingShellsMakeDamage(Vector2f playerPos, int playerWidth, int playerHeight)
{
	return character_->flyingShellsMakeDamage(playerPos, playerWidth, playerHeight);
}

int Enemy::getKillExp()
{
	return character_->getKillExp();
}

int Enemy::getCurrFlyingShellsAmount()
{
	return character_->getCurrFlyingShellAmount();
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
			cout << player->getAttackDamage() + (float)player->getAttackDamage() / 100 * (float)player->getTripleScratchesPerkBonus() << endl;
			cout << player->getAttackDamage() << endl;
			if (player->getCurrSpriteSide() == "left")
			{
				if (player->getCurrPosition().x - player->getAttackRange() <= character_->getCurrPosition().x + character_->getWidth() / 2 && player->getCurrPosition().x > character_->getCurrPosition().x)
				{
					player->setEnemyDamaged(true);
					int oldHp = character_->getCurrHealthPoints();
					if (player->getCurrHealthPoints() * 2 <= player->getMaxHealthPoints() && player->getTripleScratchesPerkLevel())
					{
						character_->setCurrHealthPoints(character_->getCurrHealthPoints() - player->getAttackDamage() - (float)player->getAttackDamage() / 100 * (float)player->getTripleScratchesPerkBonus());
					}
					else
					{
						character_->setCurrHealthPoints(character_->getCurrHealthPoints() - player->getAttackDamage());
					}

					if (player->getCurrVampireDraculaPerkLevel() == 1 && player->getCurrHealthPoints() < player->getMaxHealthPoints())
					{
						player->setCurrHealthPoints(player->getCurrHealthPoints() + player->getVampireDraculaPerkBonus() * float(oldHp - character_->getCurrHealthPoints()) / 100);
						if (player->getMaxHealthPoints() < player->getCurrHealthPoints())
						{
							player->setCurrHealthPoints(player->getMaxHealthPoints());
						}
					}
					
					cout << "Enemy health: " << character_->getCurrHealthPoints() << endl;
					character_->setHurt(true);
				}
			}
			else
			{
				if (player->getCurrPosition().x + player->getAttackRange() > character_->getCurrPosition().x - character_->getWidth() / 2 && player->getCurrPosition().x < character_->getCurrPosition().x)
				{
					player->setEnemyDamaged(true);
					int oldHp = character_->getCurrHealthPoints();
					if (player->getCurrHealthPoints() * 2 <= player->getMaxHealthPoints() && player->getTripleScratchesPerkLevel())
					{
						character_->setCurrHealthPoints(character_->getCurrHealthPoints() - player->getAttackDamage() - (float)player->getAttackDamage() / 100 * (float)player->getTripleScratchesPerkBonus());
					}
					else
					{
						character_->setCurrHealthPoints(character_->getCurrHealthPoints() - player->getAttackDamage());
					}
					if (player->getCurrVampireDraculaPerkLevel() && player->getCurrHealthPoints() < player->getMaxHealthPoints())
					{
						player->setCurrHealthPoints(player->getCurrHealthPoints() + player->getVampireDraculaPerkBonus() * float(oldHp - character_->getCurrHealthPoints()) / 100);
						if (player->getMaxHealthPoints() < player->getCurrHealthPoints())
						{
							player->setCurrHealthPoints(player->getMaxHealthPoints());
						}
					}
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
					player->setCurrHealthPoints(player->getCurrHealthPoints() - character_->getAttackDamage() * (100 - player->getArmor()) / 100);
					player->setHurt(true);
				}
			}
			else
			{
				if (character_->getCurrPosition().x + character_->getAttackRange() > player->getCurrPosition().x - player->getWidth() / 2 && character_->getCurrPosition().x < player->getCurrPosition().x)
				{
					character_->setEnemyDamaged(true);
					player->setCurrHealthPoints(player->getCurrHealthPoints() - character_->getAttackDamage() * (100 - player->getArmor()) / 100);
					player->setHurt(true);
				}
			}
		}
	}
}