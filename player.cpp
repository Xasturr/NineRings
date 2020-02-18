#include "player.h"

Player::Player(string charName, float posX, float posY)
{
	leftPressed_ = false;
	rightPressed_ = false;
	upPressed_ = false;
	downPressed_ = false;
	attack_ = false;
	runAttack_ = false;
	shoot_ = false;
	doubleDamage_ = false;

	charName_ = charName;
	currShellName_ = "FireBall";

	ddTimer_ = 0;
	ddDuration_ = 5;

	if (charName_ == "Character1")
	{
		character_ = new Character1(posX, posY);
	}
	else
	{
		cout << "Wrong character" << endl;
		exit(EXIT_FAILURE);
	}

	character_->setPosition(posX, posY);
}

Player::~Player()
{
	cout << "In Player destructor" << endl;
	delete character_;
}

void Player::moveLeft()
{
	leftPressed_ = true;
}

void Player::moveRight()
{
	rightPressed_ = true;
}

void Player::moveUp()
{
	upPressed_ = true;
}

void Player::moveDown()
{
	downPressed_ = true;
}

void Player::attack()
{
	attack_ = true;
}

void Player::shoot()
{
	shoot_ = true;
}

void Player::stopLeft()
{
	leftPressed_ = false;
}

void Player::stopRight()
{
	rightPressed_ = false;
}

void Player::stopUp()
{
	upPressed_ = false;
}

void Player::stopDown()
{
	downPressed_ = false;
}

void Player::stopAttack()
{
	attack_ = false;
}

void Player::stopShoot()
{
	shoot_ = false;
}

void Player::update(float elapsedTime)
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

		if (character_->getCurrShotCoolDown() > 0)
		{
			character_->setCurrShotCoolDown(character_->getCurrShotCoolDown() - elapsedTime);
			
			if (character_->getCurrShotCoolDown() < 0)
			{
				character_->setCurrShotCoolDown(0);
			}
		}

		if (shoot_ && character_->getCurrShotCoolDown() == 0 && character_->getCurrShellAmount() > 0 && getCurrMana() >= 40)
		{
			setCurrMana(getCurrMana() - 40);

			if (ddTimer_ > 0)
			{
				character_->addFlyingShell(currShellName_, true);
			}
			else
			{
				character_->addFlyingShell(currShellName_);
			}
			character_->setCurrShotCoolDown(character_->getMaxShotCoolDown());
		}

		if (leftPressed_)
		{
			if (character_->getCurrState() == "falling" || character_->getCurrState() == "jumping")
			{
				character_->setPosition(character_->getCurrPosition().x - character_->getMaxMoveSpeed() * elapsedTime, character_->getCurrPosition().y);
				character_->spriteUpdateRun("left");
			}
			else
			{
				character_->setState("running");
				character_->setPosition(character_->getCurrPosition().x - character_->getMaxMoveSpeed() * elapsedTime, character_->getCurrPosition().y + character_->getGravity() * elapsedTime);
				character_->setCurrRunFrame(character_->getFrameSpeed() * elapsedTime);
				character_->spriteUpdateRun("left");
			}
		}
		else if (rightPressed_)
		{
			if (character_->getCurrState() == "falling" || character_->getCurrState() == "jumping")
			{
				character_->setPosition(character_->getCurrPosition().x + character_->getMaxMoveSpeed() * elapsedTime, character_->getCurrPosition().y);
				character_->spriteUpdateRun("right");
			}
			else
			{
				character_->setState("running");
				character_->setPosition(character_->getCurrPosition().x + character_->getMaxMoveSpeed() * elapsedTime, character_->getCurrPosition().y + character_->getGravity() * elapsedTime);
				character_->setCurrRunFrame(character_->getFrameSpeed() * elapsedTime);
				character_->spriteUpdateRun("right");
			}
		}
		if (((upPressed_ && character_->getCurrState() != "jumping" && getCurrStamina() >= getJumpStaminaCost()) || character_->getCurrState() == "jumping") && character_->getCurrState() != "falling")
		{
			if (upPressed_ && character_->getCurrState() != "jumping")
			{
				character_->setState("jumping");
				character_->setCurrJumpAccel(character_->getJumpForce());
				character_->setCurrGravityAccel(0);
				character_->setCurrStamina(character_->getCurrStamina() - getJumpStaminaCost());
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
			character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y + character_->getCurrGravityAccel() * elapsedTime);
			character_->setCurrFallFrame(character_->getFrameSpeed() * elapsedTime);
			character_->spriteUpdateFall(character_->getCurrSpriteSide());
		}
		if ((attack_ && !character_->getRunAttackState() && getCurrStamina() >= getAttackStaminaCost()) || character_->getRunAttackState())
		{
			if (character_->getCurrState() == "running")
			{
				if (!character_->getRunAttackState())
				{
					setCurrStamina(getCurrStamina() - getAttackStaminaCost());
				}
				character_->setRunAttackState(true);
				character_->setCurrRunAttackFrame(character_->getFrameSpeed() * elapsedTime);
				character_->spriteUpdateRunAttack(character_->getCurrSpriteSide());
			}
		}
		if ((attack_ && !character_->getAttackState() && getCurrStamina() >= getAttackStaminaCost()) || character_->getAttackState())
		{
			if (character_->getCurrState() != "running")
			{
				if (!character_->getAttackState())
				{
					setCurrStamina(getCurrStamina() - getAttackStaminaCost());
				}
				character_->setAttackState(true);
				character_->setCurrAttackFrame(character_->getFrameSpeed() * elapsedTime);
				character_->spriteUpdateAttack(character_->getCurrSpriteSide());
			}
		}
	}
	else if (character_->getLife())
	{
		character_->setCurrDeathFrame(character_->getFrameSpeed() * elapsedTime);
		character_->spriteUpdateDeath(character_->getCurrSpriteSide());
	}
	else
	{
		cout << "You are dead" << endl;
		delete this;
		exit(0);
	}
}

void Player::setPosition(float posX, float posY)
{
	character_->setPosition(posX, posY);
}

void Player::setCurrGravityAccel(float value)
{
	character_->setCurrGravityAccel(value);
}

void Player::setCurrJumpAccel(float value)
{
	character_->setCurrJumpAccel(value);
}

void Player::setJumpState(bool flag)
{
	character_->setJumpState(flag);
}

void Player::setState(string state)
{
	character_->setState(state);
}

void Player::interactionWithMap(Vector2f oldPlayerPosition, Vector2f newPlayerPosition, Map* map, float elapsedTime)
{
	Vector2f position = newPlayerPosition;

	for (int i = (newPlayerPosition.x - character_->getWidth() / 2 + map->getTileWidth() / 2) / map->getTileWidth(); i < (newPlayerPosition.x + character_->getWidth() / 2 + map->getTileWidth() / 2) / map->getTileWidth(); i++)
	{
		for (int j = (oldPlayerPosition.y - character_->getHeight()) / map->getTileHeight(); j < (oldPlayerPosition.y) / map->getTileHeight(); j++)
		{
			if (!map->getValue(j, i, ' ', map->getTileMapElse()))
			{
				position.x = oldPlayerPosition.x;
				break;
			}
		}
	}

	for (int i = (oldPlayerPosition.x - character_->getWidth() / 2 + map->getTileWidth() / 2) / map->getTileWidth(); i < (oldPlayerPosition.x + character_->getWidth() / 2 + map->getTileWidth() / 2) / map->getTileWidth(); i++)
	{
		for (int j = (newPlayerPosition.y - character_->getHeight()) / map->getTileHeight(); j < (newPlayerPosition.y) / map->getTileHeight(); j++)
		{
			if (!map->getValue(j, i, ' ', map->getTileMapElse()))
			{
				if (character_->getCurrState() == "jumping")
				{
					if (newPlayerPosition.y > j * map->getTileHeight() + map->getTileHeight() / 2)
					{
						character_->setState("falling");
						character_->setPosition(oldPlayerPosition.x, oldPlayerPosition.y);
						character_->setCurrGravityAccel(0);
						return;
					}
				}
				else
				{
					if (position.x == newPlayerPosition.x && newPlayerPosition.x != oldPlayerPosition.x)
					{
						character_->setState("running");
					}
					else
					{
						character_->setState("staying");
					}

					//position.y = j * map->getTileHeight() - character_->getLowerGap();
					//position.y = oldPlayerPosition.y;
					position.y = j * map->getTileHeight();
				}

				character_->setCurrJumpAccel(character_->getJumpForce());
				character_->setCurrGravityAccel(0);
				break;
			}
		}
	}

	character_->setPosition(position.x, position.y);

	if (character_->getCurrState() != "jumping" && character_->getCurrState() != "falling" && character_->getCurrState() != "staying" && position == newPlayerPosition)
	{
		character_->setState("falling");
	}
}

void Player::calculateVariables(float elapsedTime)
{
	if (character_->getCurrMana() < character_->getMaxMana())
	{
		character_->setCurrMana(character_->getCurrMana() + elapsedTime * character_->getManaRegen());

		if (character_->getCurrMana() > character_->getMaxMana())
		{
			character_->setCurrMana(character_->getMaxMana());
		}
	}

	if (character_->getCurrStamina() < character_->getMaxStamina())
	{
		character_->setCurrStamina(character_->getCurrStamina() + elapsedTime * character_->getStaminaRegen());

		if (character_->getCurrStamina() > character_->getMaxStamina())
		{
			character_->setCurrStamina(character_->getMaxStamina());
		}
	}

	if (character_->getCurrState() == "falling")
	{
		character_->setCurrGravityAccel(character_->getCurrGravityAccel() + character_->getGravity() * elapsedTime);
	}
	else if (character_->getCurrState() == "jumping")
	{
		character_->setCurrGravityAccel(character_->getCurrGravityAccel() + character_->getGravity() * elapsedTime);
		character_->setCurrJumpAccel(character_->getCurrJumpAccel() - character_->getCurrGravityAccel() * elapsedTime);
	}

	if (ddTimer_ > 0)
	{
		updateDoubleDamage(elapsedTime);
	}
}

void Player::setEnemyDamaged(bool flag)
{
	character_->setEnemyDamaged(flag);
}

void Player::setCurrHealthPoints(int healthPoints)
{
	character_->setCurrHealthPoints(healthPoints);
}

void Player::setLife(bool flag)
{
	character_->setLife(flag);
}

void Player::setHurt(bool flag)
{
	character_->setHurt(flag);
}

void Player::flyingShellsUpdateAndDraw(float elapsedTime, Map* map, RenderWindow* window)
{
	character_->flyingShellsUpdateAndDraw(elapsedTime, map, window);
}

void Player::setCurrStamina(float currStamina)
{
	character_->setCurrStamina(currStamina);
}

void Player::setCurrMana(float currMana)
{
	return character_->setCurrMana(currMana);
}

void Player::setDoubleDamage()
{
	if (ddTimer_ == 0)
	{
		ddTimer_ = ddDuration_;
	}
}

void Player::updateDoubleDamage(float elapsedTime)
{
	if (ddTimer_ > 0)
	{
		ddTimer_ -= elapsedTime;

		if (ddTimer_ < 0)
		{
			ddTimer_ = 0;
		}
	}
}

Vector2f Player::getCurrPosition()
{
	return character_->getSprite().getPosition();
}

Sprite Player::getSprite()
{
	return character_->getSprite();
}

int Player::getUpperGap()
{
	return character_->getUpperGap();
}

int Player::getLowerGap()
{
	return character_->getLowerGap();
}

int Player::getLeftGap()
{
	return character_->getLeftGap();
}

int Player::getRightGap()
{
	return character_->getRightGap();
}

int Player::getAttackRange()
{
	return character_->getAttackRange();
}

int Player::getAttackDamage()
{
	return character_->getAttackDamage();
}

int Player::getNumberOfAttackFrames()
{
	return character_->getNumberOfAttackFrames();
}

int Player::getWidth()
{
	return character_->getWidth();
}

int Player::getHeight()
{
	return character_->getHeight();
}

int Player::getCurrHealthPoints()
{
	return character_->getCurrHealthPoints();
}

int Player::getMaxHealthPoints()
{
	return character_->getMaxHealthPoints();
}

int Player::flyingShellsMakeDamage(Vector2f enemyPos, int enemyWidth, int enemyHeight)
{
	return character_->flyingShellsMakeDamage(enemyPos, enemyWidth, enemyHeight);
}

int Player::getCurrShellAmount()
{
	return character_->getCurrShellAmount();
}

int Player::getDDTimer()
{
	return (int)ddTimer_;
}

int Player::getJumpStaminaCost()
{
	return character_->getJumpStaminaCost();
}

int Player::getAttackStaminaCost()
{
	return character_->getAttackStaminaCost();
}

float Player::getGravity()
{
	return character_->getGravity();
}

float Player::getJumpForce()
{
	return character_->getJumpForce();
}

float Player::getCurrGravityAccel()
{
	return character_->getCurrGravityAccel();
}

float Player::getCurrJumpAccel()
{
	return character_->getCurrJumpAccel();
}

float Player::getCurrAttackFrame()
{
	return character_->getCurrAttackFrame();
}

float Player::getCurrMana()
{
	return character_->getCurrMana();
}

float Player::getCurrStamina()
{
	return character_->getCurrStamina();
}

float Player::getMaxMana()
{
	return character_->getMaxMana();
}

float Player::getMaxStamina()
{
	return character_->getMaxStamina();
}

string Player::getCurrState()
{
	return character_->getCurrState();
}

string Player::getCurrSpriteSide()
{
	return character_->getCurrSpriteSide();
}

string Player::getCurrShellName()
{
	return character_->getCurrShellName();
}

bool Player::getAttackState()
{
	return character_->getAttackState();
}

bool Player::getCharacterMadeDamage()
{
	return character_->getCharacterMadeDamage();
}

bool Player::getDamageDisabled()
{
	return character_->getDamageDisabled();
}

bool Player::getHurt()
{
	return character_->getHurt();
}