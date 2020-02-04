#include "player.h"

Player::Player(string charName, float posX, float posY)
{
	leftPressed_ = false;
	rightPressed_ = false;
	upPressed_ = false;
	downPressed_ = false;
	attack_ = false;
	runAttack_ = false;

	charName_ = charName;

	if (charName_ == "Character1")
	{
		character_ = new Character1(posX, posY);
		//TankLight* tankLight = new TankLight;
		//tank_ = tankLight;
		//cout << "player: lightTank" << endl;
	}

	character_->setPosition(posX, posY);
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

void Player::update(float elapsedTime)
{
	cout << character_->getCurrState() << endl;

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
		character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y + character_->getCurrGravityAccel() * elapsedTime);
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

Vector2f Player::getCharacterPosition()
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

string Player::getCurrState()
{
	return character_->getCurrState();
}