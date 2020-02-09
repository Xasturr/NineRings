#pragma once

#include "character1.h"
#include "map.h"
#include "player.h"

class Enemy
{
	Character* character_;

	bool leftPressed_;
	bool rightPressed_;
	bool upPressed_;
	bool downPressed_;
	bool attack_;
	bool runAttack_;
	bool angryState_;
	bool onEdge_;

	string charName_;

	void checkDamage(Player* player);
	void updateDecisionTime(float elapsedTime);

	float stayingTime_;
	float runningTime_;

public:
	Enemy(string charName, float posX, float posY);
	~Enemy();

	bool getEnemyLife();
	//bool getAngryState();

	void updatePosition(float elapsedTime);
	void draw(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime);
	void interactionWithMap(Vector2f oldEnPosition, Vector2f newPlayerPosition, Map* map, float elapsedTime);
	void decision(float elapsedTime, Player* player);
	void calculateVariables(float elapsedTime);
	void setCurrHealthPoints(int healthPoints);
	void setHurt(bool flag);

	int getWidth();
	int getHeight();
	int getCurrHealthPoints();

	Vector2f getPosition();

	Sprite getSprite();
};