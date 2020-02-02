#include "character1.h"

Character1::Character1(float posX, float posY)
{
	position_.x = posX;
	position_.y = posY;

	textureIdle1_.loadFromFile("./textures/tiles/characters/knight/Idle/idle1.png");
	textureIdle2_.loadFromFile("./textures/tiles/characters/knight/Idle/idle2.png");
	textureIdle3_.loadFromFile("./textures/tiles/characters/knight/Idle/idle3.png");
	textureIdle4_.loadFromFile("./textures/tiles/characters/knight/Idle/idle4.png");
	textureIdle5_.loadFromFile("./textures/tiles/characters/knight/Idle/idle5.png");
	textureIdle6_.loadFromFile("./textures/tiles/characters/knight/Idle/idle6.png");
	textureIdle7_.loadFromFile("./textures/tiles/characters/knight/Idle/idle7.png");
	textureIdle8_.loadFromFile("./textures/tiles/characters/knight/Idle/idle8.png");
	textureIdle9_.loadFromFile("./textures/tiles/characters/knight/Idle/idle9.png");
	textureIdle10_.loadFromFile("./textures/tiles/characters/knight/Idle/idle10.png");
	textureIdle11_.loadFromFile("./textures/tiles/characters/knight/Idle/idle11.png");
	textureIdle12_.loadFromFile("./textures/tiles/characters/knight/Idle/idle12.png");

	textureRun1_.loadFromFile("./textures/tiles/characters/knight/Run/run1.png");
	textureRun2_.loadFromFile("./textures/tiles/characters/knight/Run/run2.png");
	textureRun3_.loadFromFile("./textures/tiles/characters/knight/Run/run3.png");
	textureRun4_.loadFromFile("./textures/tiles/characters/knight/Run/run4.png");
	textureRun5_.loadFromFile("./textures/tiles/characters/knight/Run/run5.png");
	textureRun6_.loadFromFile("./textures/tiles/characters/knight/Run/run6.png");
	textureRun7_.loadFromFile("./textures/tiles/characters/knight/Run/run7.png");
	textureRun8_.loadFromFile("./textures/tiles/characters/knight/Run/run8.png");

	sprite_.setTexture(textureIdle1_);
	sprite_.setOrigin(textureRun1_.getSize().x / 2, textureRun1_.getSize().y / 2);

	life_ = true;

	maxMoveSpeed = 2;
	currentIdleFrame_ = 1;
	currentRunFrame_ = 1;
	numberOfIdleFrames_ = 12;
	numberOfRunFrames_ = 8;
	frameSpeed_ = 0.1;

	currSpriteSide_ = "right";
}
Character1::~Character1() {}

Sprite Character1::getSprite()
{
	return sprite_;
}

float Character1::getMaxMoveSpeed()
{
	return maxMoveSpeed;
}

float Character1::getFrameSpeed()
{
	return frameSpeed_;
}

int Character1::getCurrIdleFrame()
{
	return currentIdleFrame_;
}

Vector2f Character1::getCurrPosition()
{
	return position_;
}

bool Character1::getCharacterLife()
{
	return life_;
}

void Character1::setPosition(float x, float y)
{
	position_.x = x;
	position_.y = y;
	sprite_.setPosition(x, y);
}

void Character1::setCurrIdleFrame(float increase)
{
	currentRunFrame_ = 1;
	currentIdleFrame_ += increase;

	if (currentIdleFrame_ >= numberOfIdleFrames_)
		currentIdleFrame_ = 1;
}

void Character1::setCurrRunFrame(float increase)
{
	currentIdleFrame_ = 1;
	currentRunFrame_ += increase;

	if (currentRunFrame_ >= numberOfRunFrames_)
		currentRunFrame_ = 1;
}

void Character1::spriteUpdateIdle()
{
	if (int(currentIdleFrame_) == 1)
		sprite_.setTexture(textureIdle1_);
	else if (int(currentIdleFrame_) == 2)
		sprite_.setTexture(textureIdle2_);
	else if (int(currentIdleFrame_) == 3)
		sprite_.setTexture(textureIdle3_);
	else if (int(currentIdleFrame_) == 4)
		sprite_.setTexture(textureIdle4_);
	else if (int(currentIdleFrame_) == 5)
		sprite_.setTexture(textureIdle5_);
	else if (int(currentIdleFrame_) == 6)
		sprite_.setTexture(textureIdle6_);
	else if (int(currentIdleFrame_) == 7)
		sprite_.setTexture(textureIdle7_);
	else if (int(currentIdleFrame_) == 8)
		sprite_.setTexture(textureIdle8_);
	else if (int(currentIdleFrame_) == 9)
		sprite_.setTexture(textureIdle9_);
	else if (int(currentIdleFrame_) == 10)
		sprite_.setTexture(textureIdle10_);
	else if (int(currentIdleFrame_) == 11)
		sprite_.setTexture(textureIdle11_);
	else 
		sprite_.setTexture(textureIdle12_);
}

void Character1::spriteUpdateRun(string spriteSide)
{
	if (int(currentRunFrame_) == 1)
		sprite_.setTexture(textureRun1_);
	else if (int(currentRunFrame_) == 2)
		sprite_.setTexture(textureRun2_);
	else if (int(currentRunFrame_) == 3)
		sprite_.setTexture(textureRun3_);
	else if (int(currentRunFrame_) == 4)
		sprite_.setTexture(textureRun4_);
	else if (int(currentRunFrame_) == 5)
		sprite_.setTexture(textureRun5_);
	else if (int(currentRunFrame_) == 6)
		sprite_.setTexture(textureRun6_);
	else if (int(currentRunFrame_) == 7)
		sprite_.setTexture(textureRun7_);
	else
		sprite_.setTexture(textureRun8_);

	if (currSpriteSide_ != spriteSide)
	{
		if (spriteSide == "left")
			sprite_.setScale(-1.f, 1.f);
		else
			sprite_.setScale(1.f, 1.f);

		currSpriteSide_ = spriteSide;
		cout << currSpriteSide_ << endl;
	}
}