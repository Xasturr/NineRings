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

	string charName_;

	void checkDamage(Player* player);

public:
	Enemy(string charName, float posX, float posY);
	~Enemy();

	bool getEnemyLife();

	void updatePosition(float elapsedTime);
	void draw(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime);
	void interactionWithMap(Vector2f oldEnPosition, Vector2f newPlayerPosition, Map* map, float elapsedTime);
	void decision();
	void calculateVariables(float elapsedTime);

	Vector2f getPosition();

	Sprite getSprite();
};