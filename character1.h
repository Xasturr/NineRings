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

	Texture textureJump1_;
	Texture textureJump2_;
	Texture textureJump3_;
	Texture textureJump4_;
	Texture textureJump5_;
	Texture textureJump6_;
	Texture textureJump7_;

	Texture textureFall1_;

	Sprite sprite_;

	bool life_;
	bool jump_;

	float maxMoveSpeed;
	float currentIdleFrame_;
	float currentRunFrame_;
	float currentJumpFrame_;
	float currentFallFrame_;
	float gravity_;
	float jumpForce_;
	float currGravityAccel_;
	float currJumpAccel_;

	int numberOfIdleFrames_;
	int numberOfRunFrames_;
	int numberOfJumpFrames_;
	int numberOfFallFrames_;
	int lowerGap_;
	int upperGap_;
	int rightGap_;
	int leftGap_;

	float frameSpeed_;

	string currSpriteSide_;
	string state_;

public:
	Character1(float posX, float posY);
	~Character1();

	Sprite getSprite();

	float getMaxMoveSpeed();
	float getGravity();
	float getCurrGravityAccel();
	float getFrameSpeed();
	float getCurrJumpAccel();
	float getJumpForce();

	int getCurrIdleFrame();
	int getUpperGap();
	int getLowerGap();
	int getLeftGap();
	int getRightGap();

	Vector2f getCurrPosition();

	bool getCharacterLife();

	void setPosition(float x, float y);
	void setCurrIdleFrame(float increase);
	void setCurrRunFrame(float increase);
	void setCurrJumpFrame(float increase);
	void setCurrFallFrame(float increase);
	void spriteUpdateIdle();
	void spriteUpdateRun(string spriteSide);
	void spriteUpdateJump(string spriteSide);
	void spriteUpdateFall(string spriteSide);
	void setCurrGravityAccel(float value);
	void setCurrJumpAccel(float value);
	void setJumpState(bool flag);
	void setState(string state);

	bool getJumpState();

	string getCurrSpriteSide();
	string getCurrState();
};

