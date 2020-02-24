#pragma once

#include "character.h"
#include "shellFireBall.h"

class CharacterBat : public Character
{
	Vector2f position_;

	Texture textureFly_;

	Texture textureDeath_;

	Texture textureHurt_;

	Sprite sprite_;

	bool life_;
	bool attack_;
	bool runAttack_;
	bool characterMadeDamage_;
	bool damageDisabled_;
	bool hurt_;
	bool shoot_;

	float maxMoveSpeed_;
	float maxStamina_;
	float maxMana_;
	float currentFlyFrame_;
	float currentDeathFrame_;
	float currentHurtFrame_;
	float currentMana_;
	float currentStamina_;
	float gravity_;
	float currGravityAccel_;
	float currJumpAccel_;
	float currHealthPoints_;
	float currAngle_;
	float frameSpeed_;
	float currShotCoolDown_;
	float maxShotCoolDown_;
	float attackDamage_;

	int numberOfFlyFrames_;
	int numberOfDeathFrames_;
	int numberOfHurtFrames_;
	int lowerGap_;
	int upperGap_;
	int rightGap_;
	int leftGap_;
	int maxHealthPoints_;
	int attackRange_;
	int runAttackRange_;
	int height_;
	int width_;
	int overview_;
	int currFireBallAmount_;
	int manaRegen_;
	int staminaRegen_;
	int jumpStaminaCost_;
	int attackStaminaCost_;
	int scaleFactor_;
	int killExp_;
	int armor_;

	string currSpriteSide_;
	string state_;
	string name_;
	string currShellName_;

	vector<Shell*> flyingShells_;

	void updateSpriteSide(string spriteSide);

public:
	CharacterBat(float posX, float posY);
	~CharacterBat();

	Sprite getSprite();

	float getMaxMoveSpeed();
	float getGravity();
	float getCurrGravityAccel();
	float getFrameSpeed();
	float getCurrJumpAccel();
	float getJumpForce();
	float getCurrAttackFrame();
	float getCurrShotCoolDown();
	float getMaxShotCoolDown();
	float getCurrStamina();
	float getCurrMana();
	float getMaxStamina();
	float getMaxMana();
	float getCurrShellAngle();
	float getAttackDamage();

	int getCurrIdleFrame();
	int getUpperGap();
	int getLowerGap();
	int getLeftGap();
	int getRightGap();
	int getAttackRange();
	int getCurrHealthPoints();
	int getNumberOfAttackFrames();
	int getHeight();
	int getWidth();
	int getOverview();
	int getMaxHealthPoints();
	int getCurrFlyingShellAmount();
	int getCurrShellAmount();
	int flyingShellsMakeDamage(Vector2f charPos, int charWidth, int charHeight);
	int getManaRegen();
	int getStaminaRegen();
	int getJumpStaminaCost();
	int getAttackStaminaCost();
	int getKillExp();
	int getArmor();

	Vector2f getCurrPosition();

	void setPosition(float x, float y);
	void setCurrIdleFrame(float increase);
	void setCurrFlyFrame(float increase);
	void setCurrRunFrame(float increase);
	void setCurrJumpFrame(float increase);
	void setCurrFallFrame(float increase);
	void setCurrAttackFrame(float increase);
	void setCurrRunAttackFrame(float increase);
	void setCurrDeathFrame(float increase);
	void setCurrHurtFrame(float increase);
	void spriteUpdateIdle(string spriteSide);
	void spriteUpdateFly(string spriteSide);
	void spriteUpdateRun(string spriteSide);
	void spriteUpdateJump(string spriteSide);
	void spriteUpdateFall(string spriteSide);
	void spriteUpdateAttack(string spriteSide);
	void spriteUpdateRunAttack(string spriteSide);
	void spriteUpdateDeath(string spriteSide);
	void spriteUpdateHurt(string spriteSide);
	void setCurrGravityAccel(float value);
	void setCurrJumpAccel(float value);
	void setJumpState(bool flag);
	void setState(string state);
	void setAttackState(bool flag);
	void setRunAttackState(bool flag);
	void setEnemyDamaged(bool flag);
	void setName(string name);
	void setMaxMoveSpeed(float moveMaxSpeed);
	void setSpriteSide(string spriteSide);
	void setLife(float flag);
	void setHurt(bool flag);
	void setCurrHealthPoints(int currHealthPoints);
	void setCurrStamina(float currStamina);
	void setCurrMana(float currMana);
	void addFlyingShell(string shellName, float angle);
	void addFlyingShell(string shellName, bool doubleDamage, float angle);
	void flyingShellsUpdateAndDraw(float elapsedTime, Map* map, RenderWindow* window);
	void setCurrShotCoolDown(float currShotCoolDown);
	void setCurrShellAgle(float angle);
	void setMaxHealthPoints(int healthPoints);
	void setArmor(int armor);
	void setMaxMana(int mana);

	bool getCharacterLife();
	bool getAttackState();
	bool getJumpState();
	bool getRunAttackState();
	bool getLife();
	bool getCharacterMadeDamage();
	bool getDamageDisabled();
	bool getHurt();
	bool calculateAngryState(Vector2f playerPos);

	string getCurrSpriteSide();
	string getCurrState();
	string getName();
	string getCurrShellName();
};

