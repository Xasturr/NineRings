#include "engine.h"

Engine::Engine()
{
	resolution_.x = VideoMode::getDesktopMode().width;
	resolution_.y = VideoMode::getDesktopMode().height;

	isFullscreen_ = false;

	window_.setKeyRepeatEnabled(false);

	viewSizeX_ = 1280;
	viewSizeY_ = 720;
}

Engine::~Engine() {}

GameWindow* Engine::createGameWindow(map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string texturePath)
{
	GameWindow* gameWindow = new GameWindow(sizePosMap, texturePath, resolution_);
	return gameWindow;
}

Button* Engine::createButton(string id, map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string mouseContainsTexturePath, string mouseNotContainsTexturePath, string mouseClickedTexturePath)
{
	Button* button = new Button(id, sizePosMap, mouseContainsTexturePath, mouseNotContainsTexturePath, mouseClickedTexturePath, resolution_);
	return button;
}

Vector2f Engine::getPlayerPosition()
{
	return player_->getSprite().getPosition();
}

void Engine::drawGameWindow(GameWindow* gameWindow)
{
	gameWindow->draw(&window_);
}

void Engine::drawButton(Button* button)
{
	button->draw(&window_);
}

void Engine::createRenderWindow(VideoMode videoMode, string title, string windowStyle)
{
	if (windowStyle == "Fullscreen")
		window_.create(videoMode, title, Style::Fullscreen);
	else if (windowStyle == "None")
		window_.create(videoMode, title, Style::None);
	else if (windowStyle == "Resize")
		window_.create(videoMode, title, Style::Resize);
	else if (windowStyle == "Titlebar")
		window_.create(videoMode, title, Style::Titlebar);
	else if (windowStyle == "Close")
		window_.create(videoMode, title, Style::Close);
	else 
		window_.create(videoMode, title, Style::Default);
}

Vector2i Engine::getResolution()
{
	return resolution_;
}

bool Engine::renderWindowIsOpen()
{
	return window_.isOpen();
}

bool Engine::renderWindowPollEvent()
{
	return window_.pollEvent(event_);
}

void Engine::closeRenderWindow()
{
	window_.close();
}

bool Engine::isRenderWindowFullscreen()
{
	return isFullscreen_;
}

int Engine::input()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player_->moveLeft();
	}
	else
	{
		player_->stopLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::W)) 
	{
		player_->moveUp();
	}
	else
	{
		player_->stopUp();
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) 
	{
		player_->moveDown();
	}
	else
	{
		player_->stopDown();
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) 
	{
		player_->moveRight();
	}
	else
	{
		player_->stopRight();
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		player_->attack();
	}
	else
	{
		player_->stopAttack();
	}

	return 0;
}

void Engine::changeRenderWindowMode()
{
	if (isFullscreen_)
		isFullscreen_ = false;
	else
		isFullscreen_ = true;
}

void Engine::renderWindowClear()
{
	window_.clear();
}

void Engine::renderWindowDisplay()
{
	window_.display();
}

void Engine::setGameWindowVisible(GameWindow* gameWindow)
{
	gameWindow->setVisible();
}

void Engine::setGameWindowInvisible(GameWindow* gameWindow)
{
gameWindow->setInvisible();
}

string Engine::getClickedButtonId(GameWindow* gameWindow)
{
	return gameWindow->getClickedButtonId(&window_);
}

Event* Engine::getEvent()
{
	return &event_;
}

//Level* Engine::getLevel()
//{
//	return level_;
//}

//void Engine::buildMap()
//{
//	level_->buildMap(&window_);
//}

void Engine::createLevel(Level* level)
{
	level_ = level;
}

void Engine::setPlayer(string charName, float posX, float posY)
{
	player_ = new Player(charName, posX, posY);
}

void Engine::playerMoveLeft()
{
	player_->moveLeft();
}

void Engine::playerMoveRight()
{
	player_->moveRight();
}

void Engine::playerMoveUp()
{
	player_->moveUp();
}

void Engine::playerMoveDown()
{
	player_->moveDown();
}

void Engine::update(float elapsedTime)
{
	Vector2f oldPlayerPosition = player_->getCharacterPosition();
	player_->update(elapsedTime);
	Vector2f newPlayerPosition = player_->getCharacterPosition();

	interactionWithMap(oldPlayerPosition, newPlayerPosition, elapsedTime);
	calculateVariables(elapsedTime);

	view_.setCenter(player_->getCharacterPosition().x, player_->getCharacterPosition().y);
}

void Engine::draw()
{
	level_->buildMap(&window_, player_->getSprite().getPosition(), view_.getSize());
	//level_->buildMap(&window_);

	window_.draw(player_->getSprite());
}

void Engine::drawText(Text text)
{
	window_.draw(text);
}

void Engine::setView(int sizeX, int sizeY)
{
	view_.reset(FloatRect(player_->getSprite().getPosition().x - sizeX / 2, player_->getSprite().getPosition().y - sizeY / 2, sizeX, sizeY));
	window_.setView(view_);
}

void Engine::interactionWithMap(Vector2f oldPlayerPosition, Vector2f newPlayerPosition, float elapsedTime)
{
	Vector2f position = newPlayerPosition;

	for (int i = (newPlayerPosition.x - player_->getLeftGap()) / level_->getTileWidth(); i < (newPlayerPosition.x + player_->getRightGap()) / level_->getTileWidth(); i++)
	{
		for (int j = (oldPlayerPosition.y - player_->getUpperGap()) / level_->getTileHeight(); j < (oldPlayerPosition.y + player_->getLowerGap()) / level_->getTileHeight(); j++)
		{
			if (!level_->getValue(j, i, ' ', level_->getTileMapElse()))
			{	
				position.x = oldPlayerPosition.x;
				break;
			}
		}
	}

	for (int i = (oldPlayerPosition.x - player_->getLeftGap()) / level_->getTileWidth(); i < (oldPlayerPosition.x + player_->getRightGap()) / level_->getTileWidth(); i++)
	{
		for (int j = (newPlayerPosition.y - player_->getUpperGap()) / level_->getTileHeight(); j < (newPlayerPosition.y + player_->getLowerGap()) / level_->getTileHeight(); j++)
		{
			if (!level_->getValue(j, i, ' ', level_->getTileMapElse()))
			{
				if (player_->getCurrState() == "jumping")
				{
					if (newPlayerPosition.y > j * level_->getTileHeight())
					{	
						player_->setState("falling");
						player_->setPosition(oldPlayerPosition.x, oldPlayerPosition.y);
						player_->setCurrGravityAccel(0);
						return;
					}
				}
				else
				{
					if (position.x == newPlayerPosition.x && newPlayerPosition.x != oldPlayerPosition.x)
					{
						player_->setState("running");
					}
					else
					{
						player_->setState("staying");
					}

					position.y = j * level_->getTileHeight() - player_->getLowerGap();
				}
				
				player_->setCurrJumpAccel(player_->getJumpForce());
				player_->setCurrGravityAccel(0);
				break;
			}
		}
	}

	player_->setPosition(position.x, position.y);

	if (player_->getCurrState() != "jumping" && player_->getCurrState() != "falling" && player_->getCurrState() != "staying" && position == newPlayerPosition)
	{
		player_->setState("falling");
	}
}

void Engine::calculateVariables(float elapsedTime)
{
	if (player_->getCurrState() == "falling")
	{
		player_->setCurrGravityAccel(player_->getCurrGravityAccel() + player_->getGravity() * elapsedTime);
	}
	else if (player_->getCurrState() == "jumping")
	{
		player_->setCurrGravityAccel(player_->getCurrGravityAccel() + player_->getGravity() * elapsedTime);
		player_->setCurrJumpAccel(player_->getCurrJumpAccel() - player_->getCurrGravityAccel() * elapsedTime);
	}
}