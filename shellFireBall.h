#pragma once

#include "shell.h"

class ShellFireBall : public Shell
{
	Vector2f position_;

	Texture texture1_;
	Texture texture2_;
	Texture texture3_;
	Texture texture4_;
	Texture texture5_;

	Texture textureExplosion_;

	Sprite sprite_;
	//Vector2f origin_;

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

	//void updateSpriteSide();
public:
	ShellFireBall(float posX, float posY, float angle, string spriteSide);
	~ShellFireBall();

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