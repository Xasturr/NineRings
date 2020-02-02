#include "game.h"

void Game::start()
{
	engine_.createRenderWindow(VideoMode(engine_.getResolution().x, engine_.getResolution().y), "NineRings", "Close");

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
	engine_.setPlayer("Character1", 200, 130);

	while (engine_.renderWindowIsOpen())
	{
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

		inputValue = engine_.input();
		engine_.update();

		//if (Keyboard::isKeyPressed(Keyboard::A))
		//{
		//	engine_.setGameWindowVisible(win1);
		//}
		//if (Keyboard::isKeyPressed(Keyboard::S))
		//{
		//	engine_.setGameWindowInvisible(win1);
		//}

		engine_.renderWindowClear();
		//engine_.buildMap();
		//engine_.drawGameWindow(win1);
		engine_.draw();
		engine_.renderWindowDisplay();
	}
}

Game::Game()
{
	inputValue = 0;
}

Game::~Game()
{

}