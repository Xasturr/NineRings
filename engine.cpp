#include "engine.h"

Engine::Engine()
{
	//engineInstance_ = nullptr;

	resolution_.x = VideoMode::getDesktopMode().width;
	resolution_.y = VideoMode::getDesktopMode().height;

	isFullscreen_ = false;

	window_.setKeyRepeatEnabled(false);

	viewSizeX_ = 1280;
	viewSizeY_ = 720;

	viewSize_.x = 1280;
	viewSize_.y = 720;

	srand(time(0));
}

Engine::~Engine() 
{
	cout << "In Engine distructor" << endl;

	delete player_;
	delete level_;
}

Engine* Engine::getEngineInstance()
{
	if (engineInstance_ == NULL)
	{
		engineInstance_ = new Engine();
	}
	
	return engineInstance_;
}

Engine* Engine::engineInstance_ = 0;

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

Vector2f Engine::getViewCenter()
{
	return view_.getCenter();
}

Settings* Engine::getSettings()
{
	return &settings_;
}

//void Engine::drawGameWindow(GameWindow* gameWindow)
//{
//	gameWindow->draw(&window_);
//}

//void Engine::drawButton(Button* button)
//{
//	button->draw(&window_);
//}

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

Vector2i Engine::getViewSize()
{
	return viewSize_;
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

bool Engine::mouseContains(int rectLeft, int rectTop, int rectWidth, int rectHeight)
{
	return IntRect(rectLeft, rectTop, rectWidth, rectHeight).contains(Mouse::getPosition(window_));
}

bool Engine::mouseContains(FloatRect rect)
{
	return rect.contains(Mouse::getPosition(window_).x, Mouse::getPosition(window_).y);
}

bool Engine::mouseContains(Sprite sprite)
{
	return sprite.getGlobalBounds().contains(Mouse::getPosition(window_).x, Mouse::getPosition(window_).y);
}

bool Engine::isNewPlayerLevel()
{
	return player_->isNewLevel();
}

bool Engine::isEndOfLevel()
{
	if (level_->getLevelNumber() == 1)
	{
		if (int(player_->getCurrPosition().x / level_->getTileWidth()) == 58 && int(player_->getCurrPosition().y / level_->getTileHeight()) == 34)
		{
			return true;
		}
	}
	else if (level_->getLevelNumber() == 2)
	{	
		if (int(player_->getCurrPosition().x / level_->getTileWidth() <= 3) && int(player_->getCurrPosition().y / level_->getTileHeight()) >= 33
			&& int(player_->getCurrPosition().x / level_->getTileWidth() >= 2) && int(player_->getCurrPosition().y / level_->getTileHeight()) <= 34)
		{
			return true;
		}
	}
	return false;
}

bool Engine::isNewGame()
{
	return player_->isNewGame();
}

int Engine::input()
{
	if (Keyboard::isKeyPressed(Keyboard::Key(settings_.getMoveLeft())))
	{
		player_->moveLeft();
	}
	else
	{
		player_->stopLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key(settings_.getMoveUp())))
	{
		player_->moveUp();
	}
	else
	{
		player_->stopUp();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key(settings_.getMoveRight())))
	{
		player_->moveRight();
	}
	else
	{
		player_->stopRight();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key(settings_.getAttack())) && !player_->getAttackState())
	{
		player_->attack();
	}
	else
	{
		player_->stopAttack();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key(settings_.getShoot())) && !player_->getAttackState())
	{
		player_->shoot();
	}
	else
	{
		player_->stopShoot();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::O)) // for example
	{
		player_->setDoubleDamage();
	}

	return 0;
}

int Engine::getCurrPlayerHealthPoints()
{
	return player_->getCurrHealthPoints();
}

int Engine::getCurrPlayerMana()
{
	return player_->getCurrMana();
}

int Engine::getCurrPlayerStamina()
{
	return player_->getCurrStamina();
}

int Engine::getMaxPlayerHealthPoints()
{
	return player_->getMaxHealthPoints();
}

int Engine::getMaxPlayerMana()
{
	return player_->getMaxMana();
}

int Engine::getMaxPlayerStamina()
{
	return player_->getMaxStamina();
}

int Engine::getCurrPlayerShellAmount()
{
	return player_->getCurrShellAmount();
}

int Engine::getCurrPlayerPosX()
{
	return player_->getCurrPosition().x / level_->getTileWidth();
}

int Engine::getCurrPlayerPosY()
{
	return player_->getCurrPosition().y / level_->getTileHeight();
}

int Engine::getDDTimer()
{
	return player_->getDDTimer();
}

int Engine::getPlayerLevel()
{
	return player_->getCurrLevel();
}

int Engine::getPlayerLevelPoints()
{
	return player_->getLevelPoints();
}

int Engine::getCurrLevelNumber()
{
	return level_->getLevelNumber();
}

int Engine::getTreasurePoints()
{
	return level_->getTreasurePoints();
}

int Engine::getPlayerExp()
{
	return player_->getCurrExp();
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

string Engine::getCurrPlayerShellName()
{
	return player_->getCurrShellName();
}

Event* Engine::getEvent()
{
	return &event_;
}

Player* Engine::getPlayer()
{
	return player_;
}

struct resolutions Engine::getResolutions()
{
	return resolutions_;
}

struct perksInfo Engine::getPlayerPerksInfo()
{
	return player_->getPerksInfo();
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
	if (level_)
	{
		delete level_;
	}

	player_->setPosition(1800, 300);
	level_ = level;
	cout << "Creating" << endl;
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
	Vector2f oldPlayerPosition = player_->getCurrPosition();
	player_->update(elapsedTime, &window_);
	//updateTreasurePoints();
	player_->interactionWithMap(oldPlayerPosition, player_->getSprite().getPosition(), level_->getMap(), elapsedTime);
	player_->calculateVariables(elapsedTime);
	if (level_->getInSaveZone())
	{
		saveLoad_.save(level_, player_);
	}
	view_.setCenter(player_->getCurrPosition().x, player_->getCurrPosition().y);
}

void Engine::draw(float elapsedTime)
{
	level_->buildMap(&window_, player_->getSprite().getPosition(), view_.getSize(), player_->getWidth(), player_->getHeight(), elapsedTime);
	//level_->buildMap(&window_);
	level_->updateAndDrawEnemies(&window_, player_, view_.getSize(), elapsedTime);
	player_->flyingShellsUpdateAndDraw(elapsedTime, level_->getMap(), &window_);

	window_.draw(player_->getSprite());
}

void Engine::draw(Text text)
{
	window_.draw(text);
}

void Engine::draw(Sprite sprite)
{
	window_.draw(sprite);
}

//void Engine::drawText(Text text)
//{
//	window_.draw(text);
//}

//void Engine::drawSprite(Sprite sprite)
//{
//	window_.draw(sprite);
//}

void Engine::draw(Animation* animation, float elapsedTime)
{
	animation->updateAnimation(elapsedTime);
	animation->drawAnimation(&window_);
}

void Engine::draw(GameWindow* gameWindow)
{
	gameWindow->draw(&window_);
}

void Engine::draw(Button* button)
{
	button->draw(&window_);
}

//void Engine::drawAnimation(Animation* animation, float elapsedTime)
//{
//	animation->updateAnimation(elapsedTime);
//	animation->drawAnimation(&window_);
//}

void Engine::setView(int rectLeft, int rectTop, int rectWidth, int rectHeight)
{
	view_.reset(FloatRect(rectLeft, rectTop, rectWidth, rectHeight));
	//view_.reset(FloatRect(player_->getSprite().getPosition().x - sizeX / 2, player_->getSprite().getPosition().y - sizeY / 2, sizeX, sizeY));
	window_.setView(view_);
}

void Engine::load()
{
	saveLoad_.load(&level_, &player_);
}

void Engine::loadNewGame()
{
	saveLoad_.loadNewGame(&level_, &player_);
}

//void Engine::updateTreasurePoints()
//{
//	treasurePoints_ = level_->getCatchedCoins() * coinsValue_;
//}