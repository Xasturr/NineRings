#include "treasureCoinInner.h"

TreasureCoinInner::TreasureCoinInner()
{
	position_ = { 0, 0 };

	texture1_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Items/coin1.png");
	texture2_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Items/coin2.png");
	texture3_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Items/coin3.png");
	texture4_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Items/coin4.png");
	texture5_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Items/coin5.png");
	texture6_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Items/coin6.png");
	texture7_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Items/coin7.png");
	texture8_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Items/coin8.png");
	texture9_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Items/coin9.png");
	texture10_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Items/coin10.png");

	sprite_.setTexture(texture1_);
	sprite_.setPosition(position_);

	currentFrame_ = 1;
	numberOfFrames_ = 10;
	frameSpeed_ = 12;
	points_ = 100;
}

TreasureCoinInner::~TreasureCoinInner()
{
	cout << "In TreasureCoinInner distructor" << endl;
}

Sprite TreasureCoinInner::getSprite()
{
	return sprite_;
}

void TreasureCoinInner::setCurrFrame(float elapsedTime)
{
	currentFrame_ += elapsedTime * frameSpeed_;

	if (currentFrame_ > numberOfFrames_)
	{
		currentFrame_ = 1;
	}
}

void TreasureCoinInner::spriteUpdate()
{
	if (int(currentFrame_) == 1)
		sprite_.setTexture(texture1_);
	else if (int(currentFrame_) == 2)
		sprite_.setTexture(texture2_);
	else if (int(currentFrame_) == 3)
		sprite_.setTexture(texture3_);
	else if (int(currentFrame_) == 4)
		sprite_.setTexture(texture4_);
	else if (int(currentFrame_) == 5)
		sprite_.setTexture(texture5_);
	else if (int(currentFrame_) == 6)
		sprite_.setTexture(texture6_);
	else if (int(currentFrame_) == 7)
		sprite_.setTexture(texture7_);
	else if (int(currentFrame_) == 8)
		sprite_.setTexture(texture8_);
	else if (int(currentFrame_) == 9)
		sprite_.setTexture(texture9_);
	else
		sprite_.setTexture(texture10_);
}

void TreasureCoinInner::setCurrPosition(Vector2f position)
{
	position_ = position;
	sprite_.setPosition(position_);
}

int TreasureCoinInner::getTreasurePoints()
{
	return points_;
}

Vector2f TreasureCoinInner::getCurrPosition()
{
	return position_;
}