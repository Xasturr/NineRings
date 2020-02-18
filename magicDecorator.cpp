#include "magicDecorator.h"

MagicDecorator::MagicDecorator(Shell* shell)
{
	shell_ = shell;
}

MagicDecorator::~MagicDecorator()
{
	cout << "In Magic Decorator" << endl;
	delete shell_;
}

void MagicDecorator::setLife(bool flag)
{
	if (shell_ != NULL)
	{
		shell_->setLife(flag);
	}
}

void MagicDecorator::setPosition(float posX, float posY)
{
	if (shell_ != NULL)
	{
		shell_->setPosition(posX, posY);
	}
}

void MagicDecorator::setAngle(float angle)
{
	if (shell_ != NULL)
	{
		shell_->setAngle(angle);
	}
}

void MagicDecorator::updateAndDraw(float elapsedTime, Map* map, RenderWindow* window)
{
	if (shell_ != NULL)
	{
		shell_->updateAndDraw(elapsedTime, map, window);
	}
}

void MagicDecorator::spriteUpdate()
{
	if (shell_ != NULL)
	{
		shell_->spriteUpdate();
	}
}

void MagicDecorator::setCurrFrame(float increase)
{
	if (shell_ != NULL)
	{
		shell_->setCurrFrame(increase);
	}
}

void MagicDecorator::setExplosed(bool flag)
{
	if (shell_ != NULL)
	{
		shell_->setExplosed(flag);
	}
}

bool MagicDecorator::getLife()
{
	if (shell_ != NULL)
	{
		return shell_->getLife();
	}
}

bool MagicDecorator::getExplosed()
{
	if (shell_ != NULL)
	{
		return shell_->getExplosed();
	}
}

Vector2f MagicDecorator::getPosition()
{
	if (shell_ != NULL)
	{
		return shell_->getPosition();
	}
}

int MagicDecorator::getAlphaStrike()
{
	if (shell_ != NULL)
	{
		return shell_->getAlphaStrike();
	}
}

string MagicDecorator::getSpriteSide()
{
	if (shell_ != NULL)
	{
		return shell_->getSpriteSide();
	}
}