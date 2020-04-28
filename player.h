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
	bool halfDead_;
	bool runAttack_;
	bool shoot_;
	bool doubleDamage_;
	bool newExp_;
	bool newLvl_;
	bool newGame_;

	int getJumpStaminaCost();
	int getAttackStaminaCost();

	int currShellName_;
	int exp_;
	int lvl_;
	int levelPoints_;
	int treasurePoints_;

	struct perksInfo perksInfo_;

	void updateLevel(RenderWindow* window);
	void updateJugglerPerkBonus();
	void updateDrippingBladePerkBonus();
	void updateHalfDeadPerkBonus();
	void updateVampireDraculaPerkBonus();
	void updateTripleScratchesPerkBonus();
	void updateChestArmorPerkBonus();
	void updateFairyWandPerkBonus();

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
	void activateHalfDeadPerk();

	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	void stopAttack();
	void stopShoot();
	void stopHalfDeadPerk();

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
	void setFoamyDiscPerk();
	void setIceBallPerk();
	void setJugglerPerk();
	void setDrippingBladePerk();
	void setHalfDeadPerk();
	void setVampireDraculaPerk();
	void setTripleScratchesPerk();
	void setCurrLevel(int level);
	void setMaxMana(int maxMana);
	void setMaxHealthPoints(int maxHp);
	void setMaxStamina(int maxStamina);
	void setLevelPoints(int levelPts);
	void setNewGame(bool flag);
	void setCurrShellName(int shellName);
	void setIceBallPerkLevel(int level);
	void setFoamyDiscPerkLevel(int level);
	void setJugglerPerkLevel(int level);
	void setDrippingBladePerkLevel(int level);
	void setHalfDeadPerksLevel(int level);
	void setVampireDraculaPerkLevel(int level);
	void setTripleScratchesPerkLevel(int level);
	void setChestArmorPerkLevel(int level);
	void setFairyWandPerkLevel(int level);

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
	int getMaxHealthPoints();
	int flyingShellsMakeDamage(Vector2f enemyPos, int enemyWidth, int enemyHeight);
	int getCurrShellAmount();
	int getDDTimer();
	int getCurrExp();
	int getCurrLevel();
	int getLevelPoints();
	int getArmor();
	int getCurrVampireDraculaPerkLevel();
	int getVampireDraculaPerkBonus();
	int getTreasurePoints();
	int getCurrChestArmorPerkLevel();
	int getCurrIceBallPerkLevel();
	int getCurrFoamyDiscPerkLevel();
	int getCurrShellName();
	int getCurrJugglerPerkLevel();
	int getCurrJugglerPerkBonus();
	int getCurrDrippingBladePerkLevel();
	int getCurrHalfDeadPerkLevel();
	int getCurrTripleScratchesPerkLevel();
	int getTripleScratchesPerkBonus();
	int getCurrFairyWandPerkLevel();
	int update(float elapsedTime, RenderWindow* window);

	float getGravity();
	float getJumpForce();
	float getCurrGravityAccel();
	float getCurrJumpAccel();
	float getCurrAttackFrame();
	float getCurrMana();
	float getCurrStamina();
	float getMaxMana();
	float getMaxStamina();
	float getCurrHealthPoints();

	string getCurrState();
	string getCurrSpriteSide();

	bool getAttackState();
	bool getCharacterMadeDamage();
	bool getDamageDisabled();
	bool getHurt();
	bool isNewLevel();
	bool isNewGame();

	struct perksInfo getPerksInfo();
};