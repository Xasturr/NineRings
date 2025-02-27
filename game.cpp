#include "game.h"

Game::Game()
{
	if (mainMenuMusic_.openFromFile("./audio/mainMenu/danger.ogg"))
	{
		mainMenuMusic_.setVolume(15);
		mainMenuMusic_.setLoop(true);
	}
	if (gameMusic_.openFromFile("./audio/level1/DanceoftheBlood.ogg"))
	{
		gameMusic_.setVolume(15);
		gameMusic_.setLoop(true);
	}

	engine_->createRenderWindow(VideoMode(engine_->getResolution().x, engine_->getResolution().y), "NineRings", "Fullscreen");
	
	clickTime_ = 0;
	inputValue = 0;
	elapsedTime_ = 0;

	showInfo_ = false;
	iPressed_ = false;
	tabPressed_ = false;
	mouseButtonPressed_ = false;
	escPressed_ = false;

	clickedButtonId_ = "";

	bebasRegular_.loadFromFile("./fonts/Bebas-Regular.otf");
	arcadeClassic_.loadFromFile("./fonts/ARCADECLASSIC.ttf");
	playMyGames_.loadFromFile("./fonts/PlayMeGames-Demo.otf");
	karmaSuture_.loadFromFile("./fonts/karmaSuture.ttf");

	//pair<size_t, size_t> res1 = { 1920, 1080 };
	//pair<size_t, size_t> size1 = { 1000, 500 };
	//pair<size_t, size_t> pos1 = { 100, 180 };

	//map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMapNewLevel;

	textFPS_.setFont(karmaSuture_);
	textHP_.setFont(karmaSuture_);
	textMana_.setFont(karmaSuture_);
	textStamina_.setFont(karmaSuture_);
	textShellsAmount_.setFont(karmaSuture_);
	textPosX_.setFont(karmaSuture_);
	textPosY_.setFont(karmaSuture_);
	textDDTimer_.setFont(karmaSuture_);
	textTreasurePoints_.setFont(karmaSuture_);
	textLevel_.setFont(karmaSuture_);
	textExp_.setFont(karmaSuture_);

	textFPS_.setFillColor(Color::White);
	textHP_.setFillColor(Color::White);
	textMana_.setFillColor(Color::White);
	textStamina_.setFillColor(Color::White);
	textShellsAmount_.setFillColor(Color::White);
	textPosX_.setFillColor(Color::White);
	textPosY_.setFillColor(Color::White);
	textDDTimer_.setFillColor(Color::White);
	textTreasurePoints_.setFillColor(Color::White);
	textLevel1_.setFillColor(Color::White);
	textExp_.setFillColor(Color::White);

	//chooseLevelMenu
	textLevel1_.setFont(karmaSuture_);
	textLevel1_.setCharacterSize(90);
	textLevel1_.setFillColor(Color::Black);
	textLevel1_.setOutlineColor(Color::White);
	textLevel1_.setOutlineThickness(4);
	textLevel1_.setPosition(250, 305);
	textLevel1_.setString("Level 1");

	textLevel2_.setFont(karmaSuture_);
	textLevel2_.setCharacterSize(90);
	textLevel2_.setFillColor(Color::Black);
	textLevel2_.setOutlineColor(Color::White);
	textLevel2_.setOutlineThickness(4);
	textLevel2_.setPosition(250, 480);
	textLevel2_.setString("Level 2");

	textBack_.setFont(karmaSuture_);
	textBack_.setCharacterSize(90);
	textBack_.setFillColor(Color::Black);
	textBack_.setOutlineColor(Color::White);
	textBack_.setOutlineThickness(4);
	textBack_.setPosition(285, 650);
	textBack_.setString("Back");

	float engineResX = engine_->getResolution().x;
	float engineResY = engine_->getResolution().y;

	spriteMainMenu_.setTexture(textureMainMenu_);
	spriteMainMenu_.setScale(engineResX / textureMainMenu_.getSize().x, engineResY / textureMainMenu_.getSize().y);

	spriteSettings_.setTexture(textureSettings_);
	spriteSettings_.setScale(engineResX / textureSettings_.getSize().x, engineResY / textureSettings_.getSize().y);

	//spritePerksMenuBackground_.setTexture(texturePerksMenu_);
	//spritePerksMenu_.setScale(engineResX / texturePerksMenu_.getSize().x, engineResY / texturePerksMenu_.getSize().y);
	
	/////MainMenu///////////////////////////////////////////////////////////////
	
	Texture texture;
	texture.loadFromFile("./textures/backgrounds/mainMenu/0.gif");
	
	mainMenuBackgroundAnim_ = new Animation(10);
	mainMenuBackgroundAnim_->addTexture("./textures/backgrounds/mainMenu/0.gif");
	mainMenuBackgroundAnim_->addTexture("./textures/backgrounds/mainMenu/1.gif");
	mainMenuBackgroundAnim_->addTexture("./textures/backgrounds/mainMenu/2.gif");
	mainMenuBackgroundAnim_->addTexture("./textures/backgrounds/mainMenu/3.gif");
	mainMenuBackgroundAnim_->addTexture("./textures/backgrounds/mainMenu/4.gif");
	mainMenuBackgroundAnim_->addTexture("./textures/backgrounds/mainMenu/5.gif");
	mainMenuBackgroundAnim_->addTexture("./textures/backgrounds/mainMenu/6.gif");
	mainMenuBackgroundAnim_->addTexture("./textures/backgrounds/mainMenu/7.gif");
	mainMenuBackgroundAnim_->setSpriteScale(engineResX / texture.getSize().x, engineResY / texture.getSize().y);

	texture.loadFromFile("./textures/backgrounds/inGameMenu/0001.png");

	inGameMenuBackgroundAnim_ = new Animation(10);
	inGameMenuBackgroundAnim_->addTexture("./textures/backgrounds/inGameMenu/0001.png");
	inGameMenuBackgroundAnim_->addTexture("./textures/backgrounds/inGameMenu/0002.png");
	inGameMenuBackgroundAnim_->addTexture("./textures/backgrounds/inGameMenu/0003.png");
	inGameMenuBackgroundAnim_->addTexture("./textures/backgrounds/inGameMenu/0004.png");
	inGameMenuBackgroundAnim_->addTexture("./textures/backgrounds/inGameMenu/0005.png");
	inGameMenuBackgroundAnim_->addTexture("./textures/backgrounds/inGameMenu/0006.png");
	inGameMenuBackgroundAnim_->addTexture("./textures/backgrounds/inGameMenu/0007.png");
	inGameMenuBackgroundAnim_->addTexture("./textures/backgrounds/inGameMenu/0008.png");
	inGameMenuBackgroundAnim_->setSpriteScale(engineResX / texture.getSize().x, engineResY / texture.getSize().y);
	
	textContinue.setFont(karmaSuture_);
	textContinue.setCharacterSize(60);
	textContinue.setOutlineThickness(4);
	textContinue.setPosition(90, 800);
	textContinue.setString("CONTINUE");
	
	textNewGame.setFont(karmaSuture_);
	textNewGame.setCharacterSize(60);
	textNewGame.setOutlineThickness(4);
	textNewGame.setPosition(90, 860);
	textNewGame.setString("NEW GAME");
	
	textSettings.setFont(karmaSuture_);
	textSettings.setCharacterSize(60);
	textSettings.setOutlineThickness(4);
	textSettings.setPosition(90, 920);
	textSettings.setString("SETTINGS");
	
	textExit.setFont(karmaSuture_);
	textExit.setCharacterSize(60);
	textExit.setOutlineThickness(4);
	textExit.setPosition(90, 980);
	textExit.setString("EXIT");

	textResume_.setFont(karmaSuture_);
	textResume_.setCharacterSize(60);
	textResume_.setOutlineThickness(4);
	textResume_.setPosition(90, 860);
	textResume_.setString("Resume");

	textSettings2_.setFont(karmaSuture_);
	textSettings2_.setCharacterSize(60);
	textSettings2_.setOutlineThickness(4);
	textSettings2_.setPosition(90, 920);
	textSettings2_.setString("Settings");

	textQuit_.setFont(karmaSuture_);
	textQuit_.setCharacterSize(60);
	textQuit_.setOutlineThickness(4);
	textQuit_.setPosition(90, 980);
	textQuit_.setString("Quit");

////////////////////////////////////////////////////////////////

	//PerksMenu///////////////////////////////////////////////
	texturePerksMenuBackground_.loadFromFile("./textures/backgrounds/background1.jpg");
	textureChestArmorPerkAble_.loadFromFile("./textures/icons/chestArmorPerk2.png");
	textureChestArmorPerkDisable_.loadFromFile("./textures/icons/chestArmorPerk.png");
	textureDrippingBladePerkAble_.loadFromFile("./textures/icons/drippingBladePerk2.png");
	textureDrippingBladePerkDisable_.loadFromFile("./textures/icons/drippingBladePerk.png");
	textureFairyWandPerkAble_.loadFromFile("./textures/icons/fairyWandPerk2.png");
	textureFairyWandPerkDisable_.loadFromFile("./textures/icons/fairyWandPerk.png");
	textureFoamyDiscPerkAble_.loadFromFile("./textures/icons/foamyDiscPerk2.png");
	textureFoamyDiscPerkDisable_.loadFromFile("./textures/icons/foamyDiscPerk.png");
	textureHalfDeadPerkAble_.loadFromFile("./textures/icons/halfDeadPerk2.png");
	textureHalfDeadPerkDisable_.loadFromFile("./textures/icons/halfDeadPerk.png");
	textureHeartPlusPerkAble_.loadFromFile("./textures/icons/heartPlusPerk2.png");
	textureHeartPlusPerkDisable_.loadFromFile("./textures/icons/heartPlusPerk.png");
	textureIceBoltPerkAble_.loadFromFile("./textures/icons/iceBoltPerk2.png");
	textureIceBoltPerkDisable_.loadFromFile("./textures/icons/iceBoltPerk.png");
	textureJugglerPerkAble_.loadFromFile("./textures/icons/jugglerPerk2.png"); 
	textureJugglerPerkDisable_.loadFromFile("./textures/icons/jugglerPerk.png");
	textureTripleScratchesPerkAble_.loadFromFile("./textures/icons/tripleScratchesPerk2.png");
	textureTripleScratchesPerkDisable_.loadFromFile("./textures/icons/tripleScratchesPerk.png");
	textureVampireDraculaPerkAble_.loadFromFile("./textures/icons/vampireDraculaPerk2.png");
	textureVampireDraculaPerkDisable_.loadFromFile("./textures/icons/vampireDraculaPerk.png");

	spritePerksMenuBackground_.setTexture(texturePerksMenuBackground_);
	spritePerksMenuBackground_.setScale(engineResX / texturePerksMenuBackground_.getSize().x, engineResY / texturePerksMenuBackground_.getSize().y);
	spriteChestArmorPerkAble_.setTexture(textureChestArmorPerkAble_);
	spriteChestArmorPerkDisable_.setTexture(textureChestArmorPerkDisable_);
	spriteDrippingBladePerkAble_.setTexture(textureDrippingBladePerkAble_);
	spriteDrippingBladePerkDisable_.setTexture(textureDrippingBladePerkDisable_);
	spriteFairyWandPerkAble_.setTexture(textureFairyWandPerkAble_);
	spriteFairyWandPerkDisable_.setTexture(textureFairyWandPerkDisable_);
	spriteFoamyDiscPerkAble_.setTexture(textureFoamyDiscPerkAble_);
	spriteFoamyDiscPerkDisable_.setTexture(textureFoamyDiscPerkDisable_);
	spriteHalfDeadPerkAble_.setTexture(textureHalfDeadPerkAble_);
	spriteHalfDeadPerkDisable_.setTexture(textureHalfDeadPerkDisable_);
	spriteHeartPlusPerkAble_.setTexture(textureHeartPlusPerkAble_);
	spriteHeartPlusPerkDisable_.setTexture(textureHeartPlusPerkDisable_);
	spriteIceBoltPerkAble_.setTexture(textureIceBoltPerkAble_);
	spriteIceBoltPerkDisable_.setTexture(textureIceBoltPerkDisable_);
	spriteJugglerPerkAble_.setTexture(textureJugglerPerkAble_);
	spriteJugglerPerkDisable_.setTexture(textureJugglerPerkDisable_);
	spriteTripleScratchesPerkAble_.setTexture(textureTripleScratchesPerkAble_);
	spriteTripleScratchesPerkDisable_.setTexture(textureTripleScratchesPerkDisable_);
	spriteVampireDraculaPerkAble_.setTexture(textureVampireDraculaPerkAble_);
	spriteVampireDraculaPerkDisable_.setTexture(textureVampireDraculaPerkDisable_);

	textPerksMenuPerks_.setFont(karmaSuture_);
	textPerksMenuPerks_.setFillColor(Color::Red);
	textPerksMenuPerks_.setOutlineThickness(4);
	textPerksMenuPerks_.setOutlineColor(Color::Black);
	textPerksMenuPerks_.setString("PERKS");

	textPerksMenuBack_.setFont(karmaSuture_);
	textPerksMenuBack_.setOutlineThickness(4);
	textPerksMenuBack_.setString("BACK");

	textPerksMenuI_.setFont(karmaSuture_);
	textPerksMenuI_.setFillColor(Color::Red);
	textPerksMenuI_.setOutlineThickness(4);
	textPerksMenuI_.setOutlineColor(Color::Black);
	textPerksMenuI_.setString("I");

	textPerksMenuII_.setFont(karmaSuture_);
	textPerksMenuII_.setFillColor(Color::Red);
	textPerksMenuII_.setOutlineThickness(4);
	textPerksMenuII_.setOutlineColor(Color::Black);
	textPerksMenuII_.setString("II");

	textPerksMenuIII_.setFont(karmaSuture_);
	textPerksMenuIII_.setFillColor(Color::Red);
	textPerksMenuIII_.setOutlineThickness(4);
	textPerksMenuIII_.setOutlineColor(Color::Black);
	textPerksMenuIII_.setString("III");

	textPerksMenuLevelPoints_.setFont(karmaSuture_);
	textPerksMenuLevelPoints_.setFillColor(Color::Red);
	textPerksMenuLevelPoints_.setOutlineThickness(4);
	textPerksMenuLevelPoints_.setOutlineColor(Color::Black);
	textPerksMenuLevelPoints_.setString("POINTS:");

	textCurrPerkLevel_.setFont(karmaSuture_);
	textCurrPerkLevel_.setFillColor(Color::Red);

	textPerkDescription_.setFont(karmaSuture_);
	textPerkDescription_.setFillColor(Color::Red);

	if (engineResX == 1920 && engineResY == 1080)
	{
		textPerksMenuPerks_.setPosition(830, 75);
		textPerksMenuPerks_.setCharacterSize(100);

		textPerksMenuBack_.setPosition(1650, 950);
		textPerksMenuBack_.setCharacterSize(60);

		textPerksMenuLevelPoints_.setPosition(40, 950);
		textPerksMenuLevelPoints_.setCharacterSize(60);

		textPerksMenuI_.setPosition(40, 280);
		textPerksMenuI_.setCharacterSize(140);

		textPerksMenuII_.setPosition(40, 495);
		textPerksMenuII_.setCharacterSize(140);

		textPerksMenuIII_.setPosition(40, 710);
		textPerksMenuIII_.setCharacterSize(140);

		spriteChestArmorPerkAble_.setPosition(290, 299);
		spriteChestArmorPerkAble_.setScale(0.3, 0.3);
		spriteChestArmorPerkDisable_.setPosition(290, 299);
		spriteChestArmorPerkDisable_.setScale(0.3, 0.3);

		spriteHeartPlusPerkAble_.setPosition(450, 299);
		spriteHeartPlusPerkAble_.setScale(0.3, 0.3);
		spriteHeartPlusPerkDisable_.setPosition(450, 299);
		spriteHeartPlusPerkDisable_.setScale(0.3, 0.3);

		spriteFairyWandPerkAble_.setPosition(610, 299);
		spriteFairyWandPerkAble_.setScale(0.3, 0.3);
		spriteFairyWandPerkDisable_.setPosition(610, 299);
		spriteFairyWandPerkDisable_.setScale(0.3, 0.3);

		spriteFoamyDiscPerkAble_.setPosition(290, 514);
		spriteFoamyDiscPerkAble_.setPosition(290, 514);
		spriteFoamyDiscPerkAble_.setScale(0.3, 0.3);
		spriteFoamyDiscPerkDisable_.setPosition(290, 514);
		spriteFoamyDiscPerkDisable_.setScale(0.3, 0.3);

		spriteIceBoltPerkAble_.setPosition(450, 514);
		spriteIceBoltPerkAble_.setScale(0.3, 0.3);
		spriteIceBoltPerkDisable_.setPosition(450, 514);
		spriteIceBoltPerkDisable_.setScale(0.3, 0.3);

		spriteJugglerPerkAble_.setPosition(610, 514);
		spriteJugglerPerkAble_.setScale(0.3, 0.3);
		spriteJugglerPerkDisable_.setPosition(610, 514);
		spriteJugglerPerkDisable_.setScale(0.3, 0.3);

		spriteDrippingBladePerkAble_.setPosition(770, 514);
		spriteDrippingBladePerkAble_.setScale(0.3, 0.3);
		spriteDrippingBladePerkDisable_.setPosition(770, 514);
		spriteDrippingBladePerkDisable_.setScale(0.3, 0.3);

		spriteHalfDeadPerkAble_.setPosition(290, 729);
		spriteHalfDeadPerkAble_.setScale(0.3, 0.3);
		spriteHalfDeadPerkDisable_.setPosition(290, 729);
		spriteHalfDeadPerkDisable_.setScale(0.3, 0.3);

		spriteTripleScratchesPerkAble_.setPosition(450, 729);
		spriteTripleScratchesPerkAble_.setScale(0.3, 0.3);
		spriteTripleScratchesPerkDisable_.setPosition(450, 729);
		spriteTripleScratchesPerkDisable_.setScale(0.3, 0.3);

		spriteVampireDraculaPerkAble_.setPosition(610, 729);
		spriteVampireDraculaPerkAble_.setScale(0.3, 0.3);
		spriteVampireDraculaPerkDisable_.setPosition(610, 729);
		spriteVampireDraculaPerkDisable_.setScale(0.3, 0.3);

		textCurrPerkLevel_.setPosition(700, 340);
		textCurrPerkLevel_.setCharacterSize(30);

		textPerkDescription_.setPosition(700, 420);
		textPerkDescription_.setCharacterSize(30);
	}

}

Game::~Game()
{
	cout << "In Game distructor" << endl;

	delete mainMenuBackgroundAnim_;
	delete engine_;
}

void Game::start()
{
	mainMenu();
}

void Game::mainMenu()
{
	engine_->setView(0, 0, engine_->getResolution().x, engine_->getResolution().y);
	//view_.reset(sf::FloatRect(0, 0, resolution_.x, resolution_.y));
	//window_.setView(view_);
	engine_->load();
	//bool isFullScreen = true;
	int menuState = 0;

	Vector2f rectSize;
	rectSize.x = 380;
	rectSize.y = 200;

	mainMenuMusic_.play();

	clock_.restart();

	while (engine_->renderWindowIsOpen())
	{
		Event event;
		menuState = -1;
		elapsedTime_ = clock_.restart().asSeconds();

		//TextColor////////////////////////////////////

		textContinue.setFillColor(Color::Black);
		textContinue.setOutlineColor(Color::Red);

		textNewGame.setFillColor(Color::Black);
		textNewGame.setOutlineColor(Color::Red);

		textSettings.setFillColor(Color::Black);
		textSettings.setOutlineColor(Color::Red);

		textExit.setFillColor(Color::Black);
		textExit.setOutlineColor(Color::Red);

		///////////////////////////////////////////////

		//Containing///////////////////////////////////

		if (engine_->mouseContains(textContinue.getGlobalBounds()) && !engine_->isNewGame())
		{
			textContinue.setFillColor(Color::Red);
			textContinue.setOutlineColor(Color::Black);
			menuState = 0;
		}
		if (engine_->mouseContains(textNewGame.getGlobalBounds()))
		{
			textNewGame.setFillColor(Color::Red);
			textNewGame.setOutlineColor(Color::Black);
			menuState = 1;
		}
		if (engine_->mouseContains(textSettings.getGlobalBounds()))
		{
			textSettings.setFillColor(Color::Red);
			textSettings.setOutlineColor(Color::Black);
			menuState = 2;
		}
		if (engine_->mouseContains(textExit.getGlobalBounds()))
		{
			textExit.setFillColor(Color::Red);
			textExit.setOutlineColor(Color::Black);
			menuState = 3;
		}

		////////////////////////////////////////////

		//PollEvent/////////////////////////////

		while (engine_->renderWindowPollEvent())
		{
			Event event = *engine_->getEvent();
			if (event.type == Event::Closed)
			{
				engine_->closeRenderWindow();
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
					engine_->load();
					mainMenuMusic_.stop();
					play();
					mainMenuMusic_.play();
					engine_->setView(0, 0, engine_->getResolution().x, engine_->getResolution().y);
					clock_.restart();
				}
				if (menuState == 1 && mouseButtonPressed_)
				{
					engine_->loadNewGame();
					engine_->setNewGame(false);
					mainMenuMusic_.stop();
					play();
					mainMenuMusic_.play();
					engine_->setView(0, 0, engine_->getResolution().x, engine_->getResolution().y);
					clock_.restart();
				}
				if (menuState == 2 && mouseButtonPressed_)
				{
					settings();
					clock_.restart();
				}
				if (menuState == 3 && mouseButtonPressed_)
				{
					exit(EXIT_SUCCESS);
				}
				mouseButtonPressed_ = false;
			}
		}

		///////////////////////////////////////////

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_->isRenderWindowFullscreen() == false)
		{
			engine_->createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Fullscreen");
			engine_->changeRenderWindowMode();
		}

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_->isRenderWindowFullscreen() == true)
		{
			engine_->createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Close");
			engine_->changeRenderWindowMode();
		}

		engine_->renderWindowClear();

		engine_->draw(mainMenuBackgroundAnim_, elapsedTime_);
		engine_->draw(textContinue);
		engine_->draw(textNewGame);
		engine_->draw(textSettings);
		engine_->draw(textExit);

		engine_->renderWindowDisplay();
	}
}

void Game::play()
{
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

	GameWindow* win1 = engine_->createGameWindow(sizePosMap, "./textures/buttons/button1.png");

	pair<size_t, size_t> res3 = { 1920, 1080 };
	pair<size_t, size_t> size3 = { 200, 50 };
	pair<size_t, size_t> pos3 = { 1000, 500 };

	map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap1;
	sizePosMap1 = {
		{res3, {size3, pos3}},
	};

	Button* btn1 = engine_->createButton("button1", sizePosMap1, "./textures/buttons/button1.png", "./textures/buttons/button12.png", "./textures/buttons/button13.png");

	win1->addButton(btn1);

	string clickedButtonId = "";

	float time = 0;

	Font bebasRegular;
	bebasRegular.loadFromFile("./fonts/Bebas-Regular.otf");

	Text timeText;
	timeText.setString("0");
	timeText.setFont(bebasRegular);
	timeText.setFillColor(Color::Green);

	float iter = 0;
	char* intStr;

	bool start = true;

	gameMusic_.play();

	clock_.restart();

	while (engine_->renderWindowIsOpen())
	{
		engine_->renderWindowClear();

		if (time >= 0.5)
		{
			textFPS_.setString("FPS: " + to_string(int(1 / iter)));
			time = 0;
		}

		while (engine_->renderWindowPollEvent())
		{
			Event event = *engine_->getEvent();
			if (event.type == Event::Closed)
			{
				engine_->closeRenderWindow();
			}
			if ((event.type == Event::MouseButtonPressed) && event.key.code == Mouse::Left)
			{
				string tempClickedButton1Id = engine_->getClickedButtonId(win1);
				if (!tempClickedButton1Id.empty())
					clickedButtonId = tempClickedButton1Id;
			}
			if (event.type == Event::MouseButtonReleased && !clickedButtonId.empty())
			{
				if (engine_->getClickedButtonId(win1) == clickedButtonId)
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
				if (event.key.code == Keyboard::Tab)
				{
					tabPressed_ = true;
				}
				if (event.key.code == Keyboard::Escape)
				{
					escPressed_ = true;
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
					perksMenu();
					clock_.restart();
					tabPressed_ = false;
				}
				if (escPressed_)
				{
					escPressed_ = false;
					gameMusic_.pause();
					if (inGameMenu() == 1)
					{
						gameMusic_.stop();
						return;
					}
					gameMusic_.play();
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_->isRenderWindowFullscreen() == false)
		{
			engine_->createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Fullscreen");
			engine_->changeRenderWindowMode();
		}

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_->isRenderWindowFullscreen() == true)
		{
			engine_->createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Close");
			engine_->changeRenderWindowMode();
		}

		inputValue = engine_->input();
		iter = clock_.getElapsedTime().asSeconds();
		time += iter;

		//view_.reset(FloatRect(player_->getSprite().getPosition().x - sizeX / 2, player_->getSprite().getPosition().y - sizeY / 2, sizeX, sizeY));

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			engine_->setGameWindowVisible(win1);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			engine_->setGameWindowInvisible(win1);
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

		//Check if level is ended////////////////////////

		if (engine_->isEndOfLevel())
		{
			if (loadNextLevel())
			{
				gameMusic_.stop();
				endOfGame();
				return;
			}

			continue;
		}

		////////////////////////////////////////////////

		engine_->draw(elapsedTime_);
		
		if (engine_->update(elapsedTime_) == 1)
		{
			gameMusic_.stop();
			gameOver();
			return;
		}

		engine_->setView(engine_->getPlayerPosition().x - engine_->getViewSize().x / 2, engine_->getPlayerPosition().y - engine_->getViewSize().y / 2, engine_->getViewSize().x, engine_->getViewSize().y);

		//engine_->draw(win1);
		if (showInfo_)
		{
			textFPS_.setPosition(engine_->getViewCenter().x - 620, engine_->getViewCenter().y - 335);
			textHP_.setPosition(engine_->getViewCenter().x - 620, engine_->getViewCenter().y - 305);
			textStamina_.setPosition(engine_->getViewCenter().x - 620, engine_->getViewCenter().y - 275);
			textMana_.setPosition(engine_->getViewCenter().x - 620, engine_->getViewCenter().y - 245);
			textShellsAmount_.setPosition(engine_->getViewCenter().x - 620, engine_->getViewCenter().y - 215);
			textPosX_.setPosition(engine_->getViewCenter().x - 620, engine_->getViewCenter().y - 185);
			textPosY_.setPosition(engine_->getViewCenter().x - 620, engine_->getViewCenter().y - 155);
			textDDTimer_.setPosition(engine_->getViewCenter().x - 620, engine_->getViewCenter().y - 125);
			textTreasurePoints_.setPosition(engine_->getViewCenter().x - 620, engine_->getViewCenter().y - 95);
			textLevel_.setPosition(engine_->getViewCenter().x - 620, engine_->getViewCenter().y - 65);
			textExp_.setPosition(engine_->getViewCenter().x - 620, engine_->getViewCenter().y - 35);

			textHP_.setString("HP: " + to_string((int)engine_->getCurrPlayerHealthPoints()) + " of " + to_string(engine_->getMaxPlayerHealthPoints()));
			textStamina_.setString("Stamina: " + to_string((int)engine_->getCurrPlayerStamina()) + " of " + to_string(engine_->getMaxPlayerStamina()));
			textMana_.setString("Mana: " + to_string((int)engine_->getCurrPlayerMana()) + " of " + to_string(engine_->getMaxPlayerMana()));
			if (engine_->getCurrPlayerShellName() == 0)
				textShellsAmount_.setString("Fireball amount: " + to_string(engine_->getCurrPlayerShellAmount()));
			else if (engine_->getCurrPlayerShellName() == 1)
				textShellsAmount_.setString("Iceball amount: " + to_string(engine_->getCurrPlayerShellAmount()));
			else 
				textShellsAmount_.setString("Poisonball amount: " + to_string(engine_->getCurrPlayerShellAmount()));
			textPosX_.setString("PosX: " + to_string(engine_->getCurrPlayerPosX()));
			textPosY_.setString("PosY: " + to_string(engine_->getCurrPlayerPosY()));
			textDDTimer_.setString("DDTimer: " + to_string(engine_->getDDTimer()));
			textTreasurePoints_.setString("TreasurePoints: " + to_string(engine_->getTreasurePoints()));
			textLevel_.setString("PlayerLevel: " + to_string(engine_->getPlayerLevel()));
			textExp_.setString("Exp: " + to_string(engine_->getPlayerExp()));

			engine_->draw(textFPS_);
			engine_->draw(textHP_);
			engine_->draw(textStamina_);
			engine_->draw(textMana_);
			engine_->draw(textShellsAmount_);
			engine_->draw(textPosX_);
			engine_->draw(textPosY_);
			engine_->draw(textDDTimer_);
			engine_->draw(textTreasurePoints_);
			engine_->draw(textLevel_);
			engine_->draw(textExp_);
		}

		engine_->renderWindowDisplay();
	}
}

void Game::settings()
{
	engine_->setView(0, 0, engine_->getResolution().x, engine_->getResolution().y);

	Text jumpText, turnLeftText, turnRightText, shootText, backText, fireBallText, iceBallText, foamyDiscText, halfDeadText;
	Text jumpOptionText, turnLeftOptionText, turnRightOptionText, shootOptionText, fireBallOptionText, iceBallOptionText, foamyDiscOptionText, halfDeadOptionText;

	jumpText.setFont(karmaSuture_);
	jumpText.setString("Jump");
	jumpText.setPosition(130, 140);
	jumpText.setOutlineThickness(3);
	jumpText.setCharacterSize(60);

	jumpOptionText.setFont(karmaSuture_);
	jumpOptionText.setPosition(590, 140); 
	jumpOptionText.setOutlineThickness(3);
	jumpOptionText.setCharacterSize(60);

	turnLeftOptionText.setFont(karmaSuture_);
	turnLeftOptionText.setPosition(590, 230); 
	turnLeftOptionText.setOutlineThickness(3);
	turnLeftOptionText.setCharacterSize(60);

	turnLeftText.setFont(karmaSuture_);
	turnLeftText.setString("Turn left");
	turnLeftText.setPosition(130, 230);
	turnLeftText.setOutlineThickness(3);
	turnLeftText.setCharacterSize(60);

	turnRightOptionText.setFont(karmaSuture_);
	turnRightOptionText.setPosition(590, 320);
	turnRightOptionText.setOutlineThickness(3);
	turnRightOptionText.setCharacterSize(60);

	turnRightText.setFont(karmaSuture_);
	turnRightText.setString("Turn right");
	turnRightText.setPosition(130, 320);
	turnRightText.setOutlineThickness(3);
	turnRightText.setCharacterSize(60);

	shootOptionText.setFont(karmaSuture_);
	shootOptionText.setPosition(590, 410); 
	shootOptionText.setOutlineThickness(3);
	shootOptionText.setCharacterSize(60);

	shootText.setFont(karmaSuture_);
	shootText.setString("Shoot");
	shootText.setPosition(130, 410);
	shootText.setOutlineThickness(3);
	shootText.setCharacterSize(60);

	fireBallText.setFont(karmaSuture_);
	fireBallText.setString("Fireball");
	fireBallText.setPosition(130, 500);
	fireBallText.setOutlineThickness(3);
	fireBallText.setCharacterSize(60);

	fireBallOptionText.setFont(karmaSuture_);
	fireBallOptionText.setPosition(590, 500);
	fireBallOptionText.setOutlineThickness(3);
	fireBallOptionText.setCharacterSize(60);

	iceBallOptionText.setFont(karmaSuture_);
	iceBallOptionText.setPosition(590, 590);
	iceBallOptionText.setOutlineThickness(3);
	iceBallOptionText.setCharacterSize(60);

	iceBallText.setFont(karmaSuture_);
	iceBallText.setString("Iceball");
	iceBallText.setPosition(130, 590);
	iceBallText.setOutlineThickness(3);
	iceBallText.setCharacterSize(60);

	foamyDiscOptionText.setFont(karmaSuture_);
	foamyDiscOptionText.setPosition(590, 680);
	foamyDiscOptionText.setOutlineThickness(3);
	foamyDiscOptionText.setCharacterSize(60);
	
	foamyDiscText.setFont(karmaSuture_);
	foamyDiscText.setString("Poisonball");
	foamyDiscText.setPosition(130, 680);
	foamyDiscText.setOutlineThickness(3);
	foamyDiscText.setCharacterSize(60);

	halfDeadOptionText.setFont(karmaSuture_);
	halfDeadOptionText.setPosition(590, 770);
	halfDeadOptionText.setOutlineThickness(3);
	halfDeadOptionText.setCharacterSize(60);

	halfDeadText.setFont(karmaSuture_);
	halfDeadText.setString("Halfdead");
	halfDeadText.setPosition(130, 770);
	halfDeadText.setOutlineThickness(3);
	halfDeadText.setCharacterSize(60);

	backText.setFont(karmaSuture_);
	backText.setString("BACK");
	backText.setPosition(1650, 920);
	backText.setOutlineThickness(3);
	backText.setCharacterSize(60);

	int menuState;
	clock_.restart();

	while (engine_->renderWindowIsOpen())
	{
		menuState = -1;
		elapsedTime_ = clock_.restart().asSeconds();

		jumpOptionText.setFillColor(Color::Black);
		jumpOptionText.setOutlineColor(Color::Red);
		jumpOptionText.setString((char)(engine_->getSettings()->getMoveUp() + 65));

		jumpText.setFillColor(Color::Black);
		jumpText.setOutlineColor(Color::Red);

		turnLeftOptionText.setFillColor(Color::Black);
		turnLeftOptionText.setOutlineColor(Color::Red);
		turnLeftOptionText.setString((char)(engine_->getSettings()->getMoveLeft() + 65));

		turnLeftText.setFillColor(Color::Black);
		turnLeftText.setOutlineColor(Color::Red);

		turnRightOptionText.setFillColor(Color::Black);
		turnRightOptionText.setOutlineColor(Color::Red);
		turnRightOptionText.setString((char)(engine_->getSettings()->getMoveRight() + 65));

		turnRightText.setFillColor(Color::Black);
		turnRightText.setOutlineColor(Color::Red);

		shootOptionText.setFillColor(Color::Black);
		shootOptionText.setOutlineColor(Color::Red);
		shootOptionText.setString((char)(engine_->getSettings()->getShoot() + 65));

		shootText.setFillColor(Color::Black);
		shootText.setOutlineColor(Color::Red);

		fireBallText.setFillColor(Color::Black);
		fireBallText.setOutlineColor(Color::Red);

		fireBallOptionText.setFillColor(Color::Black);
		fireBallOptionText.setOutlineColor(Color::Red);
		fireBallOptionText.setString((char)(engine_->getSettings()->getFireBallPerk() + 65));

		iceBallText.setFillColor(Color::Black);
		iceBallText.setOutlineColor(Color::Red);

		iceBallOptionText.setFillColor(Color::Black);
		iceBallOptionText.setOutlineColor(Color::Red);
		iceBallOptionText.setString((char)(engine_->getSettings()->getIceBallPerk() + 65));

		foamyDiscText.setFillColor(Color::Black);
		foamyDiscText.setOutlineColor(Color::Red);

		foamyDiscOptionText.setFillColor(Color::Black);
		foamyDiscOptionText.setOutlineColor(Color::Red);
		foamyDiscOptionText.setString((char)(engine_->getSettings()->getFoamyDiscPerk() + 65));

		halfDeadText.setFillColor(Color::Black);
		halfDeadText.setOutlineColor(Color::Red);

		halfDeadOptionText.setFillColor(Color::Black);
		halfDeadOptionText.setOutlineColor(Color::Red);
		halfDeadOptionText.setString((char)(engine_->getSettings()->getHalfDeadPerk() + 65));

		backText.setFillColor(Color::Black);
		backText.setOutlineColor(Color::Red);


		if (engine_->getEvent()->type == Event::Closed)
		{
			engine_->closeRenderWindow();
		}
		
		if (engine_->mouseContains(backText.getGlobalBounds()))
		{
			backText.setFillColor(Color::Red);
			backText.setOutlineColor(Color::Black);
			menuState = 0;
		}
		else if (engine_->mouseContains(jumpText.getGlobalBounds()))
		{
			jumpOptionText.setFillColor(Color::Red);
			jumpOptionText.setOutlineColor(Color::Black);

			jumpText.setFillColor(Color::Red);
			jumpText.setOutlineColor(Color::Black);

			menuState = 1;
		}
		else if (engine_->mouseContains(turnLeftText.getGlobalBounds()))
		{
			turnLeftOptionText.setFillColor(Color::Red);
			turnLeftOptionText.setOutlineColor(Color::Black);

			turnLeftText.setFillColor(Color::Red);
			turnLeftText.setOutlineColor(Color::Black);

			menuState = 2;
		}
		else if (engine_->mouseContains(turnRightText.getGlobalBounds()))
		{
			turnRightOptionText.setFillColor(Color::Red);
			turnRightOptionText.setOutlineColor(Color::Black);

			turnRightText.setFillColor(Color::Red);
			turnRightText.setOutlineColor(Color::Black);

			menuState = 3;
		}
		else if (engine_->mouseContains(shootText.getGlobalBounds()))
		{
			shootOptionText.setFillColor(Color::Red);
			shootOptionText.setOutlineColor(Color::Black);

			shootText.setFillColor(Color::Red);
			shootText.setOutlineColor(Color::Black);

			menuState = 4;
		}
		else if (engine_->mouseContains(fireBallText.getGlobalBounds()))
		{
			fireBallOptionText.setFillColor(Color::Red);
			fireBallOptionText.setOutlineColor(Color::Black);

			fireBallText.setFillColor(Color::Red);
			fireBallText.setOutlineColor(Color::Black);

			menuState = 5;
		}
		else if (engine_->mouseContains(iceBallText.getGlobalBounds()))
		{
			iceBallOptionText.setFillColor(Color::Red);
			iceBallOptionText.setOutlineColor(Color::Black);

			iceBallText.setFillColor(Color::Red);
			iceBallText.setOutlineColor(Color::Black);

			menuState = 6;
		}
		else if (engine_->mouseContains(foamyDiscText.getGlobalBounds()))
		{
			foamyDiscOptionText.setFillColor(Color::Red);
			foamyDiscOptionText.setOutlineColor(Color::Black);

			foamyDiscText.setFillColor(Color::Red);
			foamyDiscText.setOutlineColor(Color::Black);

			menuState = 7;
		}
		else if (engine_->mouseContains(halfDeadText.getGlobalBounds()))
		{
			halfDeadOptionText.setFillColor(Color::Red);
			halfDeadOptionText.setOutlineColor(Color::Black);

			halfDeadText.setFillColor(Color::Red);
			halfDeadText.setOutlineColor(Color::Black);

			menuState = 8;
		}

		while (engine_->renderWindowPollEvent())
		{
			Event event = *engine_->getEvent();

			if (event.type == Event::Closed)
			{
				engine_->closeRenderWindow();
			}

			if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left)
			{
				mouseButtonPressed_ = true;
			}
			if (event.type == Event::MouseButtonReleased && mouseButtonPressed_)
			{
				if (menuState > 0)
				{
					while (true)
					{
						engine_->renderWindowPollEvent();

						if (engine_->getEvent()->type == Event::TextEntered)
						{
							if (menuState == 1)
								engine_->getSettings()->setMoveUp(engine_->getEvent()->text.unicode - 32);
							else if (menuState == 2)
								engine_->getSettings()->setMoveLeft(engine_->getEvent()->text.unicode - 32);
							else if (menuState == 3)
								engine_->getSettings()->setMoveRight(engine_->getEvent()->text.unicode - 32);
							else if (menuState == 4)
								engine_->getSettings()->setShoot(engine_->getEvent()->text.unicode - 32);
							else if (menuState == 5)
								engine_->getSettings()->setFireBallPerk(engine_->getEvent()->text.unicode - 32);
							else if (menuState == 6)
								engine_->getSettings()->setIceBallPerk(engine_->getEvent()->text.unicode - 32);
							else if (menuState == 7)
								engine_->getSettings()->setFoamyDiscPerk(engine_->getEvent()->text.unicode - 32);
							else if (menuState == 8)
								engine_->getSettings()->setHalfDeadPerk(engine_->getEvent()->text.unicode - 32);

							break;
						}
					}
				}

				mouseButtonPressed_ = false;
			}
		}

		if (Mouse::isButtonPressed(Mouse::Left) && menuState == 0)
		{
			break;
		}

		engine_->renderWindowClear();

		
		engine_->draw(mainMenuBackgroundAnim_, elapsedTime_);

		engine_->draw(jumpOptionText);
		engine_->draw(jumpText);
		engine_->draw(turnLeftOptionText);
		engine_->draw(turnLeftText);
		engine_->draw(turnRightOptionText);
		engine_->draw(turnRightText);
		engine_->draw(shootOptionText);
		engine_->draw(shootText);
		engine_->draw(backText);
		engine_->draw(fireBallText);
		engine_->draw(fireBallOptionText);
		engine_->draw(iceBallText);
		engine_->draw(iceBallOptionText);
		engine_->draw(foamyDiscText);
		engine_->draw(foamyDiscOptionText);
		engine_->draw(halfDeadText);
		engine_->draw(halfDeadOptionText);

		engine_->renderWindowDisplay();
	}
}

void Game::perksMenu()
{
	int menuState;
	int currMenuState = 0;
	clock_.restart();

	engine_->setView(0, 0, engine_->getResolution().x, engine_->getResolution().y);

	//test/////////////////////////////////////////////////

	//gameWindow

	//1920x1080
	pair<size_t, size_t> res1 = { 1920, 1080 };
	pair<size_t, size_t> size1 = { 600, 500 };
	pair<size_t, size_t> pos1 = { 660, 290 };

	//1366x768
	pair<size_t, size_t> res2 = { 1366, 768 };
	pair<size_t, size_t> size2 = { 600, 400 };
	pair<size_t, size_t> pos2 = { 200, 100 };

	map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMapGameWindow;
	sizePosMapGameWindow = {
		{res1, {size1, pos1}},
		{res2, {size2, pos2}},
	};

	//btnConfirm

	//1920x1080
	pair<size_t, size_t> resBtnConfirm1 = { 1920, 1080 };
	pair<size_t, size_t> sizeBtnConfirm1 = { 100, 50 };
	pair<size_t, size_t> posBtnConfirm1 = { 1145, 720 };

	//1366x768
	pair<size_t, size_t> resBtnConfirm2 = { 1366, 768 };
	pair<size_t, size_t> sizeBtnConfirm2 = { 600, 400 };
	pair<size_t, size_t> posBtnConfirm2 = { 200, 100 };

	map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMapButtonConfirm;
	sizePosMapButtonConfirm = {
		{resBtnConfirm1, {sizeBtnConfirm1, posBtnConfirm1}},
		{resBtnConfirm2, {sizeBtnConfirm2, posBtnConfirm2}},
	};

	//btnClose

	//1920x1080
	pair<size_t, size_t> resBtnClose1 = { 1920, 1080 };
	pair<size_t, size_t> sizeBtnClose1 = { 100, 50 };
	pair<size_t, size_t> posBtnClose1 = { 1035, 720 };

	//1366x768
	pair<size_t, size_t> resBtnClose2 = { 1366, 768 };
	pair<size_t, size_t> sizeBtnClose2 = { 600, 400 };
	pair<size_t, size_t> posBtnClose2 = { 200, 100 };

	map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMapButtonClose;
	sizePosMapButtonClose = {
		{resBtnClose1, {sizeBtnClose1, posBtnClose1}},
		{resBtnClose2, {sizeBtnClose2, posBtnClose2}},
	};

	GameWindow* gameWindowPerk = engine_->createGameWindow(sizePosMapGameWindow, "./textures/backgrounds/gameWindowPerk2.png");

	Button* buttonConfirm = engine_->createButton("Confirm", sizePosMapButtonConfirm, "./textures/buttons/confirmButtonContains.png", "./textures/buttons/confirmButton.png", "./textures/buttons/confirmButtonClick.png");
	Button* buttonClose = engine_->createButton("Close", sizePosMapButtonClose, "./textures/buttons/closeButtonContains.png", "./textures/buttons/closeButton.png", "./textures/buttons/closeButtonClick.png");

	gameWindowPerk->addButton(buttonConfirm);
	gameWindowPerk->addButton(buttonClose);
	//

	while (engine_->renderWindowIsOpen())
	{
		menuState = -1;

		textPerksMenuBack_.setFillColor(Color::Red);
		textPerksMenuBack_.setOutlineColor(Color::Black);

		textPerksMenuLevelPoints_.setString("Points: " + to_string(engine_->getPlayerLevelPoints()));

		auto playerPerks = engine_->getPlayerPerksInfo();

		if (engine_->getEvent()->type == Event::Closed)
		{
			engine_->closeRenderWindow();
		}
		
		if (engine_->mouseContains(textPerksMenuBack_.getGlobalBounds()))
		{
			textPerksMenuBack_.setFillColor(Color::Black);
			textPerksMenuBack_.setOutlineColor(Color::Red);

			menuState = 0;
		}
		else if (engine_->mouseContains(spriteChestArmorPerkAble_))
		{
			menuState = 1;
		}
		else if (engine_->mouseContains(spriteHeartPlusPerkAble_))
		{
			menuState = 2;
		}
		else if (engine_->mouseContains(spriteFairyWandPerkAble_))
		{
			menuState = 3;
		}
		else if (engine_->mouseContains(spriteFoamyDiscPerkAble_))
		{
			menuState = 4;
		}
		else if (engine_->mouseContains(spriteIceBoltPerkAble_))
		{
			menuState = 5;
		}
		else if (engine_->mouseContains(spriteJugglerPerkAble_))
		{
			menuState = 6;
		}
		else if (engine_->mouseContains(spriteDrippingBladePerkAble_))
		{
			menuState = 7;
		}
		else if (engine_->mouseContains(spriteHalfDeadPerkAble_))
		{
			menuState = 8;
		}
		else if (engine_->mouseContains(spriteTripleScratchesPerkAble_))
		{
			menuState = 9;
		}
		else if (engine_->mouseContains(spriteVampireDraculaPerkAble_))
		{
			menuState = 10;
		}

		while (engine_->renderWindowPollEvent())
		{
			Event event = *engine_->getEvent();
			if (event.type == Event::Closed)
			{
				engine_->closeRenderWindow();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Tab)
				{
					tabPressed_ = true;
				}
			}
			if (event.type == Event::KeyReleased)
			{
				if (tabPressed_)
				{
					tabPressed_ = false;
					return;
				}
			}
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					mouseButtonPressed_ = true;

					string tempClickedButtonId = engine_->getClickedButtonId(gameWindowPerk);
					if (!tempClickedButtonId.empty())
						clickedButtonId_ = tempClickedButtonId;
				}
			}
			if (event.type == Event::MouseButtonReleased)
			{
				if (!clickedButtonId_.empty())
				{
					if (engine_->getClickedButtonId(gameWindowPerk) == clickedButtonId_)
					{
						if (clickedButtonId_ == "Confirm")
						{
							if (currMenuState == 1)
							{
								engine_->getPlayer()->setChestArmorPerk();
							}
							else if (currMenuState == 2)
							{
								engine_->getPlayer()->setHeartPlusPerk();
							}
							else if (currMenuState == 3)
							{
								engine_->getPlayer()->setFairyWandPerk();
							}
							else if (currMenuState == 4)
							{
								engine_->getPlayer()->setFoamyDiscPerk();
							}
							else if (currMenuState == 5)
							{
								engine_->getPlayer()->setIceBallPerk();
							}
							else if (currMenuState == 6)
							{
								engine_->getPlayer()->setJugglerPerk();
							}
							else if (currMenuState == 7)
							{
								engine_->getPlayer()->setDrippingBladePerk();
							}
							else if (currMenuState == 8)
							{
								engine_->getPlayer()->setHalfDeadPerk();
							}
							else if (currMenuState == 9)
							{
								engine_->getPlayer()->setTripleScratchesPerk();
							}
							else if (currMenuState == 10)
							{
								engine_->getPlayer()->setVampireDraculaPerk();
							}
						}
					}

					clickedButtonId_ = "";
				}

				engine_->setGameWindowInvisible(gameWindowPerk);

				if (menuState == 0 && mouseButtonPressed_)
				{
					currMenuState = 0;
					//player->setFairyWandPerk();
					return;
				}
				else if (menuState == 1 && mouseButtonPressed_)
				{
					currMenuState = 1;

					textCurrPerkLevel_.setString("Level: " + to_string(playerPerks.chestArmorPerkLevel_) + " max 3");
					textPerkDescription_.setString("Description:\n+" + to_string(playerPerks.chestArmorPerkBonus_) + "% damage resistance");

					gameWindowPerk->deleteTexts();
					gameWindowPerk->addText(textCurrPerkLevel_);
					gameWindowPerk->addText(textPerkDescription_);
					engine_->setGameWindowVisible(gameWindowPerk);
				}
				else if (menuState == 2 && mouseButtonPressed_)
				{
					currMenuState = 2;

					textCurrPerkLevel_.setString("Level: " + to_string(playerPerks.heartPlusPerkLevel_) + " max 3");
					textPerkDescription_.setString("Description:\n+" + to_string(playerPerks.heartPlusPerkBonus_) + " hp");

					gameWindowPerk->deleteTexts();
					gameWindowPerk->addText(textCurrPerkLevel_);
					gameWindowPerk->addText(textPerkDescription_);
					engine_->setGameWindowVisible(gameWindowPerk);
				}
				else if (menuState == 3 && mouseButtonPressed_)
				{
					currMenuState = 3;

					textCurrPerkLevel_.setString("Level: " + to_string(playerPerks.fairyWandPerkLevel_) + " max 3");
					textPerkDescription_.setString("Description:\n+" + to_string(playerPerks.fairyWandPerkBonus_) + " mana");

					gameWindowPerk->deleteTexts();
					gameWindowPerk->addText(textCurrPerkLevel_);
					gameWindowPerk->addText(textPerkDescription_);
					engine_->setGameWindowVisible(gameWindowPerk);
				}
				else if (menuState == 4 && mouseButtonPressed_)
				{
					currMenuState = 4;

					textCurrPerkLevel_.setString("Level: " + to_string(playerPerks.foamyDiscPerkLevel_) + " max 1");
					textPerkDescription_.setString("Description:\nPoisoning magical skill");

					gameWindowPerk->deleteTexts();
					gameWindowPerk->addText(textCurrPerkLevel_);
					gameWindowPerk->addText(textPerkDescription_);
					engine_->setGameWindowVisible(gameWindowPerk);
				}
				else if (menuState == 5 && mouseButtonPressed_)
				{
					currMenuState = 5;

					textCurrPerkLevel_.setString("Level: " + to_string(playerPerks.iceBallPerkLevel_) + " max 1");
					textPerkDescription_.setString("Description:\nFreezing magical skill");

					gameWindowPerk->deleteTexts();
					gameWindowPerk->addText(textCurrPerkLevel_);
					gameWindowPerk->addText(textPerkDescription_);
					engine_->setGameWindowVisible(gameWindowPerk);
				}
				else if (menuState == 6 && mouseButtonPressed_)
				{
					currMenuState = 6;

					textCurrPerkLevel_.setString("Level: " + to_string(playerPerks.jugglerPerkLevel_) + " max 3");
					textPerkDescription_.setString("Description:\nGives more magical damage:\nLevel 1: +50 damage\nLevel 2: +100 damage\nLevel 3: +150 damage\n");

					gameWindowPerk->deleteTexts();
					gameWindowPerk->addText(textCurrPerkLevel_);
					gameWindowPerk->addText(textPerkDescription_);
					engine_->setGameWindowVisible(gameWindowPerk);
				}
				else if (menuState == 7 && mouseButtonPressed_)
				{
					currMenuState = 7;

					textCurrPerkLevel_.setString("Level: " + to_string(playerPerks.drippingBladePerkLevel_) + " max 3");
					textPerkDescription_.setString("Description:\nGives more hand damage:\nLevel 1: +100 damage\nLevel 2: +175 damage\nLevel 3: +250 damage\n");

					gameWindowPerk->deleteTexts();
					gameWindowPerk->addText(textCurrPerkLevel_);
					gameWindowPerk->addText(textPerkDescription_);
					engine_->setGameWindowVisible(gameWindowPerk);
				}
				else if (menuState == 8 && mouseButtonPressed_)
				{
					currMenuState = 8;

					textCurrPerkLevel_.setString("Level: " + to_string(playerPerks.halfDeadPerkLevel_) + " max 1");
					textPerkDescription_.setString("Description:\nConverts mana into hp");

					gameWindowPerk->deleteTexts();
					gameWindowPerk->addText(textCurrPerkLevel_);
					gameWindowPerk->addText(textPerkDescription_);
					engine_->setGameWindowVisible(gameWindowPerk);
				}
				else if (menuState == 9 && mouseButtonPressed_)
				{
					currMenuState = 9;

					textCurrPerkLevel_.setString("Level: " + to_string(playerPerks.tripleScratchesPerkLevel_) + " max 1");
					textPerkDescription_.setString("Description:\nIncreases player's damage on 30%\nif hp is lower than 50%");

					gameWindowPerk->deleteTexts();
					gameWindowPerk->addText(textCurrPerkLevel_);
					gameWindowPerk->addText(textPerkDescription_);
					engine_->setGameWindowVisible(gameWindowPerk);
				}
				else if (menuState == 10 && mouseButtonPressed_)
				{
					currMenuState = 10;

					textCurrPerkLevel_.setString("Level: " + to_string(playerPerks.vampireDraculaPerkLevel_) + " max 1");
					textPerkDescription_.setString("Description:\n15% vampirism");

					gameWindowPerk->deleteTexts();
					gameWindowPerk->addText(textCurrPerkLevel_);
					gameWindowPerk->addText(textPerkDescription_);
					engine_->setGameWindowVisible(gameWindowPerk);
				}
				mouseButtonPressed_ = false;
			}
		}

		engine_->renderWindowClear();


		drawPerksMenu();

		engine_->draw(gameWindowPerk);

		engine_->renderWindowDisplay();
	}
}

void Game::endOfGame()
{
	engine_->setView(0, 0, engine_->getResolution().x, engine_->getResolution().y);

	Text textCompletion;
	Text textElse;

	textCompletion.setFont(karmaSuture_);
	textCompletion.setFillColor(Color::Red);
	textCompletion.setString("You have completed the game. Thank you for playing!");

	textElse.setFont(karmaSuture_);
	textElse.setFillColor(Color::Red);
	textElse.setString("Press any key to exit");

	if (engine_->getResolution().x == 1920 && engine_->getResolution().y == 1080)
	{
		textCompletion.setCharacterSize(50);
		textElse.setCharacterSize(30);
		textCompletion.setPosition(50, 80);
		textElse.setPosition(50, 1000);
	}
	else if (engine_->getResolution().x == 1366 && engine_->getResolution().y == 768)
	{
		textCompletion.setCharacterSize(40);
		textElse.setCharacterSize(25);
		textCompletion.setPosition(40, 60);
		textElse.setPosition(40, 690);
	}

	while (engine_->renderWindowIsOpen())
	{
		while (engine_->renderWindowPollEvent())
		{
			Event event = *engine_->getEvent();
			if (event.type == Event::Closed)
			{
				engine_->closeRenderWindow();
			}
			else if (event.type == Event::KeyPressed)
			{
				return;
			}
		}

		engine_->renderWindowClear();
		engine_->draw(textCompletion);
		engine_->draw(textElse);
		engine_->renderWindowDisplay();
	}
}

void Game::gameOver()
{
	engine_->setView(0, 0, engine_->getResolution().x, engine_->getResolution().y);

	Text textCompletion;
	Text textElse;

	textCompletion.setFont(karmaSuture_);
	textCompletion.setFillColor(Color::Red);
	textCompletion.setString("You are dead. Game over");

	textElse.setFont(karmaSuture_);
	textElse.setFillColor(Color::Red);
	textElse.setString("Press any key to exit");

	if (engine_->getResolution().x == 1920 && engine_->getResolution().y == 1080)
	{
		textCompletion.setCharacterSize(50);
		textElse.setCharacterSize(30);
		textCompletion.setPosition(50, 80);
		textElse.setPosition(50, 1000);
	}
	else if (engine_->getResolution().x == 1366 && engine_->getResolution().y == 768)
	{
		textCompletion.setCharacterSize(40);
		textElse.setCharacterSize(25);
		textCompletion.setPosition(40, 60);
		textElse.setPosition(40, 690);
	}

	while (engine_->renderWindowIsOpen())
	{
		while (engine_->renderWindowPollEvent())
		{
			Event event = *engine_->getEvent();
			if (event.type == Event::Closed)
			{
				engine_->closeRenderWindow();
			}
			else if (event.type == Event::KeyPressed)
			{
				return;
			}
		}

		engine_->renderWindowClear();
		engine_->draw(textCompletion);
		engine_->draw(textElse);
		engine_->renderWindowDisplay();
	}
}

int Game::inGameMenu()
{
	engine_->setView(0, 0, engine_->getResolution().x, engine_->getResolution().y);

	int menuState = 0;

	Vector2f rectSize;
	rectSize.x = 380;
	rectSize.y = 200;

	mainMenuMusic_.play();

	clock_.restart();

	while (engine_->renderWindowIsOpen())
	{
		Event event;
		menuState = -1;
		elapsedTime_ = clock_.restart().asSeconds();

		//TextColor////////////////////////////////////

		textResume_.setFillColor(Color::Black);
		textResume_.setOutlineColor(Color::Red);

		textSettings2_.setFillColor(Color::Black);
		textSettings2_.setOutlineColor(Color::Red);

		textQuit_.setFillColor(Color::Black);
		textQuit_.setOutlineColor(Color::Red);

		///////////////////////////////////////////////

		//Containing///////////////////////////////////

	
		if (engine_->mouseContains(textResume_.getGlobalBounds()))
		{
			textResume_.setFillColor(Color::Red);
			textResume_.setOutlineColor(Color::Black);
			menuState = 0;
		}
		if (engine_->mouseContains(textSettings2_.getGlobalBounds()))
		{
			textSettings2_.setFillColor(Color::Red);
			textSettings2_.setOutlineColor(Color::Black);
			menuState = 1;
		}
		if (engine_->mouseContains(textQuit_.getGlobalBounds()))
		{
			textQuit_.setFillColor(Color::Red);
			textQuit_.setOutlineColor(Color::Black);
			menuState = 2;
		}

		////////////////////////////////////////////

		//PollEvent/////////////////////////////

		while (engine_->renderWindowPollEvent())
		{
			Event event = *engine_->getEvent();
			if (event.type == Event::Closed)
			{
				engine_->closeRenderWindow();
			}

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					mouseButtonPressed_ = true;
				}
			}
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
				{
					escPressed_ = true;
				}
			}
			else if (event.type == Event::KeyReleased)
			{
				if (escPressed_)
				{
					escPressed_ = false;
					return 0;
				}
			}
			if (event.type == Event::MouseButtonReleased)
			{
				if (menuState == 0 && mouseButtonPressed_)
				{
					mainMenuMusic_.pause();
					return 0;
				}
				else if (menuState == 1 && mouseButtonPressed_)
				{
					settings();
					clock_.restart();
				}
				else if (menuState == 2 && mouseButtonPressed_)
				{
					return 1;
				}

				mouseButtonPressed_ = false;
			}
		}

		///////////////////////////////////////////

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_->isRenderWindowFullscreen() == false)
		{
			engine_->createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Fullscreen");
			engine_->changeRenderWindowMode();
		}

		if (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Enter) && engine_->isRenderWindowFullscreen() == true)
		{
			engine_->createRenderWindow(VideoMode::getDesktopMode(), "NineRings", "Close");
			engine_->changeRenderWindowMode();
		}

		engine_->renderWindowClear();

		engine_->draw(inGameMenuBackgroundAnim_, elapsedTime_);
		engine_->draw(textResume_);
		engine_->draw(textSettings2_);
		engine_->draw(textQuit_);

		engine_->renderWindowDisplay();
	}
}

int Game::loadNextLevel()
{
	if (engine_->getCurrLevelNumber() == 1)
	{
		Level* level2 = new Level2();
		engine_->createLevel(level2);
		engine_->getPlayer()->setPosition(64 * 15, 64 * 7);
		return 0;
	}
	else if (engine_->getCurrLevelNumber() == 2)
	{
		return 1;
	}
}

void Game::drawPerksMenu()
{
	engine_->draw(spritePerksMenuBackground_);
	engine_->draw(textPerksMenuBack_);
	engine_->draw(textPerksMenuLevelPoints_);
	engine_->draw(textPerksMenuPerks_);
	engine_->draw(textPerksMenuI_);
	engine_->draw(textPerksMenuII_);
	engine_->draw(textPerksMenuIII_);

	if (engine_->getPlayerLevelPoints() < 1)
	{
		engine_->draw(spriteChestArmorPerkDisable_);
		engine_->draw(spriteHeartPlusPerkDisable_);
		engine_->draw(spriteFairyWandPerkDisable_);
		engine_->draw(spriteFoamyDiscPerkDisable_);
		engine_->draw(spriteIceBoltPerkDisable_);
		engine_->draw(spriteJugglerPerkDisable_);
		engine_->draw(spriteDrippingBladePerkDisable_);
		engine_->draw(spriteHalfDeadPerkDisable_);
		engine_->draw(spriteTripleScratchesPerkDisable_);
		engine_->draw(spriteVampireDraculaPerkDisable_);
	}
	else if (engine_->getPlayerLevelPoints() < 2)
	{
		engine_->draw(spriteChestArmorPerkAble_);
		engine_->draw(spriteHeartPlusPerkAble_);
		engine_->draw(spriteFairyWandPerkAble_);
		engine_->draw(spriteFoamyDiscPerkDisable_);
		engine_->draw(spriteIceBoltPerkDisable_);
		engine_->draw(spriteJugglerPerkDisable_);
		engine_->draw(spriteDrippingBladePerkDisable_);
		engine_->draw(spriteHalfDeadPerkDisable_);
		engine_->draw(spriteTripleScratchesPerkDisable_);
		engine_->draw(spriteVampireDraculaPerkDisable_);
	}
	else if (engine_->getPlayerLevelPoints() < 3)
	{
		engine_->draw(spriteChestArmorPerkAble_);
		engine_->draw(spriteHeartPlusPerkAble_);
		engine_->draw(spriteFairyWandPerkAble_);
		engine_->draw(spriteFoamyDiscPerkAble_);
		engine_->draw(spriteIceBoltPerkAble_);
		engine_->draw(spriteJugglerPerkAble_);
		engine_->draw(spriteDrippingBladePerkAble_);
		engine_->draw(spriteHalfDeadPerkDisable_);
		engine_->draw(spriteTripleScratchesPerkDisable_);
		engine_->draw(spriteVampireDraculaPerkDisable_);
	}
	else
	{
		engine_->draw(spriteChestArmorPerkAble_);
		engine_->draw(spriteHeartPlusPerkAble_);
		engine_->draw(spriteFairyWandPerkAble_);
		engine_->draw(spriteFoamyDiscPerkAble_);
		engine_->draw(spriteIceBoltPerkAble_);
		engine_->draw(spriteJugglerPerkAble_);
		engine_->draw(spriteDrippingBladePerkAble_);
		engine_->draw(spriteHalfDeadPerkAble_);
		engine_->draw(spriteTripleScratchesPerkAble_);
		engine_->draw(spriteVampireDraculaPerkAble_);
	}
}