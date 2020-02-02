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

void Engine::start()
{
	/*window_.create(VideoMode(resolution_.x, resolution_.y),
		"NineRings",
		Style::Default);*/

	//view_.reset(sf::FloatRect(0, 0, resolution_.x, resolution_.y));	
	//window_.setView(view_);

	RectangleShape rect;
	rect.setSize(Vector2f(100, 100));
	rect.setFillColor(Color::Black);
	rect.setPosition(500, 400);

	while (window_.isOpen())
	{
		Event event;

		while (window_.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window_.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && isFullscreen_ == false)
			{
				window_.create(VideoMode::getDesktopMode(), "NineRings", Style::Fullscreen);
				isFullscreen_ = true;
			}

			if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && isFullscreen_ == true)
			{
				window_.create(VideoMode::getDesktopMode(), "NineRings", Style::None);
				isFullscreen_ = false;
			}

			if (IntRect(500, 400, 100, 100).contains(Mouse::getPosition(window_)))
			{
				//playText.setFillColor(Color::White);
				//playText.setOutlineColor(Color::Black);
				//menuState = 0;
				rect.setFillColor(Color::Red);
			}
			else
			{
				rect.setFillColor(Color::Yellow);
			}

			window_.clear();

			window_.draw(rect);

			window_.display();
		}
	}
}

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

void Engine::buildMap()
{
	level_->buildMap(&window_);
}

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

void Engine::update()
{
	player_->update();
	view_.setCenter(player_->getCharacterPosition().x, player_->getCharacterPosition().y);
}

void Engine::draw()
{
	level_->buildMap(&window_);
	window_.draw(player_->getSprite());
}