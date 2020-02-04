#pragma once

#include <SFML/Graphics.hpp>

#include "character.h"
#include "character1.h"
#include "map.h"

using namespace sf;
using namespace std;

class Player
{
	Character* character_;
	string charName_;

	//Vector2i cursorPos_;

	//Texture aimTexture_;
	//Sprite aimSprite_;

	bool leftPressed_;
	bool rightPressed_;
	bool upPressed_;
	bool downPressed_;
	bool attack_;
	bool runAttack_;
	//bool shoot_;

	//void setAimPosition(Vector2f pos);
	//void setAimRotation(float angle);

public:
	Player(string charName, float posX, float posY);

	//Tank* getTank();

	//Sprite getAimSprite();

	//bool getShootState();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void attack();

	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	void stopAttack();

	void update(float elapsedTime);
	void setPosition(float posX, float posY);
	void setCurrGravityAccel(float value);
	void setCurrJumpAccel(float value);
	void setJumpState(bool flag);
	void setState(string state);

	Vector2f getCharacterPosition();

	Sprite getSprite();

	int getUpperGap();
	int getLowerGap();
	int getRightGap();
	int getLeftGap();

	float getGravity();
	float getJumpForce();
	float getCurrGravityAccel();
	float getCurrJumpAccel();

	string getCurrState();

	//void shoot();
	//void interactionWithMap(float dx, float dy, Map* map, float oldBodyTurn);
	//void update(float elapsedTime, Map* map, RenderWindow* window);
};