#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <vector>
#include "button.h"

using namespace sf;
using namespace std;

class GameWindow
{
	Vector2u size_;
	Vector2u position_;

	Texture textureGameWindow_;

	Sprite spriteGameWindow_;

	vector<Button*> buttons_;

	bool visible_;
 
public:
	GameWindow(map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string texturePath, Vector2i resolution);
	~GameWindow();

	void draw(RenderWindow *window);
	void addButton(Button* button);
	void setVisible();
	void setInvisible();
	string getClickedButtonId(RenderWindow* window);
};