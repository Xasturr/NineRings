#pragma once

#include "shell.h"

class MagicDecorator : public Shell
{
	Shell* shell_;

public:
	MagicDecorator(Shell* shell);
	~MagicDecorator();

	void setLife(bool flag);
	void setPosition(float posX, float posY);
	void setAngle(float angle);
	void updateAndDraw(float elapsedTime, Map* map, RenderWindow* window);
	void spriteUpdate();
	void setCurrFrame(float increase);
	void setExplosed(bool flag);
	void setAlphaStrike(int alphaStrike);
	void setIsDoubleDamage(bool flag);

	bool getLife();
	bool getExplosed();
	bool isDoubleDamage();

	Vector2f getPosition();

	int getAlphaStrike();

	string getSpriteSide();
};