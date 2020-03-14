#pragma once

#include "treasureCoinInner.h"

class TreasureCoin : public Treasure
{
	Treasure* treasureCoinInner_;

	Vector2f position_;

public:
	TreasureCoin(Vector2f position);
	~TreasureCoin();

	Sprite getSprite();

	void setCurrFrame(float elapsedTime);
	void spriteUpdate();

	int getTreasurePoints();

	Vector2f getCurrPosition();
};