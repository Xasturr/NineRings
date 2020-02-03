#pragma once

#include "collision.h"

using namespace sf;
using namespace std;
using namespace Collision;

class Character
{
public:
	virtual Sprite getSprite() = 0;

	virtual float getMaxMoveSpeed() = 0;
	virtual float getGravity() = 0;
	virtual float getCurrGravityAccel() = 0;
	virtual float getFrameSpeed() = 0;
	virtual float getCurrJumpAccel() = 0;
	virtual float getJumpForce() = 0;
	//virtual float getCurrentSpeed() = 0;

	//virtual void spriteFrameUpdate(float currentFrame) = 0;
	virtual void setPosition(float posX, float posY) = 0;
	virtual void setCurrIdleFrame(float increase) = 0;
	virtual void setCurrRunFrame(float increase) = 0;
	virtual void setCurrJumpFrame(float increase) = 0;
	virtual void setCurrFallFrame(float increase) = 0;
	virtual void spriteUpdateIdle() = 0;
	virtual void spriteUpdateRun(string spriteSide) = 0;
	virtual void spriteUpdateJump(string spriteSide) = 0;
	virtual void spriteUpdateFall(string spriteSide) = 0;
	virtual void setCurrGravityAccel(float value) = 0;
	virtual void setCurrJumpAccel(float value) = 0;
	virtual void setJumpState(bool flag) = 0;
	virtual void setState(string state) = 0;

	virtual int getUpperGap() = 0;
	virtual int getLowerGap() = 0;
	virtual int getLeftGap() = 0;
	virtual int getRightGap() = 0;

	virtual bool getJumpState() = 0;

	virtual string getCurrSpriteSide() = 0;
	virtual string getCurrState() = 0;

	//virtual int getCurrFrame() = 0;

	virtual Vector2f getCurrPosition() = 0;
};