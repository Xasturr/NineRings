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

	bool leftPressed_;
	bool rightPressed_;
	bool upPressed_;
	bool downPressed_;
	bool attack_;
	bool runAttack_;

public:
	Player(string charName, float posX, float posY);

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
	void interactionWithMap(Vector2f oldPlayerPosition, Vector2f newPlayerPosition, Map* map, float elapsedTime);
	void calculateVariables(float elapsedTime);
	void setEnemyDamaged(bool flag);
	void setHealthPoints(int healthPoints);
	void setLife(bool flag);
	void setHurt(bool flag);

	Vector2f getCurrPosition();

	Sprite getSprite();

	int getUpperGap();
	int getLowerGap();
	int getRightGap();
	int getLeftGap();
	int getAttackRange();
	int getAttackDamage();
	int getNumberOfAttackFrames();
	int getWidth();
	int getHeight();
	int getHealthPoints();

	float getGravity();
	float getJumpForce();
	float getCurrGravityAccel();
	float getCurrJumpAccel();
	float getCurrAttackFrame();

	string getCurrState();
	string getCurrSpriteSide();

	bool getAttackState();
	bool getCharacterMadeDamage();
	bool getDamageDisabled();
	bool getHurt();
};