#include "gameWindow.h"

GameWindow::GameWindow(map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string texturePath, Vector2i resolution)
{
	pair<size_t, size_t> res = { resolution.x, resolution.y };

	std::map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>>::iterator it;
	it = sizePosMap.find(res);

	size_.x = it->second.first.first;
	size_.y = it->second.first.second;

	position_.x = it->second.second.first;
	position_.y = it->second.second.second;

	std::cout << it->second.first.first << endl;
	std::cout << it->second.first.second << endl;
	std::cout << it->second.second.first << endl;
	std::cout << it->second.second.second << endl;

	if (res.first == 1920 && res.second == 1080)
	{
		cout << "FULLHD" << endl;
	}
	else if (res.first == 1366 && res.second == 768)
	{
		cout << "NOT FULLHD" << endl;
	}

	textureGameWindow_.loadFromFile(texturePath);

	spriteGameWindow_.setTexture(textureGameWindow_);
	spriteGameWindow_.setPosition(position_.x, position_.y);

	Vector2u textureSize =  textureGameWindow_.getSize();

	spriteGameWindow_.setScale(size_.x / textureSize.x, size_.y / textureSize.y);

	visible_ = false;
}

GameWindow::~GameWindow() {}

void GameWindow::draw(RenderWindow *window)
{
	if (visible_)
	{
		window->draw(spriteGameWindow_);

		for (Button* button : buttons_)
		{
			button->draw(window);
		}
	}
}

void GameWindow::addButton(Button* button)
{
	buttons_.push_back(button);
}

void GameWindow::setVisible()
{
	visible_ = true;
}

void GameWindow::setInvisible()
{
	visible_ = false;
}

string GameWindow::getClickedButtonId(RenderWindow* window)
{
	if (visible_)
	{
		for (Button* button : buttons_)
		{
			if (button->containsCursor(window))
			{
				return button->getId();
			}
		}
	}
	return "";
}