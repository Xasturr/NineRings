#include "game.h"

Game::Game()
{
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
}

Game::~Game()
{

}

void Game::start()
{
	engine_.createRenderWindow(VideoMode(engine_.getResolution().x, engine_.getResolution().y), "NineRings", "Fullscreen");

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
	
	engine_.createLevel(new Level1());
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