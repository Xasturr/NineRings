#pragma once

#include "treasure.h"

class TreasureCoin : public Treasure
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

	bool life_;

	float currentFrame_;

	int numberOfFrames_;
	int frameSpeed_;

public:
	TreasureCoin(Vector2f position);
	~TreasureCoin();

	Sprite getSprite();

	void setCurrFrame(float elapsedTime);
	void spriteUpdate();
	void setLife(bool flag);

	Vector2f getCurrPosition();
};