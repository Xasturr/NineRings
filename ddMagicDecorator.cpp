#include "ddMagicDecorator.h"

DDMagicDecorator::DDMagicDecorator(Shell* shell) : MagicDecorator(shell) {}

DDMagicDecorator::~DDMagicDecorator() 
{
	cout << "In DDMagicDecorator" << endl;
}

void DDMagicDecorator::setLife(bool flag)
{
	MagicDecorator::setLife(flag);
}

void DDMagicDecorator::setPosition(float posX, float posY)
{
	MagicDecorator::setPosition(posX, posY);
}

void DDMagicDecorator::setAngle(float angle)
{
	MagicDecorator::setAngle(angle);
}

void DDMagicDecorator::updateAndDraw(float elapsedTime, Map* map, RenderWindow* window)
{
	MagicDecorator::updateAndDraw(elapsedTime, map, window);
}

void DDMagicDecorator::spriteUpdate()
{
	MagicDecorator::spriteUpdate();
}

void DDMagicDecorator::setCurrFrame(float increase)
{
	MagicDecorator::setCurrFrame(increase);
}

void DDMagicDecorator::setExplosed(bool flag)
{
	MagicDecorator::setExplosed(flag);
}

bool DDMagicDecorator::getLife()
{
	return MagicDecorator::getLife();
}

bool DDMagicDecorator::getExplosed()
{
	return MagicDecorator::getExplosed();
}

Vector2f DDMagicDecorator::getPosition()
{
	return MagicDecorator::getPosition();
}

int DDMagicDecorator::getAlphaStrike()
{
	return MagicDecorator::getAlphaStrike() * 2;
}

string DDMagicDecorator::getSpriteSide()
{
	return MagicDecorator::getSpriteSide();
}