#pragma once

#include "map.h"
#include <SFML/Graphics.hpp>

class Shell
{
public:
	virtual ~Shell() {};

	virtual void setLife(bool flag) = 0;
	virtual void setPosition(float posX, float posY) = 0;
	virtual void setAngle(float angle) = 0;
	virtual void updateAndDraw(float elapsedTime, Map* map, RenderWindow* window) = 0;
	virtual void spriteUpdate() = 0;
	virtual void setCurrFrame(float increase) = 0;
	virtual void setExplosed(bool flag) = 0;

	virtual bool getLife() = 0;
	virtual bool getExplosed() = 0;

	virtual Vector2f getPosition() = 0;

	virtual int getAlphaStrike() = 0;

	virtual string getSpriteSide() = 0;
};