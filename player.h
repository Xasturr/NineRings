#pragma once

#include <SFML/Graphics.hpp>

#include "character1.h"
#include "map.h"
#include "gameWindow.h"
#include "perksInfo.h"

using namespace sf;
using namespace std;

class Player
{
	Character* character_;

	string charName_;

	bool leftPressed_;
	bool rightPressed_;
	bool upPressed_;
	bool downPressed_;
	bool attack_;
	bool runAttack_;
	bool shoot_;
	bool doubleDamage_;
	bool newExp_;
	bool newLvl_;
	bool newGame_;

	string currShellName_;

	int getJumpStaminaCost();
	int getAttackStaminaCost();

	int exp_;
	int lvl_;
	int levelPoints_;
	int treasurePoints_;
	//int heartPlusPerkBonus_;
	//int heartPlusPerkLevel_;
	//int chestArmorPerkBonus_;
	//int chestArmorPerkLevel_;
	//int fairyWandPerkBonus_;
	//int fairyWandPerkLevel_;
	//int vampireDraculaPerkBonus_;
	//int vampireDraculaPerkLevel_;
	//int foamyDiscPerkLevel_;
	//int halfDeadPerkLevel_;
	//int iceBoltPerkLevel_;
	//int jugglerPerkLevel_;
	//int tripleScratchesPerkLevel_;
	//int dripplingBladePerkLevel_;

	struct perksInfo perksInfo_;

	void updateLevel(RenderWindow* window);

	float ddTimer_;
	float ddDuration_;

public:
	Player(string charName, float posX, float posY);
	~Player();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void attack();
	void shoot();

	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	void stopAttack();
	void stopShoot();

	void update(float elapsedTime, RenderWindow* window);
	void setPosition(float posX, float posY);
	void setCurrGravityAccel(float value);
	void setCurrJumpAccel(float value);
	void setJumpState(bool flag);
	void setState(string state);
	void interactionWithMap(Vector2f oldPlayerPosition, Vector2f newPlayerPosition, Map* map, float elapsedTime);
	void calculateVariables(float elapsedTime);
	void setEnemyDamaged(bool flag);
	void setCurrHealthPoints(int healthPoints);
	void setLife(bool flag);
	void setHurt(bool flag);
	void flyingShellsUpdateAndDraw(float elapsedTime, Map* map, RenderWindow* window);
	void setCurrStamina(float currStamina);
	void setCurrMana(float currMana);
	void setDoubleDamage();
	void updateDoubleDamage(float elapsedTime);
	void setCurrExp(int exp);
	void setHeartPlusPerk();
	void setChestArmorPerk();
	void setFairyWandPerk();
	void setVampireDraculaPerk();
	void setCurrLevel(int level);
	void setMaxMana(int maxMana);
	void setMaxHealthPoints(int maxHp);
	void setMaxStamina(int maxStamina);
	void setLevelPoints(int levelPts);
	void setNewGame(bool flag);

	Vector2f getCurrPosition();

	Sprite getSprite();

	int getUpperGap();
	int getLowerGap();
	int getRightGap();
	int getLeftGap();
	int getAttackRange();
	int getAttackDamage();
	int getNumberOfAttackFrames();
	int getWidth();
	int getHeight();
	int getCurrHealthPoints();
	int getMaxHealthPoints();
	int flyingShellsMakeDamage(Vector2f enemyPos, int enemyWidth, int enemyHeight);
	int getCurrShellAmount();
	int getDDTimer();
	int getCurrExp();
	int getCurrLevel();
	int getLevelPoints();
	int getArmor();
	int getVampireDraculaPerkLevel();
	int getVampireDraculaPerkBonus();
	int getTreasurePoints();
	int getChestArmorPerkLevel();

	float getGravity();
	float getJumpForce();
	float getCurrGravityAccel();
	float getCurrJumpAccel();
	float getCurrAttackFrame();
	float getCurrMana();
	float getCurrStamina();
	float getMaxMana();
	float getMaxStamina();

	string getCurrState();
	string getCurrSpriteSide();
	string getCurrShellName();

	bool getAttackState();
	bool getCharacterMadeDamage();
	bool getDamageDisabled();
	bool getHurt();
	bool isNewLevel();
	bool isNewGame();

	struct perksInfo getPerksInfo();
};