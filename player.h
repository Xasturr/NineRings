#pragma once

#include <SFML/Graphics.hpp>

#include "character.h"
#include "character1.h"

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

	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	void update();

	Vector2f getCharacterPosition();

	Sprite getSprite();

	//void shoot();
	//void interactionWithMap(float dx, float dy, Map* map, float oldBodyTurn);
	//void update(float elapsedTime, Map* map, RenderWindow* window);
};