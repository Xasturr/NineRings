#include "engine.h"

Engine::Engine()
{
	resolution_.x = VideoMode::getDesktopMode().width;
	resolution_.y = VideoMode::getDesktopMode().height;

	isFullscreen_ = false;

	window_.setKeyRepeatEnabled(false);
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
				window_.create(VideoMode::getDesktopMode(), "NineRings", Style::Default);
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

void Engine::update()
{
	//for (list<Button>::iterator iter = buttons.begin(); iter != buttons.end(); iter++)
	//{
	//	iter->draw(&window_);
	//}
}

GameWindow* Engine::createGameWindow(map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string texturePath)
{
	GameWindow* gameWindow = new GameWindow(sizePosMap, texturePath, resolution_);
	return gameWindow;
}

Button* Engine::createButton(string id, map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string mouseContainsTexturePath, string mouseNotContainsTexturePath)
{
	Button* button = new Button(id, sizePosMap, mouseContainsTexturePath, mouseNotContainsTexturePath, resolution_);
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