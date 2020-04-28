#include "treasureCoin.h"

TreasureCoin::TreasureCoin()
{
	cout << "In TreasureCoin constructor" << endl;
	position_ = { 0, 0 };
	treasureCoinInner_ = 0;
}

TreasureCoin::~TreasureCoin()
{
	cout << "In TreasureCoin distructor" << endl;
	delete treasureCoinInner_;
}

Sprite TreasureCoin::getSprite()
{
	return treasureCoinInner_->getSprite();
}

void TreasureCoin::setCurrFrame(float elapsedTime)
{
	if (!treasureCoinInner_)
	{
		treasureCoinInner_ = new TreasureCoinInner();
	}

	treasureCoinInner_->setCurrFrame(elapsedTime);
}

void TreasureCoin::spriteUpdate()
{
	if (!treasureCoinInner_)
	{
		treasureCoinInner_ = new TreasureCoinInner();
	}

	treasureCoinInner_->spriteUpdate();
}

void TreasureCoin::setCurrPosition(Vector2f position)
{
	if (!treasureCoinInner_)
	{
		treasureCoinInner_ = new TreasureCoinInner();
	}

	position_ = position;
	treasureCoinInner_->setCurrPosition(position);
}

int TreasureCoin::getTreasurePoints()
{
	if (!treasureCoinInner_)
	{
		treasureCoinInner_ = new TreasureCoinInner();
	}

	return treasureCoinInner_->getTreasurePoints();
}

Vector2f TreasureCoin::getCurrPosition()
{
	if (!treasureCoinInner_)
	{
		treasureCoinInner_ = new TreasureCoinInner();
	}

	return treasureCoinInner_->getCurrPosition();
}