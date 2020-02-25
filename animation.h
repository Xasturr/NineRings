#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Animation
{
	vector<Texture*> textures_;

	Sprite sprite_;

	float updateSpeed_;
	float currTexture_;

	int oldTexture_;
public:
	Animation(float updateSpeed);
	~Animation();

	void addTexture(string path);
	void updateAnimation(float elapsedTime);
	void drawAnimation(RenderWindow* window);
	void setSpriteScale(float factorX, float factorY);
};