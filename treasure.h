#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Treasure
{
public:
	~Treasure() {}

	virtual Sprite getSprite() = 0;

	virtual void setCurrFrame(float elapsedTime) = 0;
	virtual void spriteUpdate() = 0;

	virtual int getTreasurePoints() = 0;

	virtual Vector2f getCurrPosition() = 0;
};