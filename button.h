#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

using namespace sf;
using namespace std;

class Button
{
	RectangleShape button_;

	Vector2u size_;
	Vector2u position_;

	Texture textureMouseContains_;
	Texture textureMouseNotContains_;
	Texture textureMouseClicked_;

	Sprite spriteMouseContains_;
	Sprite spriteMouseNotContains_;
	Sprite spriteMouseClicked_;

	//bool mouseContains_;
	string id_;

public:
	Button(string id, map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string mouseContainsTexturePath, string mouseNotContainsTexturePath, string mouseClickedTexturePath, Vector2i resolution);
	~Button();

	//void setTextureMouseContains();
	//void setTextureMouseNotContains();
	void draw(RenderWindow* window);
	bool containsCursor(RenderWindow* window);
	string getId();
};