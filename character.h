#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include "map.h"

using namespace sf;
using namespace std;

class Character
{
public:
	virtual Sprite getSprite() = 0;

	virtual float getMaxMoveSpeed() = 0;
	virtual float getGravity() = 0;
	virtual float getCurrGravityAccel() = 0;
	virtual float getFrameSpeed() = 0;
	virtual float getCurrJumpAccel() = 0;
	virtual float getJumpForce() = 0;
	virtual float getCurrAttackFrame() = 0;
	virtual float getCurrShotCoolDown() = 0;
	virtual float getMaxShotCoolDown() = 0;
	//virtual float getCurrentSpeed() = 0;

	//virtual void spriteFrameUpdate(float currentFrame) = 0;
	virtual void setPosition(float posX, float posY) = 0;
	virtual void setCurrIdleFrame(float increase) = 0;
	virtual void setCurrRunFrame(float increase) = 0;
	virtual void setCurrJumpFrame(float increase) = 0;
	virtual void setCurrFallFrame(float increase) = 0;
	virtual void setCurrAttackFrame(float increase) = 0;
	virtual void setCurrRunAttackFrame(float increase) = 0;
	virtual void setCurrDeathFrame(float increase) = 0;
	virtual void setCurrHurtFrame(float increase) = 0;
	virtual void spriteUpdateIdle() = 0;
	virtual void spriteUpdateRun(string spriteSide) = 0;
	virtual void spriteUpdateJump(string spriteSide) = 0;
	virtual void spriteUpdateFall(string spriteSide) = 0;
	virtual void spriteUpdateAttack(string spriteSide) = 0;
	virtual void spriteUpdateRunAttack(string spriteSide) = 0;
	virtual void spriteUpdateDeath(string spriteSide) = 0;
	virtual void spriteUpdateHurt(string spriteSide) = 0;
	virtual void setCurrGravityAccel(float value) = 0;
	virtual void setCurrJumpAccel(float value) = 0;
	virtual void setJumpState(bool flag) = 0;
	virtual void setState(string state) = 0;
	virtual void setAttackState(bool flag) = 0;
	virtual void setRunAttackState(bool flag) = 0;
	virtual void setEnemyDamaged(bool flag) = 0;
	virtual void setName(string name) = 0;
	virtual void setMaxMoveSpeed(float maxMoveSpeed) = 0;
	virtual void setSpriteSide(string spriteSide) = 0;
	virtual void setLife(float flag) = 0;
	virtual void setHurt(bool flag) = 0;
	virtual void setCurrHealthPoints(int currHealthPoints) = 0;
	virtual void setCurrStamina(int currStamina) = 0;
	virtual void setCurrMana(int currMana) = 0;
	virtual void addFlyingShell(string shellName) = 0;
	virtual void flyingShellsUpdateAndDraw(float elapsedTime, Map* map, RenderWindow* window) = 0;
	virtual void setCurrShotCoolDown(float currCoolDown) = 0;

	virtual int getUpperGap() = 0;
	virtual int getLowerGap() = 0;
	virtual int getLeftGap() = 0;
	virtual int getRightGap() = 0;
	virtual int getAttackRange() = 0;
	virtual int getCurrHealthPoints() = 0;
	virtual int getCurrMana() = 0;
	virtual int getCurrStamina() = 0;
	virtual int getAttackDamage() = 0;
	virtual int getNumberOfAttackFrames() = 0;
	virtual int getHeight() = 0;
	virtual int getWidth() = 0;
	virtual int getOverview() = 0;
	virtual int getMaxHealthPoints() = 0;
	virtual int getMaxStamina() = 0;
	virtual int getMaxMana() = 0;
	virtual int getCurrFlyingShellAmount() = 0;
	virtual int getCurrShellAmount() = 0;
	virtual int flyingShellsMakeDamage(Vector2f enemyPos, int enemyWidth, int enemyHeight) = 0;

	virtual bool getJumpState() = 0;
	virtual bool getAttackState() = 0;
	virtual bool getRunAttackState() = 0;
	virtual bool getLife() = 0;
	virtual bool getCharacterMadeDamage() = 0;
	virtual bool getDamageDisabled() = 0;
	virtual bool getHurt() = 0;

	virtual string getCurrSpriteSide() = 0;
	virtual string getCurrState() = 0;
	virtual string getName() = 0;
	virtual string getCurrShellName() = 0;

	//virtual int getCurrFrame() = 0;

	virtual Vector2f getCurrPosition() = 0;
};