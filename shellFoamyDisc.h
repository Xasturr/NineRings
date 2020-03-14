#pragma once

#include "shell.h"

class ShellFoamyDisc : public Shell
{
	Vector2f position_;

	Texture texture_;

	Texture textureExplosion_;

	Sprite sprite_;

	float speed_;
	float angle_;
	float currentFrame_;
	float currentExplosionFrame_;

	bool life_;
	bool explosed_;

	int alphaStrike_;
	int numberOfFrames_;
	int numberOfExplosionFrames_;

	string spriteSide_;

public:
	ShellFoamyDisc(float posX, float posY, float angle, string spriteSide);
	~ShellFoamyDisc();

	void setLife(bool flag);
	void setPosition(float posX, float posY);
	void setAngle(float angle);
	void updateAndDraw(float elapsedTime, Map* map, RenderWindow* window);
	void spriteUpdate();
	void spriteExplosionUpdate();
	void setCurrFrame(float increase);
	void setCurrExplosionFrame(float increase);
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