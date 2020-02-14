#include "game.h"

Game::Game()
{
	engine_.createRenderWindow(VideoMode(engine_.getResolution().x, engine_.getResolution().y), "NineRings", "Fullscreen");

	clickTime_ = 0;
	inputValue = 0;
	elapsedTime_ = 0;

	showInfo_ = false;

	bebasRegular_.loadFromFile("./fonts/Bebas-Regular.otf");

	textFPS_.setFont(bebasRegular_);
	textHP_.setFont(bebasRegular_);
	textMana_.setFont(bebasRegular_);
	textStamina_.setFont(bebasRegular_);
	textShellsAmount_.setFont(bebasRegular_);
	textPosX_.setFont(bebasRegular_);
	textPosY_.setFont(bebasRegular_);

	textFPS_.setFillColor(Color::White);
	textHP_.setFillColor(Color::White);
	textMana_.setFillColor(Color::White);
	textStamina_.setFillColor(Color::White);
	textShellsAmount_.setFillColor(Color::White);
	textPosX_.setFillColor(Color::White);
	textPosY_.setFillColor(Color::White);

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
	textLevel1_.setPosition(280, 305);
	textLevel1_.setString("Level 1");

	textLevel2_.setFont(bebasRegular_);
	textLevel2_.setCharacterSize(90);
	textLevel2_.setFillColor(Color::Black);
	textLevel2_.setOutlineColor(Color::White);
	textLevel2_.setOutlineThickness(4);
	textLevel2_.setPosition(220, 480);
	textLevel2_.setString("Level 2");

	textBack_.setFont(bebasRegular_);
	textBack_.setCharacterSize(90);
	textBack_.setFillColor(Color::Black);
	textBack_.setOutlineColor(Color::White);
	textBack_.setOutlineThickness(4);
	textBack_.setPosition(285, 650);
	textBack_.setString("Back");

	textureMainMenu_.loadFromFile("./textures/backgrounds/mainMenuScreen.png");

	spriteMainMenu_.setTexture(textureMainMenu_);
	spriteMainMenu_.setScale(engine_.getResolution().x / textureMainMenu_.getSize().x, engine_.getResolution().y / textureMainMenu_.getSize().y);
	//spriteMainMenu_.setOrigin(textureMainMenu_.getSize().x / 2, textureMainMenu_.getSize().y / 2);
	spriteMainMenu_.setPosition(0, 0);

	ofstream ofs;
	ofs.open("./settings/settings.bin", ofstream::binary);
	if (ofs.is_open())
	{
		cout << "Opened" << endl;
		ofs << "INFO";
	}
	else
	{
		cout << "Some problems" << endl;
	}
	ofs.close();

	ifstream ifs;
	ifs.open("./settings/settings.bin", ifstream::binary);
	if (ifs.is_open())
	{
		cout << "Opened" << endl;
		while (!ifs.eof())
		{
			string str = "";
			getline(ifs, str);
			cout << "INFO: " << str << endl;
		}
	}
	else
	{
		cout << "Some problems" << endl;
	}
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
			clickTime_ = 0.5;
			clock_.restart();
		}
		if (Mouse::isButtonPressed(Mouse::Left) && menuState == 1 && clickTime_ == 0)
		{
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

		if (Keyboard::isKeyPressed(Keyboard::I))
		{
			if (showInfo_)
			{
				showInfo_ = false;
			}
			else
			{
				showInfo_ = true;
			}
		}

		inputValue = engine_.input();
		time += clock_.getElapsedTime().asSeconds();
		engine_.setView(1280, 720);

		//if (Keyboard::isKeyPressed(Keyboard::A))
		//{
		//	engine_.setGameWindowVisible(win1);
		//}
		//if (Keyboard::isKeyPressed(Keyboard::S))
		//{
		//	engine_.setGameWindowInvisible(win1);
		//}

		engine_.renderWindowClear();
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

			textHP_.setString("HP: " + to_string(engine_.getCurrPlayerHealthPoints()) + " of " + to_string(engine_.getMaxPlayerHealthPoints()));
			textStamina_.setString("Stamina: " + to_string(engine_.getCurrPlayerStamina()) + " of " + to_string(engine_.getMaxPlayerStamina()));
			textMana_.setString("Mana: " + to_string(engine_.getCurrPlayerMana()) + " of " + to_string(engine_.getMaxPlayerMana()));
			textShellsAmount_.setString(engine_.getCurrPlayerShellName() + ": " + to_string(engine_.getCurrPlayerShellAmount()));
			textPosX_.setString("PosX:" + to_string(engine_.getCurrPlayerPosX()));
			textPosY_.setString("PosY:" + to_string(engine_.getCurrPlayerPosY()));

			engine_.drawText(textFPS_);
			engine_.drawText(textHP_);
			engine_.drawText(textStamina_);
			engine_.drawText(textMana_);
			engine_.drawText(textShellsAmount_);
			engine_.drawText(textPosX_);
			engine_.drawText(textPosY_);
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