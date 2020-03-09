#include "shellFireBall.h"

ShellFireBall::ShellFireBall(float posX, float posY, float angle, string spriteSide)
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

	texture1_.loadFromFile("./textures/skills/FB00_nyknck/FB001.png");
	texture2_.loadFromFile("./textures/skills/FB00_nyknck/FB002.png");
	texture3_.loadFromFile("./textures/skills/FB00_nyknck/FB003.png");
	texture4_.loadFromFile("./textures/skills/FB00_nyknck/FB004.png");
	texture5_.loadFromFile("./textures/skills/FB00_nyknck/FB005.png");

	textureExplosion_.loadFromFile("./textures/explosions/1/explosion-6.png");

	sprite_.setTexture(texture1_);
	sprite_.setPosition(position_);
	sprite_.setRotation(angle_ - 90);

	spriteSide_ = spriteSide;

	sprite_.setOrigin(texture1_.getSize().x - 44, texture1_.getSize().y / 2);
	if (spriteSide_ == "left")
	{
		//sprite_.setScale(-1.f, 1.f);
	}
	//else
	//{
	//	sprite_.setOrigin(texture1_.getSize().x, texture1_.getSize().y / 2);
	//}
}

ShellFireBall::~ShellFireBall()
{
	cout << "In shellFireBall distructor" << endl;
}

void ShellFireBall::setLife(bool flag)
{
	life_ = flag;
}

void ShellFireBall::setPosition(float posX, float posY)
{
	position_.x = posX;
	position_.y = posY;
}

void ShellFireBall::setAngle(float angle)
{
	angle_ = angle;
}

void ShellFireBall::updateAndDraw(float elapsedTime, Map* map, RenderWindow* window)
{
	if (!explosed_)
	{
		position_.y -= (speed_ * cos(angle_ * 3.14 / 180)) * elapsedTime;
		position_.x += (speed_ * sin(angle_* 3.14 / 180)) * elapsedTime;

		int	gap = 0;
		int gap2 = 0;

		if (spriteSide_ == "right")
		{
			gap = map->getTileWidth() / 2;
		}
		else
		{
			gap2 = map->getTileWidth() / 2;
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

void ShellFireBall::spriteUpdate()
{
	if (int(currentFrame_) == 1)
		sprite_.setTexture(texture1_);
	else if (int(currentFrame_) == 2)
		sprite_.setTexture(texture2_);
	else if (int(currentFrame_) == 3)
		sprite_.setTexture(texture3_);
	else if (int(currentFrame_) == 4)
		sprite_.setTexture(texture4_);
	else
		sprite_.setTexture(texture5_);
}

void ShellFireBall::spriteExplosionUpdate()
{
	if (currentExplosionFrame_ == 1)
	{
		sprite_.setTexture(textureExplosion_);
	}

	if (int(currentExplosionFrame_) == 1)
		sprite_.setTextureRect(IntRect(92, 0, 50, 48));
	else if (int(currentExplosionFrame_) == 2)
		sprite_.setTextureRect(IntRect(142, 0, 47, 48));
	else if (int(currentExplosionFrame_) == 3)
		sprite_.setTextureRect(IntRect(190, 0, 48, 48));
	else if (int(currentExplosionFrame_) == 4)
		sprite_.setTextureRect(IntRect(238, 0, 48, 48));
	else if (int(currentExplosionFrame_) == 5)
		sprite_.setTextureRect(IntRect(286, 0, 49, 48));
	else 
		sprite_.setTextureRect(IntRect(335, 0, 49, 48));
}

void ShellFireBall::setCurrFrame(float increase)
{
	currentFrame_ += increase * 20;

	if (currentFrame_ > numberOfFrames_)
	{
		currentFrame_ = 1;
	}
}

void ShellFireBall::setCurrExplosionFrame(float increase)
{
	currentExplosionFrame_ += increase * 15;

	if (currentExplosionFrame_ > numberOfExplosionFrames_)
	{
		life_ = false;
	}
}

void ShellFireBall::setExplosed(bool flag)
{
	explosed_ = flag;
}

bool ShellFireBall::getLife()
{
	return life_;
}

bool ShellFireBall::getExplosed()
{
	return explosed_;
}

Vector2f ShellFireBall::getPosition()
{
	return position_;
}

int ShellFireBall::getAlphaStrike()
{
	return alphaStrike_;
}

string ShellFireBall::getSpriteSide()
{
	return spriteSide_;
}