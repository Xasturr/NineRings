#include "animation.h"

Animation::Animation(float updateSpeed)
{
	updateSpeed_ = updateSpeed;
	currTexture_ = 1;
	oldTexture_ = 1;
}

Animation::~Animation()
{
	if (textures_.size() > 0)
	{
		delete[] &textures_;
	}
}

void Animation::addTexture(string path)
{
	Texture* texture = new Texture();
	if (!texture->loadFromFile(path))
	{
		exit(EXIT_FAILURE);
	}
	textures_.push_back(texture);
	sprite_.setTexture(*texture);
}

void Animation::updateAnimation(float elapsedTime)
{
	oldTexture_ = int(currTexture_);
	currTexture_ += elapsedTime * updateSpeed_;

	if (int(currTexture_) > oldTexture_)
	{
		if (int(currTexture_) >= textures_.size())
		{
			currTexture_ = 1;
		}
		sprite_.setTexture(*textures_.at((int(currTexture_)) - 1));
	}
}

void Animation::drawAnimation(RenderWindow* window)
{
	window->draw(sprite_);
}

void Animation::setSpriteScale(float factorX, float factorY)
{
	sprite_.setScale(factorX, factorY);
}