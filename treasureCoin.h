#pragma once

#include "treasureCoinInner.h"

class TreasureCoin : public Treasure
{
	Treasure* treasureCoinInner_;

	Vector2f position_;

public:
	TreasureCoin();
	~TreasureCoin();

	Sprite getSprite();

	void setCurrFrame(float elapsedTime);
	void spriteUpdate();
	void setCurrPosition(Vector2f position);

	int getTreasurePoints();

	Vector2f getCurrPosition();
};