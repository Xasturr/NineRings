#include "player.h"

Player::Player(string charName, float posX, float posY)
{
	leftPressed_ = false;
	rightPressed_ = false;
	upPressed_ = false;
	downPressed_ = false;
	attack_ = false;
	halfDead_ = false;
	runAttack_ = false;
	shoot_ = false;
	doubleDamage_ = false;
	newExp_ = false;
	newLvl_ = false;
	newGame_ = true;

	charName_ = charName;
	currShellName_ = Shells::fireBallShell_name;

	ddTimer_ = 0;
	ddDuration_ = 5;
	exp_ = 0;
	lvl_ = 1;
	levelPoints_ = 0;
	treasurePoints_ = 0;
	perksInfo_.heartPlusPerkBonus_ = 200;
	perksInfo_.heartPlusPerkLevel_ = 0;
	perksInfo_.chestArmorPerkBonus_ = 10;
	perksInfo_.chestArmorPerkLevel_ = 0;
	perksInfo_.fairyWandPerkBonus_ = 200;
	perksInfo_.fairyWandPerkLevel_ = 0;
	perksInfo_.vampireDraculaPerkBonus_ = 0;
	perksInfo_.vampireDraculaPerkLevel_ = 0;
	perksInfo_.foamyDiscPerkLevel_ = 0;
	perksInfo_.halfDeadPerkLevel_ = 0;
	perksInfo_.halfDeadPerkBonus_ = 0;
	perksInfo_.iceBallPerkLevel_ = 0;
	perksInfo_.jugglerPerkLevel_ = 0;
	perksInfo_.jugglerPerkBonus_ = 0;
	perksInfo_.tripleScratchesPerkLevel_ = 0;
	perksInfo_.tripleScratchesPerkBonus_ = 0;
	perksInfo_.drippingBladePerkLevel_ = 0;
	perksInfo_.drippingBladePerkBonus_ = 0;

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

void Player::activateHalfDeadPerk()
{
	if (perksInfo_.halfDeadPerkLevel_ > 0)
	{
		halfDead_ = true;
	}
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

void Player::stopHalfDeadPerk()
{
	halfDead_ = false;
}

void Player::update(float elapsedTime, RenderWindow* window)
{
	if (character_->getCurrHealthPoints() > 0)
	{
		updateLevel(window);

		if (character_->getHurt())
		{
			attack_ = false;
			character_->setCurrHurtFrame(character_->getFrameSpeed() * elapsedTime);
			character_->spriteUpdateHurt(character_->getCurrSpriteSide());
			return;
		}
		else if (halfDead_)
		{
			if (character_->getCurrMana() > 0 && character_->getCurrHealthPoints() < character_->getMaxHealthPoints())
			{
				float dx = elapsedTime * (float)perksInfo_.halfDeadPerkBonus_;
				float currMana = character_->getCurrMana();
				if (dx <= currMana && dx <= character_->getMaxHealthPoints() - character_->getCurrHealthPoints())
				{
		/*			cout << "dx: " << dx << endl;
					cout << character_->getCurrMana() << endl;
					cout << character_->getCurrHealthPoints() << endl;*/
					character_->setCurrMana(character_->getCurrMana() - dx);
					character_->setCurrHealthPoints(character_->getCurrHealthPoints() + dx);
					//cout << character_->getCurrMana() << endl;
					//cout << character_->getCurrHealthPoints() << endl << endl;
				}
				else if (dx > currMana)
				{
					if (currMana > character_->getMaxHealthPoints() - character_->getCurrHealthPoints())
					{
						character_->setCurrHealthPoints(character_->getMaxHealthPoints());
					}
					else
					{
						character_->setCurrHealthPoints(character_->getCurrHealthPoints() + currMana);
					}
					character_->setCurrMana(0);
				}
				else if (dx > character_->getMaxHealthPoints() - character_->getCurrHealthPoints())
				{
					float dy = character_->getMaxHealthPoints() - character_->getCurrHealthPoints();
					character_->setCurrHealthPoints(character_->getMaxHealthPoints());
					if (currMana < dx)
					{
						character_->setCurrMana(0);
					}
					else
					{
						character_->setCurrMana(currMana - dy);
					}
				}
			}
		}

		//if (character_->getCurrShotCoolDown() > 0)
		//{
		//	character_->setCurrShotCoolDown(character_->getCurrShotCoolDown() - elapsedTime);
		//	
		//	if (character_->getCurrShotCoolDown() < 0)
		//	{
		//		character_->setCurrShotCoolDown(0);
		//	}
		//}

		if (shoot_ && character_->getCurrShotCoolDown() == 0 && character_->getCurrShellAmount() > 0 && getCurrMana() >= 40)
		{
			setCurrMana(getCurrMana() - 40);

			if (ddTimer_ > 0)
			{
				Shell* shell = character_->addFlyingShell(currShellName_, true, character_->getCurrShellAngle());
				if (perksInfo_.jugglerPerkLevel_)
				{
					shell->setAlphaStrike(shell->getAlphaStrike() / 2 + perksInfo_.jugglerPerkBonus_);
				}
				if (character_->getCurrHealthPoints() * 2 <= character_->getMaxHealthPoints() && getTripleScratchesPerkLevel())
				{
					shell->setAlphaStrike(shell->getAlphaStrike() / 2 + (float)shell->getAlphaStrike() / 200 * (float)getTripleScratchesPerkBonus());
				}
			}
			else
			{
				Shell* shell = character_->addFlyingShell(currShellName_, character_->getCurrShellAngle());
				if (perksInfo_.jugglerPerkLevel_)
				{
					shell->setAlphaStrike(shell->getAlphaStrike() + perksInfo_.jugglerPerkBonus_);
				}
				if (character_->getCurrHealthPoints() * 2 <= character_->getMaxHealthPoints())
				{
					shell->setAlphaStrike(shell->getAlphaStrike() + (float)shell->getAlphaStrike() / 100 * (float)getTripleScratchesPerkBonus());
				}
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
				if (leftPressed_ || rightPressed_)
				{
					character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y - character_->getGravity() * elapsedTime);
				}
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
			character_->spriteUpdateIdle(character_->getCurrSpriteSide());
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
					if (oldPlayerPosition.y >= j * map->getTileHeight() + map->getTileHeight())
					{
						character_->setState("falling");
						cout << oldPlayerPosition.y - newPlayerPosition.y << endl;
						character_->setPosition(oldPlayerPosition.x, 2 * oldPlayerPosition.y - newPlayerPosition.y);
						character_->setCurrGravityAccel(0);
						cout << "I" << endl;
						return;
					}
				}
				else
				{
					if (position.x == newPlayerPosition.x && newPlayerPosition.x != oldPlayerPosition.x)
					{
						character_->setState("running");
						position.y = j * map->getTileHeight();
					}
					else
					{
						character_->setState("staying");
						position.y = j * map->getTileHeight();
					}

					//position.y = j * map->getTileHeight() - character_->getLowerGap();
					//position.y = oldPlayerPosition.y;
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
	//if (character_->getCurrMana() < character_->getMaxMana())
	//{
	//	character_->setCurrMana(character_->getCurrMana() + elapsedTime * character_->getManaRegen());

	//	if (character_->getCurrMana() > character_->getMaxMana())
	//	{
	//		character_->setCurrMana(character_->getMaxMana());
	//	}
	//}

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

	if (character_->getCurrShotCoolDown() > 0)
	{
		character_->setCurrShotCoolDown(character_->getCurrShotCoolDown() - elapsedTime);

		if (character_->getCurrShotCoolDown() < 0)
		{
			character_->setCurrShotCoolDown(0);
		}
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

void Player::setCurrExp(int exp)
{
	exp_ = exp;
	newExp_ = true;
}

void Player::setHeartPlusPerk()
{
	if (levelPoints_ >= 1)
	{
		character_->setMaxHealthPoints(character_->getMaxHealthPoints() + perksInfo_.heartPlusPerkBonus_);
		levelPoints_ -= 1;
		perksInfo_.heartPlusPerkLevel_ += 1;
	}
}

void Player::setChestArmorPerk()
{
	if (levelPoints_ >= 1)
	{
		character_->setArmor(character_->getArmor() + perksInfo_.chestArmorPerkBonus_);
		levelPoints_ -= 1;
		perksInfo_.chestArmorPerkLevel_ += 1;
	}
}

void Player::setFairyWandPerk()
{
	if (levelPoints_ >= 1)
	{
		character_->setMaxMana(character_->getMaxMana() + perksInfo_.fairyWandPerkBonus_);
		levelPoints_ -= 1;
		perksInfo_.fairyWandPerkLevel_ += 1;
	}
}

void Player::setFoamyDiscPerk()
{
	if (levelPoints_ >= 2 && perksInfo_.foamyDiscPerkLevel_ == 0)
	{
		levelPoints_ -= 2;
		perksInfo_.foamyDiscPerkLevel_ = 1;
	}
}

void Player::setIceBallPerk()
{
	if (levelPoints_ >= 2 && perksInfo_.iceBallPerkLevel_ == 0)
	{
		levelPoints_ -= 2;
		perksInfo_.iceBallPerkLevel_ = 1;
	}
}

void Player::setJugglerPerk()
{
	if (levelPoints_ >= 2 && perksInfo_.jugglerPerkLevel_ < 3)
	{
		levelPoints_ -= 2;
		setJugglerPerkLevel(perksInfo_.jugglerPerkLevel_ + 1);
	}
}

void Player::setDrippingBladePerk()
{
	if (levelPoints_ >= 2 && perksInfo_.drippingBladePerkLevel_ < 3)
	{
		levelPoints_ -= 2;
		setDrippingBladePerkLevel(perksInfo_.drippingBladePerkLevel_ + 1);
	}
}

void Player::setHalfDeadPerk()
{
	if (levelPoints_ >= 3 && perksInfo_.halfDeadPerkLevel_ == 0)
	{
		levelPoints_ -= 3;
		setHalfDeadPerksLevel(perksInfo_.halfDeadPerkLevel_ + 1);
	}
}

void Player::updateJugglerPerkBonus()
{
	if (perksInfo_.jugglerPerkLevel_ == 1)
	{
		perksInfo_.jugglerPerkBonus_ = 50;
	}
	else if (perksInfo_.jugglerPerkLevel_ == 2)
	{
		perksInfo_.jugglerPerkBonus_ = 100;
	}
	else
	{
		perksInfo_.jugglerPerkBonus_ = 150;
	}
}

void Player::updateDrippingBladePerkBonus()
{
	if (perksInfo_.drippingBladePerkLevel_ == 1)
	{
		perksInfo_.drippingBladePerkBonus_ = 100;
	}
	else if (perksInfo_.drippingBladePerkLevel_ == 2)
	{
		perksInfo_.drippingBladePerkBonus_ = 175;
	}
	else
	{
		perksInfo_.drippingBladePerkBonus_ = 250;
	}
}

void Player::updateHalfDeadPerkBonus()
{
	if (perksInfo_.halfDeadPerkLevel_ == 1)
	{
		perksInfo_.halfDeadPerkBonus_ = 150;
	}
}

void Player::updateVampireDraculaPerkBonus()
{
	if (perksInfo_.vampireDraculaPerkLevel_ == 1)
	{
		perksInfo_.vampireDraculaPerkBonus_ = 15;
	}
}

void Player::updateTripleScratchesPerkBonus()
{
	if (perksInfo_.tripleScratchesPerkLevel_ == 1)
	{
		perksInfo_.tripleScratchesPerkBonus_ = 30;
	}
}

void Player::setVampireDraculaPerk()
{
	if (levelPoints_ >= 3 && perksInfo_.vampireDraculaPerkLevel_ == 0)
	{
		levelPoints_ -= 3;
		setVampireDraculaPerkLevel(perksInfo_.vampireDraculaPerkLevel_ + 1);
	}
}

void Player::setTripleScratchesPerk()
{
	if (levelPoints_ >= 3 && perksInfo_.tripleScratchesPerkLevel_ == 0)
	{
		levelPoints_ -= 3;
		setTripleScratchesPerkLevel(perksInfo_.tripleScratchesPerkLevel_ + 1);
	}
}

void Player::setCurrLevel(int level)
{
	lvl_ = level;
}

void Player::setMaxMana(int maxMana)
{
	character_->setMaxMana(maxMana);
}

void Player::setMaxHealthPoints(int maxHp)
{
	character_->setMaxHealthPoints(maxHp);
}

void Player::setMaxStamina(int maxStamina)
{
	character_->setMaxStamina(maxStamina);
}

void Player::setLevelPoints(int levelPts)
{
	levelPoints_ = levelPts;
}

void Player::setNewGame(bool flag)
{
	newGame_ = flag;
}

void Player::setCurrShellName(int shellName)
{
	if (perksInfo_.iceBallPerkLevel_ == 1 && shellName == Shells::iceBallShell_name)
	{
		currShellName_ = shellName;
	}
	else if (perksInfo_.foamyDiscPerkLevel_ == 1 && shellName == Shells::foamyDiscShell_name)
	{
		currShellName_ = shellName;
	}
	else if (shellName == Shells::fireBallShell_name)
	{
		currShellName_ = shellName;
	}
}

void Player::setIceBallPerkLevel(int level)
{
	perksInfo_.iceBallPerkLevel_ = level;
}

void Player::setFoamyDiscPerkLevel(int level)
{
	perksInfo_.foamyDiscPerkLevel_ = level;
}

void Player::setJugglerPerkLevel(int level)
{
	perksInfo_.jugglerPerkLevel_ = level;
	updateJugglerPerkBonus();
}

void Player::setDrippingBladePerkLevel(int level)
{
	perksInfo_.drippingBladePerkLevel_ = level;
	updateDrippingBladePerkBonus();
}

void Player::setHalfDeadPerksLevel(int level)
{
	perksInfo_.halfDeadPerkLevel_ = level;
	updateHalfDeadPerkBonus();
}

void Player::setVampireDraculaPerkLevel(int level)
{
	perksInfo_.vampireDraculaPerkLevel_ = level;
	updateVampireDraculaPerkBonus();
}

void Player::setTripleScratchesPerkLevel(int level)
{
	perksInfo_.tripleScratchesPerkLevel_ = level;
	updateTripleScratchesPerkBonus();
}

void Player::updateLevel(RenderWindow* window)
{
	if (newExp_)
	{
		newExp_ = false;

		if (exp_ >= 100 && lvl_ == 1)
		{
			newLvl_ = true;
			lvl_ = 2;
			levelPoints_ += 1;
			cout << "New Level! 2" << endl;
		}
		if (exp_ >= 200 && lvl_ == 2)
		{
			newLvl_ = true;
			lvl_ = 3;
			levelPoints_ += 1;
			cout << "New Level! 3" << endl;
		}
		if (exp_ >= 300 && lvl_ == 3)
		{
			newLvl_ = true;
			lvl_ = 4;
			levelPoints_ += 1;
			cout << "New Level! 4" << endl;
		}
		if (exp_ >= 400 && lvl_ == 4)
		{
			newLvl_ = true;
			lvl_ = 5;
			levelPoints_ += 1;
			cout << "New Level! 5" << endl;
		}
		if (exp_ >= 500 && lvl_ == 5)
		{
			newLvl_ = true;
			lvl_ = 6;
			levelPoints_ += 1;
			cout << "New Level! 6" << endl;
		}
		if (exp_ >= 600 && lvl_ == 6)
		{
			newLvl_ = true;
			lvl_ = 7;
			levelPoints_ += 1;
			cout << "New Level! 7" << endl;
		}
		if (exp_ >= 700 && lvl_ == 7)
		{
			newLvl_ = true;
			lvl_ = 8;
			levelPoints_ += 1;
			cout << "New Level! 8" << endl;
		}
		if (exp_ >= 800 && lvl_ == 8)
		{
			newLvl_ = true;
			lvl_ = 9;
			levelPoints_ += 1;
			cout << "New Level! 9" << endl;
		}
		if (exp_ >= 900 && lvl_ == 9)
		{
			newLvl_ = true;
			lvl_ = 10;
			levelPoints_ += 1;
			cout << "New Level! 10" << endl;
		}
		if (exp_ >= 1000 && lvl_ == 10)
		{
			newLvl_ = true;
			lvl_ = 11;
			levelPoints_ += 1;
			cout << "New Level! 11" << endl;
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
	if (getCurrDrippingBladePerkLevel())
	{
		return character_->getAttackDamage() + perksInfo_.drippingBladePerkBonus_;
	}
	else
	{
		return character_->getAttackDamage();
	}
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

float Player::getCurrHealthPoints()
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

int Player::getCurrExp()
{
	return exp_;
}

int Player::getCurrLevel()
{
	return lvl_;
}

int Player::getLevelPoints()
{
	return levelPoints_;
}

int Player::getArmor()
{
	return character_->getArmor();
}

int Player::getCurrVampireDraculaPerkLevel()
{
	return perksInfo_.vampireDraculaPerkLevel_;
}

int Player::getVampireDraculaPerkBonus()
{
	return perksInfo_.vampireDraculaPerkBonus_;
}

int Player::getTreasurePoints()
{
	return treasurePoints_;
}

int Player::getCurrChestArmorPerkLevel()
{
	return perksInfo_.chestArmorPerkLevel_;
}

int Player::getCurrIceBallPerkLevel()
{
	return perksInfo_.iceBallPerkLevel_;
}

int Player::getCurrFoamyDiscPerkLevel()
{
	return perksInfo_.foamyDiscPerkLevel_;
}

int Player::getJumpStaminaCost()
{
	return character_->getJumpStaminaCost();
}

int Player::getAttackStaminaCost()
{
	return character_->getAttackStaminaCost();
}

int Player::getCurrShellName()
{
	return character_->getCurrShellName();
}

int Player::getCurrJugglerPerkLevel()
{
	return perksInfo_.jugglerPerkLevel_;
}

int Player::getCurrJugglerPerkBonus()
{
	if (perksInfo_.jugglerPerkLevel_ == 0)
	{
		return 0;
	}
	else if (perksInfo_.jugglerPerkLevel_ == 1)
	{
		return 100;
	}
	else if (perksInfo_.jugglerPerkLevel_ == 2)
	{
		return 150;
	}
	else
	{
		return 200;
	}
}

int Player::getCurrDrippingBladePerkLevel()
{
	return perksInfo_.drippingBladePerkLevel_;
}

int Player::getCurrHalfDeadPerkLevel()
{
	return perksInfo_.halfDeadPerkLevel_;
}

int Player::getVampireDraculaPerkLevel()
{
	return perksInfo_.vampireDraculaPerkLevel_;
}

int Player::getTripleScratchesPerkLevel()
{
	return perksInfo_.tripleScratchesPerkLevel_;
}

int Player::getTripleScratchesPerkBonus()
{
	return perksInfo_.tripleScratchesPerkBonus_;
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

bool Player::isNewLevel()
{
	return newLvl_;
}

bool Player::isNewGame()
{
	return newGame_;
}

struct perksInfo Player::getPerksInfo()
{
	return perksInfo_;
}