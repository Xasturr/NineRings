#pragma once

#include "character1.h"
#include "map.h"
#include "player.h"
#include "states.h"
#include "physxImplEnWalk.h"

class Enemy
{
	Character* character_;

	struct states states_;

	string charName_;

	void checkDamage(Player* player);
	//void updateDecisionTime(float elapsedTime);

	//float stayingTime_;
	//float runningTime_;

	PhysxImplement* physx_;

public:
	Enemy(string charName, float posX, float posY, PhysxImplement* physx);
	~Enemy();

	bool getEnemyLife();
	//bool getAngryState();

	void draw(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime);
	void updatePosition(float elapsedTime);
	void interactionWithMap(Vector2f oldEnPosition, Vector2f newPlayerPosition, Map* map, float elapsedTime);
	void decision(float elapsedTime, Player* player);
	//void calculateVariables(float elapsedTime);
	void setCurrHealthPoints(int healthPoints);
	void setHurt(bool flag);

	int getWidth();
	int getHeight();
	int getCurrHealthPoints();

	Vector2f getPosition();

	Sprite getSprite();
};