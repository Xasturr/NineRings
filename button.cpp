#include "button.h"

Button::Button(string id, map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string mouseContainsTexturePath, string mouseNotContainsTexturePath, Vector2i resolution)
{
	pair<size_t, size_t> res = { resolution.x, resolution.y };

	std::map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>>::iterator it;
	it = sizePosMap.find(res);

	size_.x = it->second.first.first;
	size_.y = it->second.first.second;

	position_.x = it->second.second.first;
	position_.y = it->second.second.second;

	textureMouseContains_.loadFromFile(mouseContainsTexturePath);
	textureMouseNotContains_.loadFromFile(mouseNotContainsTexturePath);

	spriteMouseContains_.setTexture(textureMouseContains_);
	spriteMouseNotContains_.setTexture(textureMouseNotContains_);

	spriteMouseContains_.setPosition(position_.x, position_.y);
	spriteMouseNotContains_.setPosition(position_.x, position_.y);

	Vector2u textureMouseContainsSize = textureMouseContains_.getSize();
	Vector2u textureMouseNotContainsSize = textureMouseNotContains_.getSize();

	spriteMouseContains_.setScale(size_.x / textureMouseContainsSize.x, size_.y / textureMouseContainsSize.y);
	spriteMouseNotContains_.setScale(size_.x / textureMouseNotContainsSize.x, size_.y / textureMouseNotContainsSize.y);

	//mouseContains_ = false;

	id_ = id;
}

Button::~Button() {}

//void Button::setTextureMouseContains()
//{
//	mouseContains_ = true;
//}
//
//void Button::setTextureMouseNotContains()
//{
//	mouseContains_ = false;
//}

void Button::draw(RenderWindow *window)
{
	if (IntRect(position_.x, position_.y, size_.x, size_.y).contains(Mouse::getPosition(*window)))
	{
		window->draw(spriteMouseContains_);
		//mouseContains_ = true;
	}
	else
	{
		window->draw(spriteMouseNotContains_);
		//mouseContains_ = false;
	}
}

bool Button::containsCursor(RenderWindow* window)
{
	if (IntRect(position_.x, position_.y, size_.x, size_.y).contains(Mouse::getPosition(*window)))
	{
		return true;
	}
	return false;
}

string Button::getId()
{
	return id_;
}