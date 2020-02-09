#include "character1.h"

Character1::Character1(float posX, float posY)
{
	position_.x = posX;
	position_.y = posY;

	textureIdle1_.loadFromFile("./textures/tiles/characters/knight/Idle/idle1.png");
	textureIdle2_.loadFromFile("./textures/tiles/characters/knight/Idle/idle2.png");
	textureIdle3_.loadFromFile("./textures/tiles/characters/knight/Idle/idle3.png");
	textureIdle4_.loadFromFile("./textures/tiles/characters/knight/Idle/idle4.png");
	textureIdle5_.loadFromFile("./textures/tiles/characters/knight/Idle/idle5.png");
	textureIdle6_.loadFromFile("./textures/tiles/characters/knight/Idle/idle6.png");
	textureIdle7_.loadFromFile("./textures/tiles/characters/knight/Idle/idle7.png");
	textureIdle8_.loadFromFile("./textures/tiles/characters/knight/Idle/idle8.png");
	textureIdle9_.loadFromFile("./textures/tiles/characters/knight/Idle/idle9.png");
	textureIdle10_.loadFromFile("./textures/tiles/characters/knight/Idle/idle10.png");
	textureIdle11_.loadFromFile("./textures/tiles/characters/knight/Idle/idle11.png");
	textureIdle12_.loadFromFile("./textures/tiles/characters/knight/Idle/idle12.png");

	textureRun1_.loadFromFile("./textures/tiles/characters/knight/Run/run1.png");
	textureRun2_.loadFromFile("./textures/tiles/characters/knight/Run/run2.png");
	textureRun3_.loadFromFile("./textures/tiles/characters/knight/Run/run3.png");
	textureRun4_.loadFromFile("./textures/tiles/characters/knight/Run/run4.png");
	textureRun5_.loadFromFile("./textures/tiles/characters/knight/Run/run5.png");
	textureRun6_.loadFromFile("./textures/tiles/characters/knight/Run/run6.png");
	textureRun7_.loadFromFile("./textures/tiles/characters/knight/Run/run7.png");
	textureRun8_.loadFromFile("./textures/tiles/characters/knight/Run/run8.png");

	textureJump1_.loadFromFile("./textures/tiles/characters/knight/Jump/jump1.png");
	textureJump2_.loadFromFile("./textures/tiles/characters/knight/Jump/jump2.png");
	textureJump3_.loadFromFile("./textures/tiles/characters/knight/Jump/jump3.png");
	textureJump4_.loadFromFile("./textures/tiles/characters/knight/Jump/jump4.png");
	textureJump5_.loadFromFile("./textures/tiles/characters/knight/Jump/jump5.png");
	textureJump6_.loadFromFile("./textures/tiles/characters/knight/Jump/jump6.png");
	textureJump7_.loadFromFile("./textures/tiles/characters/knight/Jump/jump7.png");

	textureFall1_.loadFromFile("./textures/tiles/characters/knight/Jump/jump6.png");

	textureAttack1_.loadFromFile("./textures/tiles/characters/knight/Attack/attack1.png");
	textureAttack2_.loadFromFile("./textures/tiles/characters/knight/Attack/attack2.png");
	textureAttack3_.loadFromFile("./textures/tiles/characters/knight/Attack/attack3.png");
	textureAttack4_.loadFromFile("./textures/tiles/characters/knight/Attack/attack4.png");

	textureRunAttack1_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack1.png");
	textureRunAttack2_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack2.png");
	textureRunAttack3_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack3.png");
	textureRunAttack4_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack4.png");
	textureRunAttack5_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack5.png");
	textureRunAttack6_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack6.png");
	textureRunAttack7_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack7.png");
	textureRunAttack8_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack8.png");

	textureDeath1_.loadFromFile("./textures/tiles/characters/knight/Death/death1.png");
	textureDeath2_.loadFromFile("./textures/tiles/characters/knight/Death/death2.png");
	textureDeath3_.loadFromFile("./textures/tiles/characters/knight/Death/death3.png");
	textureDeath4_.loadFromFile("./textures/tiles/characters/knight/Death/death4.png");
	textureDeath5_.loadFromFile("./textures/tiles/characters/knight/Death/death5.png");
	textureDeath6_.loadFromFile("./textures/tiles/characters/knight/Death/death6.png");
	textureDeath7_.loadFromFile("./textures/tiles/characters/knight/Death/death7.png");
	textureDeath8_.loadFromFile("./textures/tiles/characters/knight/Death/death8.png");
	textureDeath9_.loadFromFile("./textures/tiles/characters/knight/Death/death9.png");
	textureDeath10_.loadFromFile("./textures/tiles/characters/knight/Death/death10.png");

	textureHurt1_.loadFromFile("./textures/tiles/characters/knight/Hurt/hurt1.png");
	textureHurt2_.loadFromFile("./textures/tiles/characters/knight/Hurt/hurt2.png");
	textureHurt3_.loadFromFile("./textures/tiles/characters/knight/Hurt/hurt3.png");
	textureHurt4_.loadFromFile("./textures/tiles/characters/knight/Hurt/hurt4.png");

	sprite_.setTexture(textureIdle1_);

	life_ = true;
	jump_ = false;
	attack_ = false;
	runAttack_ = false;
	characterMadeDamage_ = false;
	damageDisabled_ = false;
	hurt_ = false;
	shoot_ = false;

	maxMoveSpeed_ = 450;
	currentIdleFrame_ = 1;
	currentRunFrame_ = 1;
	currentJumpFrame_ = 1;
	currentFallFrame_ = 1;
	currentAttackFrame_ = 1;
	currentRunAttackFrame_ = 1;
	currentDeathFrame_ = 1;
	currentHurtFrame_ = 1;
	numberOfIdleFrames_ = 12;
	numberOfRunFrames_ = 8;
	numberOfJumpFrames_ = 6;
	numberOfFallFrames_ = 1;
	numberOfAttackFrames_ = 4;
	numberOfRunAttackFrames_ = 8;
	numberOfDeathFrames_ = 10;
	numberOfHurtFrames_ = 4;
	frameSpeed_ = 10;
	gravity_ = 1700.f;
	jumpForce_ = 900.f;
	currJumpAccel_ = 0.f;
	leftGap_ = 20; //from center to left edge
	rightGap_ = 20;//from center to right edge
	//lowerGap_ = 23;
	//upperGap_ = 52;
	currGravityAccel_ = jumpForce_;
	maxHealthPoints_ = currHealthPoints_ =  100;
	maxStamina_ = currStamina_ = 100;
	maxMana_ = currMana_ = 100;
	attackDamage_ = 10;
	attackRange_ = 60;
	runAttackRange_ = 58;
	height_ = 70; //height of character
	width_ = 40; //width of caracter
	overview_ = 330;
	currFireBallAmount_ = 100;
	currAngle_ = 90;
	maxShotCoolDown_ = 2;
	currShotCoolDown_ = 0;

	sprite_.setOrigin(textureRun1_.getSize().x / 2, 110);

	currSpriteSide_ = "right";
	state_ = "falling";
	name_ = "Character1";
	currShellName_ = "FireBall";

	//for (int i = 0; i < currFireBallAmount_; i++)
	//{
	//	shells_[i] = new ShellFireBall();
	//}
}
Character1::~Character1() {}

Sprite Character1::getSprite()
{
	return sprite_;
}

float Character1::getMaxMoveSpeed()
{
	return maxMoveSpeed_;
}

float Character1::getGravity()
{
	return gravity_;
}

float Character1::getCurrGravityAccel()
{
	return currGravityAccel_;
}

float Character1::getFrameSpeed()
{
	return frameSpeed_;
}

float Character1::getCurrJumpAccel()
{
	return currJumpAccel_;
}

float Character1::getJumpForce()
{
	return jumpForce_;
}

float Character1::getCurrAttackFrame()
{
	return currentAttackFrame_;
}

float Character1::getCurrShotCoolDown()
{
	return currShotCoolDown_;
}

float Character1::getMaxShotCoolDown()
{
	return maxShotCoolDown_;
}

int Character1::getCurrIdleFrame()
{
	return currentIdleFrame_;
}

int Character1::getUpperGap()
{
	return upperGap_;
}

int Character1::getLowerGap()
{
	return lowerGap_;
}

int Character1::getLeftGap()
{
	return leftGap_;
}

int Character1::getRightGap()
{
	return rightGap_;
}

int Character1::getAttackRange()
{
	if (attack_)
	{
		return attackRange_;
	}
	else
	{
		return runAttackRange_;
	}
}

int Character1::getCurrHealthPoints()
{
	return int(currHealthPoints_);
}

int Character1::getCurrMana()
{
	return int(currMana_);
}

int Character1::getCurrStamina()
{
	return int(currStamina_);
}

int Character1::getMaxHealthPoints()
{
	return maxHealthPoints_;
}

int Character1::getMaxMana()
{
	return maxMana_;
}

int Character1::getMaxStamina()
{
	return maxStamina_;
}

int Character1::getAttackDamage()
{
	return attackDamage_;
}

int Character1::getNumberOfAttackFrames()
{
	return numberOfAttackFrames_;
}

int Character1::getHeight()
{
	return height_;
}

int Character1::getWidth()
{
	return width_;
}

int Character1::getOverview()
{
	return overview_;
}

int Character1::getCurrFlyingShellAmount()
{
	return flyingShells_.size();
}

int Character1::getCurrShellAmount()
{
	if (currShellName_ == "FireBall")
	{
		return currFireBallAmount_;
	}

	return 0;
}

int Character1::flyingShellsMakeDamage(Vector2f enemyPos, int enemyWidth, int enemyHeight)
{
	for (int i = 0; i < flyingShells_.size(); i++)
	{
		if (!flyingShells_[i]->getExplosed())
		{
			if (enemyPos.x - enemyWidth / 2 <= flyingShells_[i]->getPosition().x
				&& enemyPos.x + enemyWidth / 2 >= flyingShells_[i]->getPosition().x
				&& enemyPos.y - enemyHeight <= flyingShells_[i]->getPosition().y
				&& enemyPos.y >= flyingShells_[i]->getPosition().y)
			{
				cout << "DAMAGED ENEMY" << endl;
				//flyingShells_[i]->setLife(false);
				flyingShells_[i]->setExplosed(true);
				//hurt_ = true;
				return flyingShells_[i]->getAlphaStrike();
			}
		}
	}

	return 0;
}

Vector2f Character1::getCurrPosition()
{
	return position_;
}

bool Character1::getCharacterLife()
{
	return life_;
}

bool Character1::getAttackState()
{
	return attack_ || runAttack_;
}

void Character1::setPosition(float x, float y)
{
	position_.x = x;
	position_.y = y;
	sprite_.setPosition(x, y);
}

void Character1::setCurrIdleFrame(float increase)
{
	currentRunFrame_ = 1;
	currentJumpFrame_ = 1;
	currentFallFrame_ = 1;
	currentRunAttackFrame_ = 1;
	
	currentIdleFrame_ += increase;

	runAttack_ = false;

	if (currentIdleFrame_ >= numberOfIdleFrames_)
		currentIdleFrame_ = 1;
}

void Character1::setCurrRunFrame(float increase)
{
	currentIdleFrame_ = 1;
	currentJumpFrame_ = 1;
	currentFallFrame_ = 1;
	currentAttackFrame_ = 1;
	currentRunFrame_ += increase;

	attack_ = false;

	if (currentRunFrame_ >= numberOfRunFrames_)
		currentRunFrame_ = 1;
}

void Character1::setCurrJumpFrame(float increase)
{
	currentIdleFrame_ = 1;
	currentRunFrame_ = 1;
	currentFallFrame_ = 1;
	currentRunAttackFrame_ = 1;

	currentJumpFrame_ += (increase / 1.4);

	runAttack_ = false;

	if (currentJumpFrame_ >= numberOfJumpFrames_)
	{
		state_ = "falling";
		currGravityAccel_ = 0.f;
	}
}

void Character1::setCurrFallFrame(float increase)
{
	currentIdleFrame_ = 1;
	currentRunFrame_ = 1;
	currentJumpFrame_ = 1;
	currentRunAttackFrame_ = 1;

	currentFallFrame_ += increase;

	runAttack_ = false;

	if (currentFallFrame_ >= numberOfFallFrames_)
		currentFallFrame_ = numberOfFallFrames_;
}

void Character1::setCurrAttackFrame(float increase)
{
	currentRunAttackFrame_ = 1;

	currentAttackFrame_ += increase / 1.2;

	runAttack_ = false;

	if (currentAttackFrame_ < 3)
	{
		damageDisabled_ = true;
	}
	else
	{
		damageDisabled_ = false;
	}

	if (currentAttackFrame_ >= numberOfAttackFrames_)
	{
		currentAttackFrame_ = 1;
		attack_ = false;
		characterMadeDamage_ = false;
	}
}

void Character1::setCurrRunAttackFrame(float increase)
{
	currentRunAttackFrame_ += increase * 1.5;

	if (currentRunAttackFrame_ < 5)
	{
		damageDisabled_ = true;
	}
	else
	{
		damageDisabled_ = false;
	}

	if (currentRunAttackFrame_ >= numberOfRunAttackFrames_)
	{
		currentRunAttackFrame_ = 1;
		runAttack_ = false;
		characterMadeDamage_ = false;
	}
}

void Character1::setCurrDeathFrame(float increase)
{
	currentDeathFrame_ += increase / 1.4;

	if (currentDeathFrame_ > numberOfDeathFrames_)
	{
		life_ = false;
	}
}

void Character1::setCurrHurtFrame(float increase)
{
	currentIdleFrame_ = 1;
	currentRunFrame_ = 1;
	currentJumpFrame_ = 1;
	currentRunAttackFrame_ = 1;

	currentHurtFrame_ += increase / 2;
	//damageDisabled_ = true;
	//hurt_ = true;

	if (currentHurtFrame_ > numberOfHurtFrames_)
	{
		hurt_ = false;
		currentHurtFrame_ = 1;
		//damageDisabled_ = false;
	}
}

void Character1::updateSpriteSide(string spriteSide)
{
	if (currSpriteSide_ != spriteSide)
	{
		if (spriteSide == "left")
		{
			sprite_.setScale(-1.f, 1.f);
			currAngle_ = -90;
		}
		else
		{
			sprite_.setScale(1.f, 1.f);
			currAngle_ = 90;
		}

		currSpriteSide_ = spriteSide;
	}
}

void Character1::spriteUpdateIdle()
{
	if (int(currentIdleFrame_) == 1)
		sprite_.setTexture(textureIdle1_);
	else if (int(currentIdleFrame_) == 2)
		sprite_.setTexture(textureIdle2_);
	else if (int(currentIdleFrame_) == 3)
		sprite_.setTexture(textureIdle3_);
	else if (int(currentIdleFrame_) == 4)
		sprite_.setTexture(textureIdle4_);
	else if (int(currentIdleFrame_) == 5)
		sprite_.setTexture(textureIdle5_);
	else if (int(currentIdleFrame_) == 6)
		sprite_.setTexture(textureIdle6_);
	else if (int(currentIdleFrame_) == 7)
		sprite_.setTexture(textureIdle7_);
	else if (int(currentIdleFrame_) == 8)
		sprite_.setTexture(textureIdle8_);
	else if (int(currentIdleFrame_) == 9)
		sprite_.setTexture(textureIdle9_);
	else if (int(currentIdleFrame_) == 10)
		sprite_.setTexture(textureIdle10_);
	else if (int(currentIdleFrame_) == 11)
		sprite_.setTexture(textureIdle11_);
	else 
		sprite_.setTexture(textureIdle12_);
}

void Character1::spriteUpdateRun(string spriteSide)
{
	if (int(currentRunFrame_) == 1)
		sprite_.setTexture(textureRun1_);
	else if (int(currentRunFrame_) == 2)
		sprite_.setTexture(textureRun2_);
	else if (int(currentRunFrame_) == 3)
		sprite_.setTexture(textureRun3_);
	else if (int(currentRunFrame_) == 4)
		sprite_.setTexture(textureRun4_);
	else if (int(currentRunFrame_) == 5)
		sprite_.setTexture(textureRun5_);
	else if (int(currentRunFrame_) == 6)
		sprite_.setTexture(textureRun6_);
	else if (int(currentRunFrame_) == 7)
		sprite_.setTexture(textureRun7_);
	else
		sprite_.setTexture(textureRun8_);

	updateSpriteSide(spriteSide);
}

void Character1::spriteUpdateJump(string spriteSide)
{
	if (int(currentJumpFrame_) == 1)
		sprite_.setTexture(textureJump1_);
	else if (int(currentJumpFrame_) == 2)
		sprite_.setTexture(textureJump2_);
	else if (int(currentJumpFrame_) == 3)
		sprite_.setTexture(textureJump3_);
	else if (int(currentJumpFrame_) == 4)
		sprite_.setTexture(textureJump4_);
	else if (int(currentJumpFrame_) == 5)
		sprite_.setTexture(textureJump5_);
	else if (int(currentJumpFrame_) == 6)
		sprite_.setTexture(textureJump6_);
	else 
		sprite_.setTexture(textureJump7_);

	updateSpriteSide(spriteSide);
}

void Character1::spriteUpdateFall(string spriteSide)
{
	if (int(currentJumpFrame_) == 1)
	{
		sprite_.setTexture(textureFall1_);
	}

	updateSpriteSide(spriteSide);
}

void Character1::spriteUpdateAttack(string spriteSide)
{
	if (int(currentAttackFrame_) == 1)
		sprite_.setTexture(textureAttack1_);
	else if (int(currentAttackFrame_) == 2)
		sprite_.setTexture(textureAttack2_);
	else if (int(currentAttackFrame_) == 3)
		sprite_.setTexture(textureAttack3_);
	else
		sprite_.setTexture(textureAttack4_);

	updateSpriteSide(spriteSide);
}

void Character1::spriteUpdateRunAttack(string spriteSide)
{
	if (int(currentRunAttackFrame_) == 1)
		sprite_.setTexture(textureRunAttack1_);
	else if (int(currentRunAttackFrame_) == 2)
		sprite_.setTexture(textureRunAttack2_);
	else if (int(currentRunAttackFrame_) == 3)
		sprite_.setTexture(textureRunAttack3_);
	else if (int(currentRunAttackFrame_) == 4)
		sprite_.setTexture(textureRunAttack4_);
	else if (int(currentRunAttackFrame_) == 5)
		sprite_.setTexture(textureRunAttack5_);
	else if (int(currentRunAttackFrame_) == 6)
		sprite_.setTexture(textureRunAttack6_);
	else if (int(currentRunAttackFrame_) == 7)
		sprite_.setTexture(textureRunAttack7_);
	else
		sprite_.setTexture(textureRunAttack8_);

	updateSpriteSide(spriteSide);
}

void Character1::spriteUpdateDeath(string spriteSide)
{
	if (int(currentDeathFrame_) == 1)
		sprite_.setTexture(textureDeath1_);
	else if (int(currentDeathFrame_) == 2)
		sprite_.setTexture(textureDeath2_);
	else if (int(currentDeathFrame_) == 3)
		sprite_.setTexture(textureDeath3_);
	else if (int(currentDeathFrame_) == 4)
		sprite_.setTexture(textureDeath4_);
	else if (int(currentDeathFrame_) == 5)
		sprite_.setTexture(textureDeath5_);
	else if (int(currentDeathFrame_) == 6)
		sprite_.setTexture(textureDeath6_);
	else if (int(currentDeathFrame_) == 7)
		sprite_.setTexture(textureDeath7_);
	else if (int(currentDeathFrame_) == 8)
		sprite_.setTexture(textureDeath8_);
	else if (int(currentDeathFrame_) == 9)
		sprite_.setTexture(textureDeath9_);
	else
		sprite_.setTexture(textureDeath10_);

	updateSpriteSide(spriteSide);
}

void Character1::spriteUpdateHurt(string spriteSide)
{
	if (int(currentHurtFrame_) == 1)
		sprite_.setTexture(textureHurt1_);
	else if (int(currentHurtFrame_) == 2)
		sprite_.setTexture(textureHurt2_);
	else if (int(currentHurtFrame_) == 3)
		sprite_.setTexture(textureHurt3_);
	else
		sprite_.setTexture(textureHurt4_);

	updateSpriteSide(spriteSide);
}

void Character1::setCurrGravityAccel(float value)
{
	currGravityAccel_ = value;
}

void Character1::setCurrJumpAccel(float value)
{
	currJumpAccel_ = value;
}

void Character1::setJumpState(bool flag)
{
	jump_ = flag;
}

void Character1::setAttackState(bool flag)
{
	attack_ = flag;
}

void Character1::setRunAttackState(bool flag)
{
	runAttack_ = flag;
}

void Character1::setCurrHealthPoints(int currHealthPoints)
{
	currHealthPoints_ = currHealthPoints;
}

void Character1::setCurrStamina(int currStamina)
{
	currStamina_ = currStamina;
}

void Character1::setCurrMana(int currMana)
{
	currMana_ = currMana;
}

void Character1::addFlyingShell(string shellName)
{
	if (shellName == "FireBall" && currFireBallAmount_ > 0)
	{
		currFireBallAmount_ -= 1;
		flyingShells_.push_back(new ShellFireBall(position_.x + width_ / 2, position_.y - height_ / 2, currAngle_, currSpriteSide_));
	}
}

void Character1::flyingShellsUpdateAndDraw(float elapsedTime, Map* map, RenderWindow* window)
{
	int eraseShell = -1;

	for (int i = 0; i < flyingShells_.size(); i++)
	{
		if (flyingShells_[i]->getLife())
		{
			flyingShells_[i]->updateAndDraw(elapsedTime, map, window);
		}
		else
		{
			eraseShell = i;
		}
	}

	if (eraseShell != -1)
	{
		flyingShells_.erase(flyingShells_.begin() + eraseShell);
	}
}

void Character1::setCurrShotCoolDown(float currShotCoolDown)
{
	currShotCoolDown_ = currShotCoolDown;
}

//void Character1::eraseShell(string shellName)
//{
//	if (shellName == "FireBall" && currFireBallAmount_ > 0)
//	{
//		//shells_.erase(shells_.begin());
//		currFireBallAmount_ -= 1;
//	}
//}

void Character1::setEnemyDamaged(bool flag)
{
	characterMadeDamage_ = flag;
}

void Character1::setState(string state)
{
	state_ = state;
}

void Character1::setName(string name)
{
	name_ = name;
}

void Character1::setMaxMoveSpeed(float maxMoveSpeed)
{
	maxMoveSpeed_ = maxMoveSpeed;
}

void Character1::setSpriteSide(string spriteSide)
{
	currSpriteSide_ = spriteSide;
}

void Character1::setLife(float flag)
{
	life_ = flag;
}

void Character1::setHurt(bool flag)
{
	hurt_ = flag;
}

bool Character1::getJumpState()
{
	return jump_;
}

bool Character1::getRunAttackState()
{
	return runAttack_;
}

bool Character1::getLife()
{
	return life_;
}

bool Character1::getCharacterMadeDamage()
{
	return characterMadeDamage_;
}

bool Character1::getDamageDisabled()
{
	return damageDisabled_;
}

bool Character1::getHurt()
{
	return hurt_;
}

string Character1::getCurrSpriteSide()
{
	return currSpriteSide_;
}

string Character1::getCurrState()
{
	return state_;
}

string Character1::getName()
{
	return name_;
}

string Character1::getCurrShellName()
{
	return currShellName_;
}