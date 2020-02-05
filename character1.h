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

	Texture textureAttack1_;
	Texture textureAttack2_;
	Texture textureAttack3_;
	Texture textureAttack4_;

	Texture textureRunAttack1_;
	Texture textureRunAttack2_;
	Texture textureRunAttack3_;
	Texture textureRunAttack4_;
	Texture textureRunAttack5_;
	Texture textureRunAttack6_;
	Texture textureRunAttack7_;
	Texture textureRunAttack8_;

	Texture textureFall1_;

	Sprite sprite_;

	bool life_;
	bool jump_;
	bool attack_;
	bool runAttack_;
	bool enemyDamaged_;
	bool damageDisabled_;

	float maxMoveSpeed;
	float currentIdleFrame_;
	float currentRunFrame_;
	float currentJumpFrame_;
	float currentFallFrame_;
	float currentAttackFrame_;
	float currentRunAttackFrame_;
	float gravity_;
	float jumpForce_;
	float currGravityAccel_;
	float currJumpAccel_;

	int numberOfIdleFrames_;
	int numberOfRunFrames_;
	int numberOfJumpFrames_;
	int numberOfFallFrames_;
	int numberOfAttackFrames_;
	int numberOfRunAttackFrames_;
	int lowerGap_;
	int upperGap_;
	int rightGap_;
	int leftGap_;
	int healthPoints_;
	int attackDamage_;
	int attackRange_;

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
	float getCurrAttackFrame();

	int getCurrIdleFrame();
	int getUpperGap();
	int getLowerGap();
	int getLeftGap();
	int getRightGap();
	int getAttackRange();
	int getHealthPoints();
	int getAttackDamage();
	int getNumberOfAttackFrames();

	Vector2f getCurrPosition();

	void setPosition(float x, float y);
	void setCurrIdleFrame(float increase);
	void setCurrRunFrame(float increase);
	void setCurrJumpFrame(float increase);
	void setCurrFallFrame(float increase);
	void setCurrAttackFrame(float increase);
	void setCurrRunAttackFrame(float increase);
	void spriteUpdateIdle();
	void spriteUpdateRun(string spriteSide);
	void spriteUpdateJump(string spriteSide);
	void spriteUpdateFall(string spriteSide);
	void spriteUpdateAttack(string spriteSide);
	void spriteUpdateRunAttack(string spriteSide);
	void setCurrGravityAccel(float value);
	void setCurrJumpAccel(float value);
	void setJumpState(bool flag);
	void setState(string state);
	void setAttackState(bool flag);
	void setRunAttackState(bool flag);
	void setHealthPoints(int healthPoints);
	void setEnemyDamaged(bool flag);

	bool getCharacterLife();
	bool getAttackState();
	bool getJumpState();
	bool getRunAttackState();
	bool getLife();
	bool getEnemyDamaged();
	bool getDamageDisabled();

	string getCurrSpriteSide();
	string getCurrState();
};

