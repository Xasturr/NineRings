#pragma once

#include "treasure.h"

class TreasureCoinInner : public Treasure
{
	Sprite sprite_;

	Texture texture1_;
	Texture texture2_;
	Texture texture3_;
	Texture texture4_;
	Texture texture5_;
	Texture texture6_;
	Texture texture7_;
	Texture texture8_;
	Texture texture9_;
	Texture texture10_;

	Vector2f position_;

	float currentFrame_;

	int numberOfFrames_;
	int frameSpeed_;
	int points_;

public:
	TreasureCoinInner(Vector2f position);
	~TreasureCoinInner();

	Sprite getSprite();

	void setCurrFrame(float elapsedTime);
	void spriteUpdate();

	int getTreasurePoints();

	Vector2f getCurrPosition();
};