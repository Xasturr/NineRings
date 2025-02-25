#pragma once

#include "character1.h"
#include "characterBat.h";
#include "map.h"
#include "player.h"
#include "states.h"
#include "physxImplEnWalk.h"
#include "physxImplEnFly.h"
#include "strategyParams.h"

class Enemy
{
	Character* character_;

	int charName_;

	void checkDamage(Player* player);

	PhysxImplement* physx_;

public:
	Enemy(int charName, float posX, float posY, PhysxImplement* physx);
	~Enemy();

	bool getEnemyLife();
	bool getHurt();

	void draw(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime);
	void updatePosition(float elapsedTime);
	void interactionWithMap(Vector2f oldEnPosition, Map* map, float elapsedTime);
	void decision(float elapsedTime, Player* player);
	void calculateVariables(float elapsedTime);
	void setCurrHealthPoints(int healthPoints);
	void setHurt(bool flag);
	void flyingShellsUpdateAndDraw(float elapsedTime, Map* map, RenderWindow* window);
	void setStrategy(int param);

	int getWidth();
	int getHeight();
	int getCurrHealthPoints();
	int flyingShellsMakeDamage(Vector2f playerPos, int playerWidth, int playerHeight);
	int getKillExp();
	int getCurrFlyingShellsAmount();

	Vector2f getPosition();

	Sprite getSprite();
};