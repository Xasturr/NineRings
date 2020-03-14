#pragma once

#include "character.h"
#include "shellFireBall.h"
#include "shellIceBall.h"
#include "shellFoamyDisc.h"
#include "ddMagicDecorator.h"

#include <iostream>

using namespace std;

class Character1 : public Character
{
	Vector2f position_;
	Texture textureIdle1_;
	Texture textureIdle2_;
	Texture textureIdle3_;
	Texture textureIdle4_;
	Texture textureIdle5_;
	Texture textureIdle6_;
	Texture textureIdle7_;
	Texture textureIdle8_;
	Texture textureIdle9_;
	Texture textureIdle10_;
	Texture textureIdle11_;
	Texture textureIdle12_;

	Texture textureRun1_;
	Texture textureRun2_;
	Texture textureRun3_;
	Texture textureRun4_;
	Texture textureRun5_;
	Texture textureRun6_;
	Texture textureRun7_;
	Texture textureRun8_;

	Texture textureJump1_;
	Texture textureJump2_;
	Texture textureJump3_;
	Texture textureJump4_;
	Texture textureJump5_;
	Texture textureJump6_;
	Texture textureJump7_;

	Texture textureAttack1_;
	Texture textureAttack2_;
	Texture textureAttack3_;
	Texture textureAttack4_;

	Texture textureRunAttack1_;
	Texture textureRunAttack2_;
	Texture textureRunAttack3_;
	Texture textureRunAttack4_;
	Texture textureRunAttack5_;
	Texture textureRunAttack6_;
	Texture textureRunAttack7_;
	Texture textureRunAttack8_;

	Texture textureDeath1_;
	Texture textureDeath2_;
	Texture textureDeath3_;
	Texture textureDeath4_;
	Texture textureDeath5_;
	Texture textureDeath6_;
	Texture textureDeath7_;
	Texture textureDeath8_;
	Texture textureDeath9_;
	Texture textureDeath10_;

	Texture textureHurt1_;
	Texture textureHurt2_;
	Texture textureHurt3_;
	Texture textureHurt4_;

	Texture textureFall1_;

	Sprite sprite_;

	bool life_;
	bool jump_;
	bool attack_;
	bool runAttack_;
	bool characterMadeDamage_;
	bool damageDisabled_;
	bool hurt_;
	bool shoot_;

	float maxMoveSpeed_;
	float currentIdleFrame_;
	float currentRunFrame_;
	float currentJumpFrame_;
	float currentFallFrame_;
	float currentAttackFrame_;
	float currentRunAttackFrame_;
	float currentDeathFrame_;
	float currentHurtFrame_;
	float currentMana_;
	float currentStamina_;
	float gravity_;
	float jumpForce_;
	float currGravityAccel_;
	float currJumpAccel_;
	float currHealthPoints_;
	float currAngle_;
	float frameSpeed_;
	float currShotCoolDown_;
	float maxShotCoolDown_;
	float attackDamage_;

	int maxStamina_;
	int maxMana_;
	int numberOfIdleFrames_;
	int numberOfRunFrames_;
	int numberOfJumpFrames_;
	int numberOfFallFrames_;
	int numberOfAttackFrames_;
	int numberOfRunAttackFrames_;
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
	int currIceBallAmount_;
	int currFoamyDiscAmount_;
	int manaRegen_;
	int staminaRegen_;
	int jumpStaminaCost_;
	int attackStaminaCost_;
	int killExp_;
	int armor_;
	int name_;
	int currShellName_;

	string currSpriteSide_;
	string state_;

	vector<Shell*> flyingShells_;

	void updateSpriteSide(string spriteSide);

public:
	Character1(float posX, float posY);
	~Character1();

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
	float getMaxMana();
	float getCurrShellAngle();
	float getAttackDamage();
	float getCurrHealthPoints();

	int getCurrIdleFrame();
	int getUpperGap();
	int getLowerGap();
	int getLeftGap();
	int getRightGap();
	int getAttackRange();
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
	int getName();
	int getCurrShellName();
	int getMaxStamina();

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
	void setName(int name);
	void setMaxMoveSpeed(float moveMaxSpeed);
	void setSpriteSide(string spriteSide);
	void setLife(float flag);
	void setHurt(bool flag);
	void setCurrHealthPoints(float currHealthPoints);
	void setCurrStamina(float currStamina);
	void setCurrMana(float currMana);
	void flyingShellsUpdateAndDraw(float elapsedTime, Map* map, RenderWindow* window);
	void setCurrShotCoolDown(float currShotCoolDown);
	void setCurrShellAgle(float angle);
	void setMaxHealthPoints(int healthPoints);
	void setArmor(int armor);
	void setMaxMana(int mana);
	void setMaxStamina(int stamina);

	bool getCharacterLife();
	bool getAttackState();
	bool getJumpState();
	bool getRunAttackState();
	bool getLife();
	bool getCharacterMadeDamage();
	bool getDamageDisabled();
	bool getHurt();
	bool calculateAngryState(Vector2f playerPos);

	Shell* addFlyingShell(int shellName, bool doubleDamage, float angle);
	Shell* addFlyingShell(int shellName, float angle);

	string getCurrSpriteSide();
	string getCurrState();
};

