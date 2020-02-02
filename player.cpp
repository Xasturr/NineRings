#include "player.h"

Player::Player(string charName, float posX, float posY)
{
	leftPressed_ = false;
	rightPressed_ = false;
	upPressed_ = false;
	downPressed_ = false;

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

void Player::update()
{
	if (leftPressed_)
	{
		character_->setPosition(character_->getCurrPosition().x - character_->getMaxMoveSpeed(), character_->getCurrPosition().y);
		character_->setCurrRunFrame(character_->getFrameSpeed());
		character_->spriteUpdateRun("left");
	}
	else if (rightPressed_)
	{
		character_->setPosition(character_->getCurrPosition().x + character_->getMaxMoveSpeed(), character_->getCurrPosition().y);
		character_->setCurrRunFrame(character_->getFrameSpeed());
		character_->spriteUpdateRun("right");
	}
	else
	{
		character_->setCurrIdleFrame(character_->getFrameSpeed());
		character_->spriteUpdateIdle();
	}
}

Vector2f Player::getCharacterPosition()
{
	return character_->getSprite().getPosition();
}

Sprite Player::getSprite()
{
	return character_->getSprite();
}