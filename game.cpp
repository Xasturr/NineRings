#include "game.h"

Game::Game()
{
	engine_.createRenderWindow(VideoMode(engine_.getResolution().x, engine_.getResolution().y), "NineRings", "Fullscreen");

	clickTime_ = 0;
	inputValue = 0;
	elapsedTime_ = 0;

	showInfo_ = false;
	iPressed_ = false;
	tabPressed_ = false;
	mouseButtonPressed_ = false;
	//showNewLevel_ = false;

	bebasRegular_.loadFromFile("./fonts/Bebas-Regular.otf");

	//pair<size_t, size_t> res1 = { 1920, 1080 };
	//pair<size_t, size_t> size1 = { 1000, 500 };
	//pair<size_t, size_t> pos1 = { 100, 180 };

	//map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMapNewLevel;

	textFPS_.setFont(bebasRegular_);
	textHP_.setFont(bebasRegular_);
	textMana_.setFont(bebasRegular_);
	textStamina_.setFont(bebasRegular_);
	textShellsAmount_.setFont(bebasRegular_);
	textPosX_.setFont(bebasRegular_);
	textPosY_.setFont(bebasRegular_);
	textDDTimer_.setFont(bebasRegular_);

	textFPS_.setFillColor(Color::White);
	textHP_.setFillColor(Color::White);
	textMana_.setFillColor(Color::White);
	textStamina_.setFillColor(Color::White);
	textShellsAmount_.setFillColor(Color::White);
	textPosX_.setFillColor(Color::White);
	textPosY_.setFillColor(Color::White);
	textDDTimer_.setFillColor(Color::White);

	textPlay.setFont(bebasRegular_);
	textPlay.setCharacterSize(90);
	textPlay.setFillColor(Color::Black);
	textPlay.setOutlineColor(Color::White);
	textPlay.setOutlineThickness(4);
	textPlay.setPosition(280, 305);
	textPlay.setString("PLAY");

	textSettings.setFont(bebasRegular_);
	textSettings.setCharacterSize(90);
	textSettings.setFillColor(Color::Black);
	textSettings.setOutlineColor(Color::White);
	textSettings.setOutlineThickness(4);
	textSettings.setPosition(220, 480);
	textSettings.setString("SETTINGS");

	textExit.setFont(bebasRegular_);
	textExit.setCharacterSize(90);
	textExit.setFillColor(Color::Black);
	textExit.setOutlineColor(Color::White);
	textExit.setOutlineThickness(4);
	textExit.setPosition(285, 650);
	textExit.setString("EXIT");

	//chooseLevelMenu
	textLevel1_.setFont(bebasRegular_);
	textLevel1_.setCharacterSize(90);
	textLevel1_.setFillColor(Color::Black);
	textLevel1_.setOutlineColor(Color::White);
	textLevel1_.setOutlineThickness(4);
	textLevel1_.setPosition(250, 305);
	textLevel1_.setString("Level 1");

	textLevel2_.setFont(bebasRegular_);
	textLevel2_.setCharacterSize(90);
	textLevel2_.setFillColor(Color::Black);
	textLevel2_.setOutlineColor(Color::White);
	textLevel2_.setOutlineThickness(4);
	textLevel2_.setPosition(250, 480);
	textLevel2_.setString("Level 2");

	textBack_.setFont(bebasRegular_);
	textBack_.setCharacterSize(90);
	textBack_.setFillColor(Color::Black);
	textBack_.setOutlineColor(Color::White);
	textBack_.setOutlineThickness(4);
	textBack_.setPosition(285, 650);
	textBack_.setString("Back");

	textureMainMenu_.loadFromFile("./textures/backgrounds/mainMenuScreen.jpg");
	textureSettings_.loadFromFile("./textures/backgrounds/mainMenuScreen.jpg");
	texturePerksMenu_.loadFromFile("./textures/backgrounds/backgroundPerks.png");

	float engineResX = engine_.getResolution().x;
	float engineResY = engine_.getResolution().y;

	spriteMainMenu_.setTexture(textureMainMenu_);
	spriteMainMenu_.setScale(engineResX / textureMainMenu_.getSize().x, engineResY / textureMainMenu_.getSize().y);

	spriteSettings_.setTexture(textureSettings_);
	spriteSettings_.setScale(engineResX / textureSettings_.getSize().x, engineResY / textureSettings_.getSize().y);

	spritePerksMenu_.setTexture(texturePerksMenu_);
	spritePerksMenu_.setScale(engineResX / texturePerksMenu_.getSize().x, engineResY / texturePerksMenu_.getSize().y);	
}

Game::~Game()
{

}

void Game::start()
{
	mainMenu();
}

void Game::mainMenu()
{
	//engine_.setView(engine_.getResolution().x, engine_.getResolution().y);
	//view_.reset(sf::FloatRect(0, 0, resolution_.x, resolution_.y));
	//window_.setView(view_);

	//bool isFullScreen = true;
	int menuState = 0;

	Vector2f rectSize;
	rectSize.x = 380;
	rectSize.y = 200;

	//clickTime_ = 2;
	clock_.restart();

	while (engine_.renderWindowIsOpen())
	{
		Event event;
		menuState = -1;

		while (engine_.renderWindowPollEvent())
		{
			Event event = *engine_.getEvent();
			if (event.type == Event::Closed)
			{
				engine_.closeRenderWindow();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_.isRenderWindowFullscreen() == false)
		{
			engine_.createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Fullscreen");
			engine_.changeRenderWindowMode();
		}

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_.isRenderWindowFullscreen() == true)
		{
			engine_.createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Close");
			engine_.changeRenderWindowMode();
		}

		textPlay.setFillColor(Color::Black);
		textPlay.setOutlineColor(Color::White);

		textSettings.setFillColor(Color::Black);
		textSettings.setOutlineColor(Color::White);

		textExit.setFillColor(Color::Black);
		textExit.setOutlineColor(Color::White);

		if (engine_.mouseContains(90, 305, 580, 110))
		{
			textPlay.setFillColor(Color::White);
			textPlay.setOutlineColor(Color::Black);
			menuState = 0;
		}
		if (engine_.mouseContains(90, 485, 580, 110))
		{
			textSettings.setFillColor(Color::White);
			textSettings.setOutlineColor(Color::Black);
			menuState = 1;
		}
		if (engine_.mouseContains(90, 660, 580, 110))
		{
			textExit.setFillColor(Color::White);
			textExit.setOutlineColor(Color::Black);
			menuState = 2;
		}

		if (Mouse::isButtonPressed(Mouse::Left) && menuState == 0 && clickTime_ == 0)
		{
			chooseLevelMenu();
			clickTime_ = 0.25;
			clock_.restart();
		}
		if (Mouse::isButtonPressed(Mouse::Left) && menuState == 1 && clickTime_ == 0)
		{
			settings();
			clickTime_ = 0.25;
			clock_.restart();
			//return 1;
			//settingsMenu();
		}
		if (Mouse::isButtonPressed(Mouse::Left) && menuState == 2 && clickTime_ == 0)
		{
			exit(EXIT_SUCCESS);
		}

		//window_.clear();
		engine_.renderWindowClear();

		//window_.draw(mainMenuSprite_);
		//window_.draw(playText);
		//window_.draw(settingsText);
		//window_.draw(exitText);
		//engine_.draw

		engine_.drawSprite(spriteMainMenu_);
		engine_.drawText(textPlay);
		engine_.drawText(textSettings);
		engine_.drawText(textExit);
		//window_.display();
		engine_.renderWindowDisplay();

		if (clickTime_ != 0)
		{
			clickTime_ -= clock_.restart().asSeconds();
			if (clickTime_ < 0)
			{
				clickTime_ = 0;
			}
		}
	}
}

void Game::play(Level* level)
{
	//engine_.createRenderWindow(VideoMode(engine_.getResolution().x, engine_.getResolution().y), "NineRings", "Fullscreen");

	//1920x1080
	pair<size_t, size_t> res1 = { 1920, 1080 };
	pair<size_t, size_t> size1 = { 1000, 500 };
	pair<size_t, size_t> pos1 = { 100, 180 };

	//1366x768
	pair<size_t, size_t> res2 = { 1366, 768 };
	pair<size_t, size_t> size2 = { 600, 400 };
	pair<size_t, size_t> pos2 = { 200, 100 };

	map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap;
	sizePosMap = {
		{res1, {size1, pos1}},
		{res2, {size2, pos2}},
	};

	GameWindow* win1 = engine_.createGameWindow(sizePosMap, "./textures/buttons/button1.png");
	//newLevelWindow_ = engine_.createGameWindow(sizePosMap, "./textures/buttons/button1.png");

	//newLevelWindow();

	pair<size_t, size_t> res3 = { 1920, 1080 };
	pair<size_t, size_t> size3 = { 200, 50 };
	pair<size_t, size_t> pos3 = { 1000, 500 };

	map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap1;
	sizePosMap1 = {
		{res3, {size3, pos3}},
	};

	Button* btn1 = engine_.createButton("button1", sizePosMap1, "./textures/buttons/button1.png", "./textures/buttons/button12.png", "./textures/buttons/button13.png");

	win1->addButton(btn1);

	string clickedButtonId = "";

	engine_.createLevel(level);
	engine_.setPlayer("Character1", 1800, 350);

	float time = 0;

	Font bebasRegular;
	bebasRegular.loadFromFile("./fonts/Bebas-Regular.otf");

	Text timeText;
	timeText.setString("0");
	timeText.setFont(bebasRegular);
	timeText.setFillColor(Color::Green);

	int iter = 0;
	char* intStr;

	clock_.restart();

	bool start = true;

	while (engine_.renderWindowIsOpen())
	{
		engine_.renderWindowClear();

		if (time >= 1)
		{
			//timeText.setString(to_string(iter));
			textFPS_.setString("FPS: " + to_string(iter));
			time = 0;
			iter = 0;
		}

		while (engine_.renderWindowPollEvent())
		{
			Event event = *engine_.getEvent();
			if (event.type == Event::Closed)
			{
				engine_.closeRenderWindow();
			}
			if ((event.type == Event::MouseButtonPressed) && event.key.code == Mouse::Left)
			{
				string tempClickedButton1Id = engine_.getClickedButtonId(win1);
				if (!tempClickedButton1Id.empty())
					clickedButtonId = tempClickedButton1Id;
			}
			if (event.type == Event::MouseButtonReleased && !clickedButtonId.empty())
			{
				if (engine_.getClickedButtonId(win1) == clickedButtonId)
				{
					cout << "SAME" << endl;
				}
				
				clickedButtonId = "";
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::I)
				{
					iPressed_ = true;
				}
				//else if (event.key.code == Keyboard::Tab && engine_.getNewPlayerLevel())
				if (event.key.code == Keyboard::Tab)
				{
					tabPressed_ = true;
				}
			}
			if (event.type == Event::KeyReleased)
			{
				if (iPressed_)
				{
					if (showInfo_)
					{
						showInfo_ = false;
					}
					else
					{
						showInfo_ = true;
					}
					iPressed_ = false;
				}
				if (tabPressed_)
				{
					//if (showNewLevel_)
					//{
					//	showNewLevel_ = false;
					//}
					//else
					//{
					//	showNewLevel_ = true;
					//}
					perksMenu();
					clock_.restart();
					//elapsedTime_ = 0;
					tabPressed_ = false;
					//showNewLevel_ = true;
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_.isRenderWindowFullscreen() == false)
		{
			engine_.createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Fullscreen");
			engine_.changeRenderWindowMode();
		}

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_.isRenderWindowFullscreen() == true)
		{
			engine_.createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Close");
			engine_.changeRenderWindowMode();
		}

		inputValue = engine_.input();
		time += clock_.getElapsedTime().asSeconds();

		//view_.reset(FloatRect(player_->getSprite().getPosition().x - sizeX / 2, player_->getSprite().getPosition().y - sizeY / 2, sizeX, sizeY));

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			engine_.setGameWindowVisible(win1);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			engine_.setGameWindowInvisible(win1);
		}

		if (start)
		{
			clock_.restart();
			start = false;
		}

		elapsedTime_ = clock_.restart().asSeconds();

		if (elapsedTime_ * 25 >= 1)
		{
			elapsedTime_ = 0;
		}

		engine_.draw(elapsedTime_);
		engine_.update(elapsedTime_);

		engine_.setView(engine_.getPlayerPosition().x - 1280 / 2, engine_.getPlayerPosition().y - 720 / 2, 1280, 720);

		//engine_.drawGameWindow(win1);
		//engine_.drawText(timeText);
		if (showInfo_)
		{
			textFPS_.setPosition(engine_.getViewCenter().x - 620, engine_.getViewCenter().y - 335);
			textHP_.setPosition(engine_.getViewCenter().x - 620, engine_.getViewCenter().y - 305);
			textStamina_.setPosition(engine_.getViewCenter().x - 620, engine_.getViewCenter().y - 275);
			textMana_.setPosition(engine_.getViewCenter().x - 620, engine_.getViewCenter().y - 245);
			textShellsAmount_.setPosition(engine_.getViewCenter().x - 620, engine_.getViewCenter().y - 215);
			textPosX_.setPosition(engine_.getViewCenter().x - 620, engine_.getViewCenter().y - 185);
			textPosY_.setPosition(engine_.getViewCenter().x - 620, engine_.getViewCenter().y - 155);
			textDDTimer_.setPosition(engine_.getViewCenter().x - 620, engine_.getViewCenter().y - 125);

			textHP_.setString("HP: " + to_string(engine_.getCurrPlayerHealthPoints()) + " of " + to_string(engine_.getMaxPlayerHealthPoints()));
			textStamina_.setString("Stamina: " + to_string(engine_.getCurrPlayerStamina()) + " of " + to_string(engine_.getMaxPlayerStamina()));
			textMana_.setString("Mana: " + to_string(engine_.getCurrPlayerMana()) + " of " + to_string(engine_.getMaxPlayerMana()));
			textShellsAmount_.setString(engine_.getCurrPlayerShellName() + ": " + to_string(engine_.getCurrPlayerShellAmount()));
			textPosX_.setString("PosX:" + to_string(engine_.getCurrPlayerPosX()));
			textPosY_.setString("PosY:" + to_string(engine_.getCurrPlayerPosY()));
			textDDTimer_.setString("DDTimer: " + to_string(engine_.getDDTimer()));

			engine_.drawText(textFPS_);
			engine_.drawText(textHP_);
			engine_.drawText(textStamina_);
			engine_.drawText(textMana_);
			engine_.drawText(textShellsAmount_);
			engine_.drawText(textPosX_);
			engine_.drawText(textPosY_);
			engine_.drawText(textDDTimer_);
		}

		engine_.renderWindowDisplay();

		iter++;
	}
}

void Game::chooseLevelMenu()
{
	int menuState = 0;

	Vector2f rectSize;
	rectSize.x = 380;
	rectSize.y = 200;

	clickTime_ = 0.5;
	clock_.restart();

	while (engine_.renderWindowIsOpen())
	{
		Event event;
		menuState = -1;

		while (engine_.renderWindowPollEvent())
		{
			Event event = *engine_.getEvent();
			if (event.type == Event::Closed)
			{
				engine_.closeRenderWindow();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_.isRenderWindowFullscreen() == false)
		{
			engine_.createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Fullscreen");
			engine_.changeRenderWindowMode();
		}

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_.isRenderWindowFullscreen() == true)
		{
			engine_.createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Close");
			engine_.changeRenderWindowMode();
		}

		textLevel1_.setFillColor(Color::Black);
		textLevel1_.setOutlineColor(Color::White);

		textLevel2_.setFillColor(Color::Black);
		textLevel2_.setOutlineColor(Color::White);

		textBack_.setFillColor(Color::Black);
		textBack_.setOutlineColor(Color::White);

		if (engine_.mouseContains(90, 305, 580, 110))
		{
			textLevel1_.setFillColor(Color::White);
			textLevel1_.setOutlineColor(Color::Black);
			menuState = 0;
		}
		if (engine_.mouseContains(90, 485, 580, 110))
		{
			textLevel2_.setFillColor(Color::White);
			textLevel2_.setOutlineColor(Color::Black);
			menuState = 1;
		}
		if (engine_.mouseContains(90, 660, 580, 110))
		{
			textBack_.setFillColor(Color::White);
			textBack_.setOutlineColor(Color::Black);
			menuState = 2;
		}

		if (Mouse::isButtonPressed(Mouse::Left) && menuState == 0 && clickTime_ == 0)
		{
			play(new Level1);
		}
		if (Mouse::isButtonPressed(Mouse::Left) && menuState == 1 && clickTime_ == 0)
		{
			//return 1;
			//settingsMenu();
			play(new Level2);
		}
		if (Mouse::isButtonPressed(Mouse::Left) && menuState == 2 && clickTime_ == 0)
		{
			break;
		}

		//window_.clear();
		engine_.renderWindowClear();

		//window_.draw(mainMenuSprite_);
		//window_.draw(playText);
		//window_.draw(settingsText);
		//window_.draw(exitText);
		//engine_.draw

		engine_.drawSprite(spriteMainMenu_);
		engine_.drawText(textLevel1_);
		engine_.drawText(textLevel2_);
		engine_.drawText(textBack_);
		//window_.display();
		engine_.renderWindowDisplay();

		if (clickTime_ != 0)
		{
			clickTime_ -= clock_.restart().asSeconds();
			if (clickTime_ < 0)
			{
				clickTime_ = 0;
			}
		}
	}
}

void Game::settings()
{
	//window_.setMouseCursorVisible(true);

	//view_.reset(sf::FloatRect(0, 0, resolution_.x, resolution_.y));
	//window_.setView(view_);

	Text jumpText, turnLeftText, turnRightText, shootText, backText;
	Text jumpOptionText, turnLeftOptionText, turnRightOptionText, shootOptionText;

	jumpText.setFont(bebasRegular_);
	jumpText.setString("Jump:");
	jumpText.setPosition(130, 210);
	jumpText.setOutlineThickness(3);
	jumpText.setCharacterSize(70);

	jumpOptionText.setFont(bebasRegular_);
	jumpOptionText.setPosition(590, 210); //740
	jumpOptionText.setOutlineThickness(3);
	jumpOptionText.setCharacterSize(70);

	turnLeftOptionText.setFont(bebasRegular_);
	turnLeftOptionText.setPosition(590, 350); //550
	turnLeftOptionText.setOutlineThickness(3);
	turnLeftOptionText.setCharacterSize(70);

	turnLeftText.setFont(bebasRegular_);
	turnLeftText.setString("Turn left:");
	turnLeftText.setPosition(130, 350);
	turnLeftText.setOutlineThickness(3);
	turnLeftText.setCharacterSize(70);

	turnRightOptionText.setFont(bebasRegular_);
	turnRightOptionText.setPosition(590, 490);
	turnRightOptionText.setOutlineThickness(3);
	turnRightOptionText.setCharacterSize(70);

	turnRightText.setFont(bebasRegular_);
	turnRightText.setString("Turn right:");
	turnRightText.setPosition(130, 490);
	turnRightText.setOutlineThickness(3);
	turnRightText.setCharacterSize(70);

	shootOptionText.setFont(bebasRegular_);
	shootOptionText.setPosition(590, 630); //405
	shootOptionText.setOutlineThickness(3);
	shootOptionText.setCharacterSize(70);

	shootText.setFont(bebasRegular_);
	shootText.setString("Shoot:");
	shootText.setPosition(130, 630);
	shootText.setOutlineThickness(3);
	shootText.setCharacterSize(70);

	backText.setFont(bebasRegular_);
	backText.setString("BACK");
	backText.setPosition(1488, 770);
	backText.setOutlineThickness(3);
	backText.setCharacterSize(70);

	int menuState;
	clock_.restart();
	Time time;

	while (engine_.renderWindowIsOpen())
	{
		if (time.asSeconds() > 100000)
			time = clock_.restart();
		else
			time += clock_.restart();

		//Event event;
		menuState = -1;

		jumpOptionText.setFillColor(Color::Black);
		jumpOptionText.setOutlineColor(Color::White);
		jumpOptionText.setString((char)(engine_.getSettings()->getMoveUp() + 65));

		jumpText.setFillColor(Color::Black);
		jumpText.setOutlineColor(Color::White);

		turnLeftOptionText.setFillColor(Color::Black);
		turnLeftOptionText.setOutlineColor(Color::White);
		turnLeftOptionText.setString((char)(engine_.getSettings()->getMoveLeft() + 65));

		turnLeftText.setFillColor(Color::Black);
		turnLeftText.setOutlineColor(Color::White);

		turnRightOptionText.setFillColor(Color::Black);
		turnRightOptionText.setOutlineColor(Color::White);
		turnRightOptionText.setString((char)(engine_.getSettings()->getMoveRight() + 65));

		turnRightText.setFillColor(Color::Black);
		turnRightText.setOutlineColor(Color::White);

		shootOptionText.setFillColor(Color::Black);
		shootOptionText.setOutlineColor(Color::White);
		shootOptionText.setString((char)(engine_.getSettings()->getShoot() + 65));

		shootText.setFillColor(Color::Black);
		shootText.setOutlineColor(Color::White);

		backText.setFillColor(Color::Black);
		backText.setOutlineColor(Color::White);

		//engine_.renderWindowPollEvent();

		//Event* event = engine_.getEvent();
		if (engine_.getEvent()->type == Event::Closed)
		{
			engine_.closeRenderWindow();
		}
		
		if (engine_.mouseContains(1400, 775, 400, 90))
		{
			backText.setFillColor(Color::White);
			backText.setOutlineColor(Color::Black);
			menuState = 0;
		}
		if (engine_.mouseContains(100, 215, 1720, 90))
		{
			jumpOptionText.setFillColor(Color::White);
			jumpOptionText.setOutlineColor(Color::Black);

			jumpText.setFillColor(Color::White);
			jumpText.setOutlineColor(Color::Black);

			menuState = 1;
		}
//355
		if (engine_.mouseContains(100, 355, 1720, 90))
		{
			turnLeftOptionText.setFillColor(Color::White);
			turnLeftOptionText.setOutlineColor(Color::Black);

			turnLeftText.setFillColor(Color::White);
			turnLeftText.setOutlineColor(Color::Black);

			menuState = 3;
		}
		if (engine_.mouseContains(100, 495, 1720, 90))
		{
			turnRightOptionText.setFillColor(Color::White);
			turnRightOptionText.setOutlineColor(Color::Black);

			turnRightText.setFillColor(Color::White);
			turnRightText.setOutlineColor(Color::Black);

			menuState = 4;
		}
		if (engine_.mouseContains(100, 635, 1720, 90))
		{
			shootOptionText.setFillColor(Color::White);
			shootOptionText.setOutlineColor(Color::Black);

			shootText.setFillColor(Color::White);
			shootText.setOutlineColor(Color::Black);

			menuState = 5;
		}

		if (Mouse::isButtonPressed(Mouse::Left) && menuState == 0)
		{
			break;
		}

		if (Mouse::isButtonPressed(Mouse::Left) && menuState > 0 && time.asSeconds() > 1)
		{
			while (1)
			{
				//window_.pollEvent(event);
				engine_.renderWindowPollEvent();
				
				if (engine_.getEvent()->type == Event::TextEntered)
				{
					if (menuState == 1)
						engine_.getSettings()->setMoveUp(engine_.getEvent()->text.unicode - 32);
					if (menuState == 3)
						engine_.getSettings()->setMoveLeft(engine_.getEvent()->text.unicode - 32);
					if (menuState == 4)
						engine_.getSettings()->setMoveRight(engine_.getEvent()->text.unicode - 32);
					if (menuState == 5)
						engine_.getSettings()->setShoot(engine_.getEvent()->text.unicode - 32);

					break;
				}
			}
		}

		engine_.renderWindowClear();

		engine_.drawSprite(spriteSettings_);

		engine_.drawText(jumpOptionText);
		engine_.drawText(jumpText);
		engine_.drawText(turnLeftOptionText);
		engine_.drawText(turnLeftText);
		engine_.drawText(turnRightOptionText);
		engine_.drawText(turnRightText);
		engine_.drawText(shootOptionText);
		engine_.drawText(shootText);
		engine_.drawText(backText);

		engine_.renderWindowDisplay();
	}
}

void Game::perksMenu()
{
	Text jumpText, turnLeftText, turnRightText, shootText, backText;
	Text jumpOptionText, turnLeftOptionText, turnRightOptionText, shootOptionText;
	Text textPoints_;

	jumpText.setFont(bebasRegular_);
	jumpText.setString("Jump:");
	jumpText.setPosition(130, 210);
	jumpText.setOutlineThickness(3);
	jumpText.setCharacterSize(70);

	jumpOptionText.setFont(bebasRegular_);
	jumpOptionText.setPosition(590, 210); //740
	jumpOptionText.setOutlineThickness(3);
	jumpOptionText.setCharacterSize(70);

	turnLeftOptionText.setFont(bebasRegular_);
	turnLeftOptionText.setPosition(590, 350); //550
	turnLeftOptionText.setOutlineThickness(3);
	turnLeftOptionText.setCharacterSize(70);

	turnLeftText.setFont(bebasRegular_);
	turnLeftText.setString("Turn left:");
	turnLeftText.setPosition(130, 350);
	turnLeftText.setOutlineThickness(3);
	turnLeftText.setCharacterSize(70);

	turnRightOptionText.setFont(bebasRegular_);
	turnRightOptionText.setPosition(590, 490);
	turnRightOptionText.setOutlineThickness(3);
	turnRightOptionText.setCharacterSize(70);

	turnRightText.setFont(bebasRegular_);
	turnRightText.setString("Turn right:");
	turnRightText.setPosition(130, 490);
	turnRightText.setOutlineThickness(3);
	turnRightText.setCharacterSize(70);

	shootOptionText.setFont(bebasRegular_);
	shootOptionText.setPosition(590, 630); //405
	shootOptionText.setOutlineThickness(3);
	shootOptionText.setCharacterSize(70);

	shootText.setFont(bebasRegular_);
	shootText.setString("Shoot:");
	shootText.setPosition(130, 630);
	shootText.setOutlineThickness(3);
	shootText.setCharacterSize(70);

	backText.setFont(bebasRegular_);
	backText.setString("BACK");
	backText.setPosition(1588, 870);
	backText.setOutlineThickness(3);
	backText.setCharacterSize(70);

	textPoints_.setFont(bebasRegular_);
	textPoints_.setString("POINTS: ");
	textPoints_.setPosition(1488, 770);
	textPoints_.setOutlineThickness(3);
	textPoints_.setCharacterSize(70);

	int menuState;
	clock_.restart();
	Time time;

	Player* player = engine_.getPlayer();

	engine_.setView(0, 0, engine_.getResolution().x, engine_.getResolution().y);

	while (engine_.renderWindowIsOpen())
	{
		if (time.asSeconds() > 100000)
			time = clock_.restart();
		else
			time += clock_.restart();

		//Event event;
		menuState = -1;

		jumpOptionText.setFillColor(Color::Black);
		jumpOptionText.setOutlineColor(Color::White);
		jumpOptionText.setString((char)(engine_.getSettings()->getMoveUp() + 65));

		jumpText.setFillColor(Color::Black);
		jumpText.setOutlineColor(Color::White);

		turnLeftOptionText.setFillColor(Color::Black);
		turnLeftOptionText.setOutlineColor(Color::White);
		turnLeftOptionText.setString((char)(engine_.getSettings()->getMoveLeft() + 65));

		turnLeftText.setFillColor(Color::Black);
		turnLeftText.setOutlineColor(Color::White);

		turnRightOptionText.setFillColor(Color::Black);
		turnRightOptionText.setOutlineColor(Color::White);
		turnRightOptionText.setString((char)(engine_.getSettings()->getMoveRight() + 65));

		turnRightText.setFillColor(Color::Black);
		turnRightText.setOutlineColor(Color::White);

		shootOptionText.setFillColor(Color::Black);
		shootOptionText.setOutlineColor(Color::White);
		shootOptionText.setString((char)(engine_.getSettings()->getShoot() + 65));

		shootText.setFillColor(Color::Black);
		shootText.setOutlineColor(Color::White);

		backText.setFillColor(Color::Black);
		backText.setOutlineColor(Color::White);

		textPoints_.setFillColor(Color::Black);
		textPoints_.setOutlineColor(Color::White);
		textPoints_.setString("POINTS: " + to_string(engine_.getPlayerPoints()));

		//engine_.renderWindowPollEvent();

		//Event* event = engine_.getEvent();
		if (engine_.getEvent()->type == Event::Closed)
		{
			engine_.closeRenderWindow();
		}

		if (engine_.mouseContains(1500, 875, 400, 90))
		{
			backText.setFillColor(Color::White);
			backText.setOutlineColor(Color::Black);

			menuState = 0;
		}
		if (engine_.mouseContains(100, 215, 1720, 90))
		{
			jumpOptionText.setFillColor(Color::White);
			jumpOptionText.setOutlineColor(Color::Black);

			jumpText.setFillColor(Color::White);
			jumpText.setOutlineColor(Color::Black);

			menuState = 1;
		}
		//355
		if (engine_.mouseContains(100, 355, 1720, 90))
		{
			turnLeftOptionText.setFillColor(Color::White);
			turnLeftOptionText.setOutlineColor(Color::Black);

			turnLeftText.setFillColor(Color::White);
			turnLeftText.setOutlineColor(Color::Black);

			menuState = 3;
		}
		if (engine_.mouseContains(100, 495, 1720, 90))
		{
			turnRightOptionText.setFillColor(Color::White);
			turnRightOptionText.setOutlineColor(Color::Black);

			turnRightText.setFillColor(Color::White);
			turnRightText.setOutlineColor(Color::Black);

			menuState = 4;
		}
		if (engine_.mouseContains(100, 635, 1720, 90))
		{
			shootOptionText.setFillColor(Color::White);
			shootOptionText.setOutlineColor(Color::Black);

			shootText.setFillColor(Color::White);
			shootText.setOutlineColor(Color::Black);

			menuState = 5;
		}

		//if (Mouse::isButtonPressed(Mouse::Left) && menuState == 0)
		//{
		//	break;
		//}

		while (engine_.renderWindowPollEvent())
		{
			Event event = *engine_.getEvent();
			if (event.type == Event::Closed)
			{
				engine_.closeRenderWindow();
			}
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					mouseButtonPressed_ = true;
				}
			}
			if (event.type == Event::MouseButtonReleased)
			{
				if (menuState == 0 && mouseButtonPressed_)
				{
					player->setFairyWandPerk();
					return;
				}
				mouseButtonPressed_ = false;
			}
		}

		//if (Mouse::isButtonPressed(Mouse::Left) && menuState > 0 && time.asSeconds() > 1)
		//{
		//	while (1)
		//	{
		//		engine_.renderWindowPollEvent();

		//		if (engine_.getEvent()->type == Event::TextEntered)
		//		{
		//			if (menuState == 1)
		//				engine_.getSettings()->setMoveUp(engine_.getEvent()->text.unicode - 32);
		//			if (menuState == 3)
		//				engine_.getSettings()->setMoveLeft(engine_.getEvent()->text.unicode - 32);
		//			if (menuState == 4)
		//				engine_.getSettings()->setMoveRight(engine_.getEvent()->text.unicode - 32);
		//			if (menuState == 5)
		//				engine_.getSettings()->setShoot(engine_.getEvent()->text.unicode - 32);

		//			break;
		//		}
		//	}
		//}

		engine_.renderWindowClear();

		engine_.drawSprite(spritePerksMenu_);

		//engine_.drawText(jumpOptionText);
		//engine_.drawText(jumpText);
		//engine_.drawText(turnLeftOptionText);
		//engine_.drawText(turnLeftText);
		//engine_.drawText(turnRightOptionText);
		//engine_.drawText(turnRightText);
		//engine_.drawText(shootOptionText);
		//engine_.drawText(shootText);
		engine_.drawText(backText);
		engine_.drawText(textPoints_);

		engine_.renderWindowDisplay();
	}
}