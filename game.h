#pragma once

#include "engine.h"
#include "level1.h"
#include "level2.h"

using namespace sf;
using namespace std;

class Game
{
	Engine* engine_ = Engine::getEngineInstance();

	Clock clock_;

	Font bebasRegular_;
	Font arcadeClassic_;
	Font playMyGames_;
	Font karmaSuture_;

	int inputValue;

	float elapsedTime_;
	float clickTime_;

	bool showInfo_;
	bool iPressed_;
	bool tabPressed_;
	bool mouseButtonPressed_;
	//bool showNewLevel_;

	Text textFPS_;
	Text textHP_;
	Text textMana_;
	Text textStamina_;
	Text textShellsAmount_;
	Text textPosX_;
	Text textPosY_;
	Text textDDTimer_;
	Text textTreasurePoints_;
	Text textLevel_;
	Text textExp_;

	//chooseLevelMenu
	Text textLevel1_;
	Text textLevel2_;
	Text textBack_;

	Texture textureMainMenu_;
	Texture textureSettings_;

	Sprite spriteMainMenu_;
	Sprite spriteSettings_;

	map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap_;

	resolutions resolutions_;

	Animation* mainMenuBackgroundAnim_;
	Text textContinue, textNewGame, textSettings, textExit;

	//perksMenu
	Texture texturePerksMenuBackground_;
	Texture textureChestArmorPerkAble_;
	Texture textureChestArmorPerkDisable_;
	Texture textureDrippingBladePerkAble_;
	Texture textureDrippingBladePerkDisable_;
	Texture textureFairyWandPerkAble_;
	Texture textureFairyWandPerkDisable_;
	Texture textureFoamyDiscPerkAble_;
	Texture textureFoamyDiscPerkDisable_;
	Texture textureHalfDeadPerkAble_;
	Texture textureHalfDeadPerkDisable_;
	Texture textureHeartPlusPerkAble_;
	Texture textureHeartPlusPerkDisable_;
	Texture textureIceBoltPerkAble_;
	Texture textureIceBoltPerkDisable_;
	Texture textureJugglerPerkAble_;
	Texture textureJugglerPerkDisable_;
	Texture textureTripleScratchesPerkAble_;
	Texture textureTripleScratchesPerkDisable_;
	Texture textureVampireDraculaPerkAble_;
	Texture textureVampireDraculaPerkDisable_;
	Sprite spritePerksMenuBackground_;
	Sprite spriteChestArmorPerkAble_;
	Sprite spriteChestArmorPerkDisable_;
	Sprite spriteDrippingBladePerkAble_;
	Sprite spriteDrippingBladePerkDisable_;
	Sprite spriteFairyWandPerkAble_;
	Sprite spriteFairyWandPerkDisable_;
	Sprite spriteFoamyDiscPerkAble_;
	Sprite spriteFoamyDiscPerkDisable_;
	Sprite spriteHalfDeadPerkAble_;
	Sprite spriteHalfDeadPerkDisable_;
	Sprite spriteHeartPlusPerkAble_;
	Sprite spriteHeartPlusPerkDisable_;
	Sprite spriteIceBoltPerkAble_;
	Sprite spriteIceBoltPerkDisable_;
	Sprite spriteJugglerPerkAble_;
	Sprite spriteJugglerPerkDisable_;
	Sprite spriteTripleScratchesPerkAble_;
	Sprite spriteTripleScratchesPerkDisable_;
	Sprite spriteVampireDraculaPerkAble_;
	Sprite spriteVampireDraculaPerkDisable_;
	Text textPerksMenuPerks_;
	Text textPerksMenuBack_;
	Text textPerksMenuI_;
	Text textPerksMenuII_;
	Text textPerksMenuIII_;
	Text textPerksMenuLevelPoints_;
	Text textCurrPerkLevel_;
	Text textPerkDescription_;

	string clickedButtonId_;

	void mainMenu();
	void play();
	void chooseLevelMenu(); //
	void settings();
	void perksMenu();

	void loadNextLevel();
	void drawPerksMenu();

public:
	Game();
	~Game();

	void start();
};