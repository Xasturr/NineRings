#include "settings.h"

Settings::Settings()
{
	moveUp_ = SFML_KEY::W;
	moveLeft_ = SFML_KEY::A;
	moveRight_ = SFML_KEY::D;
	shoot_ = SFML_KEY::P;
	attack_ = SFML_KEY::Space;
}

void Settings::setMoveUp(char c)
{
	if (c >= 65 && c <= 90 && isFree(c))
		moveUp_ = c - 65;
}

void Settings::setMoveLeft(char c)
{
	if (c >= 65 && c <= 90 && isFree(c))
		moveLeft_ = c - 65;
}

void Settings::setMoveRight(char c)
{
	if (c >= 65 && c <= 90 && isFree(c))
		moveRight_ = c - 65;
}

void Settings::setShoot(char c)
{
	if (c >= 65 && c <= 90 && isFree(c))
		shoot_ = c - 65;
}

void Settings::setAttack(char c)
{
	if (c >= 65 && c <= 90 && isFree(c))
		shoot_ = c - 65;
}

void Settings::saveSattings()
{

}

int Settings::getMoveUp()
{
	return moveUp_;
}

int Settings::getMoveLeft()
{
	return moveLeft_;
}

int Settings::getMoveRight()
{
	return moveRight_;
}

int Settings::getShoot()
{
	return shoot_;
}

int Settings::getAttack()
{
	return attack_;
}

bool Settings::isFree(char c)
{
	if (moveUp_ == c - 65)
		return false;
	if (moveLeft_ == c - 65)
		return false;
	if (moveRight_ == c - 65)
		return false;
	if (shoot_ == c - 65)
		return false;

	return true;
}