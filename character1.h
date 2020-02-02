#pragma once

#include "character.h"
#include <iostream>

using namespace std;

class Character1 : public Character
{
	Vector2f position_;
	Texture textureIdle1_;
	Texture textureIdle2_;
	Texture textureIdle3_;
	Texture textureIdle4_;
	Texture textureIdle5_;
	Texture textureIdle6_;
	Texture textureIdle7_;
	Texture textureIdle8_;
	Texture textureIdle9_;
	Texture textureIdle10_;
	Texture textureIdle11_;
	Texture textureIdle12_;

	Texture textureRun1_;
	Texture textureRun2_;
	Texture textureRun3_;
	Texture textureRun4_;
	Texture textureRun5_;
	Texture textureRun6_;
	Texture textureRun7_;
	Texture textureRun8_;

	Sprite sprite_;

	bool life_;

	float maxMoveSpeed;
	float currentIdleFrame_;
	float currentRunFrame_;

	int numberOfIdleFrames_;
	int numberOfRunFrames_;

	float frameSpeed_;

	string currSpriteSide_;

public:
	Character1(float posX, float posY);
	~Character1();

	Sprite getSprite();

	float getMaxMoveSpeed();
	float getFrameSpeed();

	int getCurrIdleFrame();

	Vector2f getCurrPosition();

	bool getCharacterLife();

	void setPosition(float x, float y);
	void setCurrIdleFrame(float increase);
	void setCurrRunFrame(float increase);
	void spriteUpdateIdle();
	void spriteUpdateRun(string spriteSide);
};

