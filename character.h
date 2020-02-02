#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Character
{
public:
	virtual Sprite getSprite() = 0;

	virtual float getMaxMoveSpeed() = 0;
	//virtual float getCurrentSpeed() = 0;

	//virtual void spriteFrameUpdate(float currentFrame) = 0;
	virtual void setPosition(float posX, float posY) = 0;
	virtual void setCurrIdleFrame(float increase) = 0;
	virtual void setCurrRunFrame(float increase) = 0;
	virtual void spriteUpdateIdle() = 0;
	virtual void spriteUpdateRun(string spriteSide) = 0;


	//virtual int getCurrFrame() = 0;
	virtual float getFrameSpeed() = 0;

	virtual Vector2f getCurrPosition() = 0;
};