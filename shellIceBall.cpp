#include "shellIceBall.h"

ShellIceBall::ShellIceBall(float posX, float posY, float angle, string spriteSide)
{
	position_.x = posX;
	position_.y = posY;

	life_ = true;
	explosed_ = false;

	angle_ = angle;
	alphaStrike_ = 500;
	speed_ = 360;
	currentFrame_ = 1;
	currentExplosionFrame_ = 1;
	numberOfFrames_ = 60;
	numberOfExplosionFrames_ = 6;

	texture_.loadFromFile("./textures/skills/1/Small_Iceball_9x24.png");

	textureExplosion_.loadFromFile("./textures/explosions/1/explosion-7.png");

	sprite_.setTexture(texture_);
	sprite_.setPosition(position_);
	sprite_.setRotation(angle_ - 180);
	sprite_.setScale(2.4, 2.4);

	spriteSide_ = spriteSide;

	sprite_.setOrigin(4, 0);

	if (spriteSide_ == "left")
	{
		//sprite_.setOrigin(18, 0);
		//sprite_.setScale(-1.f, 1.f);
	}
	else
	{
		//sprite_.setOrigin(18, 0);
		//sprite_.setOrigin(texture1_.getSize().x, texture1_.getSize().y / 2);
	}
}

ShellIceBall::~ShellIceBall()
{
	cout << "In ShellIceBall distructor" << endl;
}

void ShellIceBall::setLife(bool flag)
{
	life_ = flag;
}

void ShellIceBall::setPosition(float posX, float posY)
{
	position_.x = posX;
	position_.y = posY;
}

void ShellIceBall::setAngle(float angle)
{
	angle_ = angle;
}

void ShellIceBall::updateAndDraw(float elapsedTime, Map* map, RenderWindow* window)
{
	if (!explosed_)
	{
		position_.y -= (speed_ * cos(angle_ * 3.14 / 180)) * elapsedTime;
		position_.x += (speed_ * sin(angle_ * 3.14 / 180)) * elapsedTime;

		int	gap = 0;
		int gap2 = 0;

		if (spriteSide_ == "right")
		{
			gap = map->getTileWidth() / 2 * 2;
		}
		else
		{
			//gap2 = map->getTileWidth() / 1;
		}

		for (int i = (position_.x + gap2) / map->getTileWidth(); i < (position_.x + gap + gap2) / map->getTileWidth(); i++)
		{
			for (int j = position_.y / map->getTileHeight(); j < (position_.y) / map->getTileHeight(); j++)
			{
				if (!map->getCollision(j, i, ' '))
				{
					explosed_ = true;
					return;
				}
			}
		}

		sprite_.setPosition(position_);
		spriteUpdate();
		setCurrFrame(elapsedTime);
	}
	else
	{
		spriteExplosionUpdate();
		setCurrExplosionFrame(elapsedTime);
	}
	window->draw(sprite_);
}

void ShellIceBall::spriteUpdate()
{
	int width = 8;
	int height = 23;
	int rectTop = 0;
	int rectLeft = 0;

	if ((int)currentFrame_ <= 10)
	{
		rectTop = 0;
	}
	else if ((int)currentFrame_ <= 20)
	{
		rectTop = 24;
	}
	else if ((int)currentFrame_ <= 30)
	{
		rectTop = 49;
	}
	else if ((int)currentFrame_ <= 40)
	{
		rectTop = 72;
	}
	else if ((int)currentFrame_ <= 50)
	{
		rectTop = 96;
	}
	else
	{
		rectTop = 120;
	}

	if ((int)currentFrame_ % 10 == 1)
	{
		rectLeft = 0;
	}
	else if ((int)currentFrame_ % 10 == 2)
	{
		rectLeft = 9;
	}
	else if ((int)currentFrame_ % 10 == 3)
	{
		rectLeft = 18;
	}
	else if ((int)currentFrame_ % 10 == 4)
	{
		rectLeft = 27;
	}
	else if ((int)currentFrame_ % 10 == 5)
	{
		rectLeft = 36;
	}
	else if ((int)currentFrame_ % 10 == 6)
	{
		rectLeft = 45;
	}
	else if ((int)currentFrame_ % 10 == 7)
	{
		rectLeft = 54;
	}
	else if ((int)currentFrame_ % 10 == 8)
	{
		rectLeft = 63;
	}
	else if ((int)currentFrame_ % 10 == 9)
	{
		rectLeft = 72;
	}
	else
	{
		rectLeft = 81;
	}

	sprite_.setTextureRect(IntRect(rectLeft, rectTop, width, height));
}

void ShellIceBall::spriteExplosionUpdate()
{
	if (currentExplosionFrame_ == 1)
	{
		sprite_.setScale(1, 1);
		sprite_.setOrigin(25, 0);
		sprite_.setTexture(textureExplosion_);
	}

	if (int(currentExplosionFrame_) == 1)
		sprite_.setTextureRect(IntRect(92, 0, 44, 48));
	else if (int(currentExplosionFrame_) == 2)
		sprite_.setTextureRect(IntRect(136, 0, 48, 48));
	else if (int(currentExplosionFrame_) == 3)
		sprite_.setTextureRect(IntRect(184, 0, 49, 48));
	else if (int(currentExplosionFrame_) == 4)
		sprite_.setTextureRect(IntRect(233, 0, 49, 48));
	else if (int(currentExplosionFrame_) == 5)
		sprite_.setTextureRect(IntRect(282, 0, 48, 48));
	else
		sprite_.setTextureRect(IntRect(339, 0, 49, 48));
}

void ShellIceBall::setCurrFrame(float increase)
{
	currentFrame_ += increase * 90;

	if (currentFrame_ >= numberOfFrames_)
	{
		currentFrame_ = 1;
	}
}

void ShellIceBall::setCurrExplosionFrame(float increase)
{
	currentExplosionFrame_ += increase * 15;

	if (currentExplosionFrame_ > numberOfExplosionFrames_)
	{
		life_ = false;
	}
}

void ShellIceBall::setExplosed(bool flag)
{
	explosed_ = flag;
}

void ShellIceBall::setAlphaStrike(int alphaStrike)
{
	alphaStrike_ = alphaStrike;
}

void ShellIceBall::setIsDoubleDamage(bool flag)
{
	doubleDamage_ = flag;
}

bool ShellIceBall::getLife()
{
	return life_;
}

bool ShellIceBall::getExplosed()
{
	return explosed_;
}

bool ShellIceBall::isDoubleDamage()
{
	return doubleDamage_;
}

Vector2f ShellIceBall::getPosition()
{
	return position_;
}

int ShellIceBall::getAlphaStrike()
{
	return alphaStrike_;
}

string ShellIceBall::getSpriteSide()
{
	return spriteSide_;
}